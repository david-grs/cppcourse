Snake
=====
This first project consists of developing a simple 2D snake game with [libcinder](http://libcinder.org/)!

There is no particular requirement, the idea is to have fun while practicing your C++ on a real project. The only important 
guideline is to keep things as simple as possible &mdash; elegance comes with simplicity, and performance too, most of the time. 
Snake is a simple game, so should be your code. 

You should not need anything else than what we discussed so far: classes, references, std::vector, small and isolated compilation units.

As earlier, I am waiting for your pull requests. Don't edit directly the files, create a directory with your name to avoid conflicts.

Deadline: Tuesday, 21st August



Building libcinder
------------------

  1. Install the dependencies needed for libcinder &mdash; from [Ubuntu Notes on libcinder.org](https://www.libcinder.org/docs/guides/linux-notes/ubuntu.html):

```
sudo apt-get install libxcursor-dev \
libxrandr-dev \
libxinerama-dev \
libxi-dev \
libgl1-mesa-dev \
libglu1-mesa-dev \
zlib1g-dev \
libfontconfig1-dev \
libmpg123-dev \
libsndfile1 \
libsndfile1-dev \
libpulse-dev \
libasound2-dev \
libcurl4-gnutls-dev \
libgstreamer1.0-dev \
libgstreamer-plugins-bad1.0-dev \
libgstreamer-plugins-base1.0-dev \
gstreamer1.0-libav \
gstreamer1.0-alsa \
gstreamer1.0-pulseaudio \
gstreamer1.0-plugins-bad
```

NOTE: If you are using CentOS instead of Ubuntu, use `yum install` instead of `apt-get install`. 

NOTE2: I found [this link](https://github.com/cinder/Cinder/wiki/Cinder-for-Linux-%7C-Fedora-23-24-on-x86_64) about Fedora 23. The article is only one year old so it could work for CentOS.


  2. Build `libcinder` (here, Debug build)

```
git clone --recursive https://github.com/cinder/Cinder.git
cd Cinder
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8
```


  3. Build your project (= from the skeleton in this directory) by configuring cmake with: 

```
cmake  -DCMAKE_BUILD_TYPE=Debug -DCINDER_PATH=~/Cinder ..

```

where `~/Cinder` is the directory you cloned in step 2.

NOTE: if you build your application in Release, then you need to build libcinder in Release too.

