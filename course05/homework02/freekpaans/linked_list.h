#include <cstddef>
#include <memory>
#include <iterator>
#include <numeric>

template <typename T>
class LinkedList {
public:
	using size_type = std::size_t;
	using value_type = T;
	using reference = T&;
	using const_reference = const T&;

	struct Link
	{
		T mValue;
		std::unique_ptr<Link> mNext;
	};

	using LinkPtr = std::unique_ptr<Link>;

	LinkedList() =default;
	LinkedList(const LinkedList& from);

	LinkedList& operator=(const LinkedList& from);

	bool empty() const
	{
		return !mFront;
	}

	size_type size() const;

	void push_front(const_reference str);
	void pop_front();
	void insert_at(size_type index, const_reference str);

	const_reference front() const;
	const_reference at(size_type index) const;

	struct iterator : public std::iterator<std::input_iterator_tag, T, size_type>
	{
		const Link* mLink;

		explicit iterator(const Link* link) : mLink{link}
		{}

		bool operator==(const iterator& other) const
		{
			return mLink == other.mLink;
		}

		bool operator!=(const iterator& other) const
		{
			return !(*this == other);
		}

		iterator& operator++()
		{
			mLink = mLink->mNext.get();
			return *this;
		}

		const_reference operator*() const
		{
			return mLink->mValue;
		}
	};

	iterator begin() const
	{
		return iterator{mFront.get()};
	}

	iterator end() const
	{
		return iterator{nullptr};
	}

private:
	LinkPtr mFront{};
};

template <typename T>
static void push_at(
	typename LinkedList<T>::LinkPtr& link,
	typename LinkedList<T>::const_reference item)
{
	typename LinkedList<T>::LinkPtr newLink{new typename LinkedList<T>::Link { item, {} }};

	newLink->mNext = std::move(link);
	link = std::move(newLink);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& from)
{
	std::accumulate(
		from.begin(), from.end(),
		std::ref(mFront),
		[](LinkPtr& output, const_reference item) -> LinkPtr&
		{
			push_at<T>(output, item);

			return output->mNext;
		});
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& from)
{
	LinkedList copy{from};
	mFront = std::move(copy.mFront);
	return *this;
}

template <typename T>
typename LinkedList<T>::size_type LinkedList<T>::size() const
{
	return std::distance(begin(), end());
}

template <typename T>
void LinkedList<T>::push_front(LinkedList<T>::const_reference str)
{
	push_at<T>(mFront, str);
}

template <typename T>
void LinkedList<T>::pop_front()
{
	mFront = std::move(mFront->mNext);
}

template <typename T>
typename LinkedList<T>::const_reference LinkedList<T>::front() const
{
	return mFront->mValue;
}

template <typename T>
auto LinkedList<T>::at(size_type index) const -> const_reference
{
	return *std::next(begin(), index);
}

template <typename T>
static typename LinkedList<T>::LinkPtr& find_link(
	typename LinkedList<T>::LinkPtr& from,
	typename LinkedList<T>::size_type index)
{
	auto* link = &from;

	while(index-- > 0)
	{
		link = &link->get()->mNext;
	}

	return *link;
}

template <typename T>
void LinkedList<T>::insert_at(size_type index, const_reference str)
{
	push_at<T>(find_link<T>(mFront, index), str);
}
