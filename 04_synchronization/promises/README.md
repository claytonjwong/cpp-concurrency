# Build + Run
```
cmake . && cmake --build . && ./cmake-bin/main
```

# Output
```
➜  promises git:(main) ✗ cmake . && cmake --build . && ./cmake-bin/main
C_COMPILER: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
CXX_COMPILER: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
Boost: 1.84
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/claytonjwong/sandbox/cpp-concurrency/04_synchronization/promises
Consolidate compiler generated dependencies of target main
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable cmake-bin/main
[100%] Built target main
A: 1 2 3 4 5 6 7 8 9 10
and_then_1...       55
and_then_2...      155
and_then_3...      255
no_more_and_then!  355
```
