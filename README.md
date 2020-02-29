# Intro

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
