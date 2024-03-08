# Build + Run
```
cmake . && cmake --build . && ./cmake-bin/main
```

# Dependencies

* [Boost 1.84](https://www.boost.org/users/history/version_1_84_0.html)
  * installed via `homebrew install boost` into the folder `/opt/homebrew/Cellar/boost/1.84.0_1`

# Output
```
➜  promises git:(main) ✗ cmake . && cmake --build . && ./cmake-bin/main
-- The C compiler identification is AppleClang 15.0.0.15000309
-- The CXX compiler identification is AppleClang 15.0.0.15000309
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
C_COMPILER: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc
CXX_COMPILER: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++
-- Found Boost: /opt/homebrew/lib/cmake/Boost-1.84.0/BoostConfig.cmake (found suitable version "1.84.0", minimum required is "1.84.0") found components: thread
Boost: 1.84 include_directories(/opt/homebrew/include) target_link_libraries(Boost::thread)
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/claytonjwong/sandbox/cpp-concurrency/04_synchronization/promises
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable cmake-bin/main
[100%] Built target main
A: 1 2 3 4 5 6 7 8 9 10
and_then_1...       55
and_then_2...      155
and_then_3...      255
no_more_and_then!  355
```

# Cleanup
```
rm -r CMakeFiles cmake-bin &> /dev/null
rm CMakeCache.txt cmake_install.cmake Makfile &> /dev/null
```
