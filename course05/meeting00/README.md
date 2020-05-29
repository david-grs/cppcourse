Build
=====
g++ -o main main.cc
g++ -o main -std=c++17 -g -Wall  main.cc

cmake -DCMAKE_BUILD_TYPE=Debug .
make


Debug
=====
gdb ./main

Inside GDB:
r
b foo
b main.cc:13
bt
frame
p name

