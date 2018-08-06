# Test coverage 

### Target platform: Ubuntu 16.04

Language: C++11 compiled under GCC 5.4.0 using CMake 3.5.1

## Run test coverage

In CMakeLists.txt:

```
option(CodeCoverage "CodeCoverage" ON)
```

In bash:

```
./coverage.sh
```

The report will be placed in ./build/coverage/

## Brief description

Test coverage using lcov and genhtml

## Author

* **Taras Koval** - *All work* - [TarasKoval](https://github.com/TarasKoval)

## License

No license - do what you want
