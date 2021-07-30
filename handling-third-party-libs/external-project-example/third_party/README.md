# Third party libs project

This project installs third party libs locally so that they do not pollute the system.

## Build

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug --parallel 8
cmake --install cmake-build-debug
```