#include <boost/optional.hpp>
#include <memory>
#include <string>

// I couldn't decide what to make data
template <typename T>
struct Node
{
	Node() = delete;
	Node(T data) : mData{std::make_unique<T>(std::move(data))} {};

	std::unique_ptr<T> mData = std::unique_ptr<T>{};

	boost::optional<Node<T>> Next() const { return mNxt; };

	Node<T>* Append(T val)
	{
		Node<T>* new_node = new Node<T>{val};
		return new_node;
		/* mNxt = new Node<T>{val}; */
		/* return mNxt.get(); */
	}

private:
	boost::optional<Node&> mNxt = boost::none;
};
