# Pacman
<img src="https://github.com/dovito/Pacman/blob/master/pacman.gif" width="400" height="300">

## Improvement TODOs:
* Add sensible ghost walking algorithm
* Improve pacman's controling

# Setup
## Linux
```
mkdir build
cd build
cmake -DCINDER_PATH=path_to_cinder ..
make
```
## To setup Cinder:
### Install CMake
```
sudo apt-get install cmake
```
### Install Clang
```
sudo apt-get install clang
```
To set Clang as the default compiler, select /usr/bin/clang++ when prompted by this command: 
```
sudo update-alternatives --config c++
```
### Cinder dependencies
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

### Fetching and building Cinder
```
git clone --recursive https://github.com/cinder/Cinder.git
cd Cinder
mkdir build && cd build
cmake ..
make -j 8
```
