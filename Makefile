FMT ?= clang-format

build:
	@mkdir -p build
	@cd build && cmake .. && cmake --build . --target=test

tests: build
	@cd build/tests && ((test -t 1 && ctest -V) || ctest -V)

.PHONY: tests build
clean:
	@rm -rf build
	@rm -rf cmake-*


.PHONY: format
format:
	@find lib -name '*pp' -type f | xargs $(FMT) -i
	@find tests -name '*pp' -type f | xargs $(FMT) -i
	@echo "play.cpp" | xargs $(FMT) -i
