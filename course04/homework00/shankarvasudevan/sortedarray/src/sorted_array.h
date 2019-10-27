#include <vector>

class SortedArray
{
public:
	explicit SortedArray(std::size_t capacity);
	
	const std::size_t size();
	void clear();
	void push_back(std::size_t value);
	const std::size_t operator[](std::size_t index);
	const std::size_t at(std::size_t index);
		
private:
	std::vector<size_t> mData;
	std::size_t mCapacity;
};

