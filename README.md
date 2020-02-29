# Intro

![C/C++ CI](https://github.com/RaymondZuo301/cmake_example/workflows/C/C++%20CI/badge.svg)

This project is an example of a CMake & C++ project

# Dependence

- gtest
- dmake
- doxygen
- graphviz

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
make test
```

# Doc

```bash
make doc
```
