
#!/usr/bin/env bash
set -Eeuo pipefail

# Check if build folder exists
if [ ! -d "build" ]; then
    echo "Build directory does not exist, creating and running cmake build"
    mkdir build
    cmake -B build -S .
fi


cmake --build build --target adventofcode
if [ $? -ne 0 ]; then
  echo "❌ Build failed. Not running program."
  exit 1
fi


case $# in
    0)
        ./build/adventofcode
        ;;
    1)
        ./build/adventofcode --day "$1"
        ;;
    2)
        ./build/adventofcode --day "$1" --part "$2"
        ;;
    *)
        ./build/adventofcode "$@"
        ;;
esac
