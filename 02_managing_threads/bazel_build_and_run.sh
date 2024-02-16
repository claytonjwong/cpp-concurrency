#!/bin/sh
set -e
bazel build :main
./bazel-bin/main
