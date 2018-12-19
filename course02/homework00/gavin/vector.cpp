//
// Created by gavin on 10/12/2018.
//
#include "vector.h"

VectorInt::VectorInt() : mSize(0)
{}

void VectorInt::push_back(int element) {
    if(mSize >= capacity())
        throw std::out_of_range("Out of capacity");

    mData[mSize] = element;
    mSize++;
}

std::size_t  VectorInt::size() const{
    return mSize;
}

std::size_t  VectorInt::capacity() {
    return mData.size();
}

int& VectorInt::back() {
    if(!mSize)
        throw std::out_of_range("Vector is empty");
    return mData[mSize - 1];
}

int VectorInt::back() const {
    if(!mSize)
        throw std::out_of_range("Vector is empty");
    return mData[mSize - 1];
}

void VectorInt::clear() {
    mSize = 0;
}

int& VectorInt::at(size_t index) {
    if(index >= mSize)
        throw std::out_of_range("Index out of range");
    return mData.at(index);
};

int VectorInt::at(size_t index) const {
    if(index >= mSize)
        throw std::out_of_range("Index out of range");
    return mData.at(index);
};
