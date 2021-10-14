# Adding/Enabling/Disabling preprocessor definitions with modern CMake

This example demonstrates how to add/enable/disable certain parts of code using preprocessor defintions via CMake.

## Build with flag enabled

```bash
cmake -S . -B build -DENABLE_MY_FLAG=ON
```

## Build with flag disabled

```bash
cmake -S . -B build -DENABLE_MY_FLAG=OFF
```