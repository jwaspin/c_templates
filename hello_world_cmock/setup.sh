#!/bin/bash

mkdir bin

git clone https://github.com/ThrowTheSwitch/unity.git

git clone --recursive https://github.com/throwtheswitch/cmock.git && cd cmock/ && bundle install && echo "cmock successfully installed"
