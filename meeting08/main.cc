#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <deque>

void* operator new(std::size_t bytes)
{
	std::cout << "allocation " << bytes << std::endl;
	return std::malloc(bytes);
}

class Image 
{
public:
	Image() { std::cout << "ctor" << std::endl; }
	Image(const Image&) { std::cout << "copy ctor" << std::endl; }
	Image& operator=(const Image&) { std::cout << "assignment op" << std::endl; return *this; }

	std::array<int, 1024 * 8> mContent;
};

int main()
{
	Image img;
	// img.read("something");

	//std::deque<Image> v;
	std::vector<Image> v;
	//v.reserve(1000);

	std::cout << "START" << std::endl;
	v.push_back(img);
	v.push_back(img);

	// Image& r = v.back(); 
	v.push_back(img);
	v.push_back(img);
	v.push_back(img);
	v.push_back(img);

	std::set<int> ss;
	ss.insert(5);
	ss.insert(3);
	ss.insert(3);
	ss.insert(2);

	for (int i : ss)
		std::cout << i << std::endl;

	return 0;
}

