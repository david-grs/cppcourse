#include <array>
#pragma once

class VectorInt
{
public:
	int size();

	int capacity();

	int back();

	void push_back(int);
	
	void clear();

	VectorInt();

private:
	int vectorSize;
	
	std::array<int, 42> vectorData;
};


