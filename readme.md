# gls api wrapper
libgls - простой и удобный sdk для взаимодействия c [Garpix Load System](https://glsystem.net/dokumentaciya-k-api). В данный момент находится в активной разработке.
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
