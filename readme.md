# gls api wrapper

## install
```commandline
mkdir -p build
cd build 
cmake .. 
cmake --build . # to build everything we got
cmake --build . --target=test # to build test.cpp without play.cpp
```

## run tests
```commandline
make tests
```
or repeat what is written in the makefile
```commandline
mkdir -p build
cd build 
cmake .. 
cmake --build . --target=test
cd tests
(test -t 1 && GTEST_COLOR=1 PYTEST_ADDOPTS="--color=yes" ctest -V) || ctest -V
```
