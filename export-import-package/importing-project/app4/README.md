# App4

Demonstrates linking against imported lib4

## Build

```bash
cmake -S . -B cmake-debug-build -DCMAKE_BUILD_TYPE=Debug \
                                -DCMAKE_PREFIX_PATH=../../exporting-project/cmake-build-debug/install

cmake --build cmake-debug-build
```

## Run

```bash
./cmake-build-debug/app4
```
