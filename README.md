# Intro

![C/C++ CI](https://github.com/RaymondZuo301/cmake_example/workflows/C/C++%20CI/badge.svg)

This is an example of CMake & C++ project.

# Dependence

- gtest
- cmake-3.10+
- doxygen(sudo apt-get install doxygen)
- graphviz(sudo apt-get install graphviz)

# Build

```bash
mkdir build
cd build
cmake ..
make
```

# Install

```bash
make install
```

# CPack

```bash
cpack ./CPackConfig.cmake
dpkg -i XXXXX.deb
```

# Test

```bash
cmake .. -DBUILD_TEST=1
make test
```

# Doc

```bash
cmake .. -DBUILD_DOC=1
make doc
```
