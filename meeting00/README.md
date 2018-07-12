Session 0
=========
[slides](http://david-grs.github.io/00.html)
[compiler explorer](http://www.godbolt.org)

```
git clone <url>
git status
git add <file>
git commit -m "commit message"
...
git push
```

```
cmake ..
VERBOSE=1 cmake --build .
```

```
g++ -o meeting00 meeting00.cc
```

```
disass() {
  gdb -batch -ex 'set disassembly-flavor intel' -ex "file $1" -ex "disassemble '$2'"
}
```

