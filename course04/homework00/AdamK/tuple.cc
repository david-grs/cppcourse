/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <utility>

template <size_t, class T>
struct tuple_element
{
    tuple_element() = default;
    tuple_element(const tuple_element&) = default;
    tuple_element& operator=(const tuple_element& rhs) = default;
    tuple_element(tuple_element&&) = default;
    tuple_element& operator=(tuple_element&&) = default;
    
    explicit tuple_element(const T& value) : mValue(value) {};
    explicit tuple_element(T&& value) : mValue(std::move(value)) {};
    
    T mValue;
};

template <class Sequence, class... Types>
struct tuple_impl;

template <class>
struct is_tuple_impl : std::false_type {};

template <size_t... Indices, class... Types>
struct is_tuple_impl<tuple_impl<std::index_sequence<Indices...>, Types...>> : std::true_type {};

template <template <class> class>
constexpr bool is_any_of()
{
    return false;
}

template <template <class> class Op, class Head, class... Tail>
constexpr bool is_any_of()
{
    return Op<Head>::value || is_any_of<Op, Tail...>();
}

template <size_t... Indices, class... Types>
struct tuple_impl<std::index_sequence<Indices...>, Types...>
    : tuple_element<Indices, Types>...
{
    tuple_impl() = default;
    tuple_impl(const tuple_impl&) = default;
    tuple_impl& operator=(const tuple_impl& rhs) = default;
    tuple_impl(tuple_impl&&) = default;
    tuple_impl& operator=(tuple_impl&&) = default;
    
    template <class... OtherTypes,
                class = class std::enable_if<
                    !is_any_of<is_tuple_impl, class std::decay<OtherTypes>::type...>()
                >::type
            >
    explicit tuple_impl(OtherTypes&&... elements)
        : tuple_element<Indices, Types>(std::forward<OtherTypes>(elements))...
    {
    }
};

template <size_t I, class Head, class... Tail>
struct type_at_index
{
    using type = typename type_at_index<I-1, Tail...>::type;
};

template <class Head, class... Tail>
struct type_at_index<0, Head, Tail...>
{
    using type = Head;    
};

template <size_t I, class... Types>
using type_at_index_t = typename type_at_index<I, Types...>::type;

template <class... Types>
class tuple
    : tuple_impl<std::make_index_sequence<sizeof...(Types)>, Types...>
{
public:
    tuple() = default;
    tuple(const tuple&) = default;
    tuple& operator=(const tuple& rhs) = default;
    tuple(tuple&&) = default;
    tuple& operator=(tuple&&) = default;
    
    using base_tuple = tuple_impl<std::make_index_sequence<sizeof...(Types)>, Types...>;
    
    template <class... OtherTypes>
    explicit tuple(OtherTypes&&... elements)
        : base_tuple(std::forward<OtherTypes>(elements)...)
    {
    }
    
    template <size_t I>
    static const type_at_index_t<I, Types...>& get(const tuple<Types...>& tup)
    {
        const tuple_element<I, type_at_index_t<I, Types...>>& base = tup;
        return base.mValue;
    }
    
    template <size_t I>
    static type_at_index_t<I, Types...>& get(tuple<Types...>& tup)
    {
        tuple_element<I, type_at_index_t<I, Types...>>& base = tup;
        return base.mValue;
    }
    
    template <size_t I>
    static std::remove_reference<type_at_index_t<I, Types...>>&& get(tuple<Types...>&& tup)
    {
        std::remove_reference<tuple_element<I, type_at_index_t<I, Types...>>>&& base = tup;
        return base.mValue;
    }
};

int main()
{
    std::cout<<"Hello World" << std::endl;
    
    int x = 1;
    float y = 0.1;
    tuple<int, float> t1(x, y);
    
    std::cout << tuple<int, float>::get<0>(t1) << std::endl;
    std::cout << tuple<int, float>::get<1>(t1) << std::endl;

    return 0;
}
