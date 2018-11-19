#pragma once
#include <iostream>
#include <memory>

class String
{
 public:
  String();
  
  String(const String&);
  String& operator=(String);

  String(char);
  String& operator=(char);
  
  String(const char*);
  String& operator=(const char*);
  
  String operator+(const String&) const;
  String operator+(const char*) const;

  bool operator==(const String&) const;

  char operator[](int) const;
  char& operator[](int);

  int size() const;
  int capacity() const;
  
  bool empty() const;

  char* c_str() const;
  
  operator std::string() const
  {
    return std::string(c_str());
  };
  
 private:
  void grow();

  int mSize;
  int mCapacity;
  std::unique_ptr<char[]> mData;
};

std::ostream& operator<<(std::ostream&, const String&);
String operator+(const char*, const String&);
bool operator==(const char*, const String&);
bool operator==(std::string, const String&);
