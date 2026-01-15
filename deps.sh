#!/bin/bash
sudo apt update
sudo apt install -y \
  cmake git build-essential pkg-config \
  libx11-dev libxrandr-dev libxcursor-dev libxinerama-dev libxi-dev \
  libgl1-mesa-dev libfreetype-dev libjpeg-dev libpng-dev \
  libopenal-dev libflac-dev libvorbis-dev libmpg123-dev \
  libasio-dev \
  doxygen graphviz
