#include <cstddef>
#include <string>
#include <memory>
#include <iterator>

class LinkedList{
public:
	using size_type = size_t;

	struct Link
	{
		std::string mValue;
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

	void push_front(const std::string& str);
	void pop_front();
	void insert_at(size_type index, const std::string& str);

	const std::string& front() const;
	const std::string& at(size_type index) const;

	struct iterator : public std::iterator<std::input_iterator_tag, std::string, size_type>
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

		const std::string& operator*() const
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
