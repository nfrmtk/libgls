# gls api wrapper

## build
```shell
mkdir -p build
cd build 
cmake .. 
cmake --build . # to build everything we got
cmake --build . --target=play # to build play.cpp
```

## run tests
```shell
make tests
```
or repeat what is written in the makefile
```shell
mkdir -p build
cd build 
cmake .. 
cmake --build . --target=test
cd tests
(test -t 1 && GTEST_COLOR=1 PYTEST_ADDOPTS="--color=yes" ctest -V) || ctest -V
```
