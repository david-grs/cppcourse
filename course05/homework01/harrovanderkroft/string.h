#pragma once


#include <stdexcept>
#include <ostream>
#include <string>
#include <cstring>
#include <array>

class String
{
private:
    static constexpr int MAX_STRING_SIZE = 1024;
	std::array<char, MAX_STRING_SIZE> chars;
    std::size_t size_of_string;
public:
	String(){
        this->size_of_string = 0;
	}
	String(std::string strInput){
        this->ParseChar( (char*)strInput.c_str());
    }
	String(const char chars[]){
        this->ParseChar(chars);
	}
    
    void ParseChar(const char chars[]){ 
        char currentChar = chars[0];
        int currentIndex = 0;
        while(currentChar != '\0'){
            this->chars[currentIndex] = currentChar;
            currentIndex++;
            currentChar = chars[currentIndex];
        }
        this->size_of_string = (std::size_t) currentIndex;
    } 

    char CharAt(int i ){
        return this->chars[i];
    }

    String operator+=(String other){
        return *this + other;
    }
    String operator+(String other){
        std::size_t totalLength = this->Size() + other.Size();
        if(totalLength > MAX_STRING_SIZE){
            throw std::length_error("Can't concatenate more than 1024 in total");
        }
        int indexStart = (int)this->Size();
        for(int i = 0; i <= indexStart; i++){
            this->chars[indexStart + i] = other.CharAt(i);
        }
        this->size_of_string = (std::size_t) totalLength;
        return *this;
    }

    bool operator!=(String other) {
        return !(this == &other); 
    }

    bool operator==(String other) {
        if(this->Size() != other.Size()){
            return false;
        }
        for(int i = 0; i < (int) this->Size(); i++){
            if(this->at(i) != other.at(i)){
                return false;
            }
        }
        return true;
    }

    char at(int i) const {
        return this->chars[i];
    }

    char operator[](int i) const    {
        return this->at(i);
    }
    
    std::size_t Size() const {
        return this->size_of_string;
    }

	bool Empty() const {
        return true;
    }
};

std::ostream& operator<<(std::ostream& stream, String str)
{
    assert(False);
	return stream;
}

