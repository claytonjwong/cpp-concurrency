#!/bin/sh
set -e
cmake . && cmake --build .
./main
