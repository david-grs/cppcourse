#include <boost/optional.hpp>
#include <memory>

// I couldn't decide what type to make data
template <typename T>
struct Node {
    Node() = delete;
    Node(T data)
        : mData{ std::make_unique<T>(std::move(data)) } {};

    const boost::optional<Node<T>&> Next() const { return *mNxt; };

    const T& GetData() const { return *mData; };
    const std::size_t GetSize() const { return mSize; };
    const bool Empty() const { return mSize == 0; }

    Node<T>& Append(T);
    Node<T>& Append(T, const std::size_t);

    Node<T>& Pop();
    boost::optional<Node<T>&> Pop(const std::size_t);

    boost::optional<Node<T>&> At(const std::size_t);

private:
    Node* mNxt = nullptr;
    std::unique_ptr<T> mData = std::unique_ptr<T>{};
    std::size_t mSize{ 0 };
};
