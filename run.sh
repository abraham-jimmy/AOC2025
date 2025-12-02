
#!/usr/bin/env bash
set -Eeuo pipefail

# Check if build folder exists
if [ ! -d "build" ]; then
    echo "Build directory does not exist, creating and running cmake build"
    mkdir build
    cmake -B build -S .
fi

function runSource()
{
  cmake --build build --target adventofcode
  if [ $? -ne 0 ]; then
    echo "❌ build failed. not running program."
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
}

function runTest()
{

  cmake --build build --target solution_check
  if [ $? -ne 0 ]; then
    echo "❌ build failed. not running program."
    exit 1
  fi


  case $# in
      0)
          ./build/solution_check
          ;;
      1)
          ./build/solution_check --day "$2"
          ;;
      2)
          ./build/solution_check  --day "$2" --part "$3"
          ;;
      *)
          ./build/solution_check  "$@"
          ;;
  esac

}



    case "$1" in
        -t)
            runTest "$@"
            shift
            ;;
        *)
            runSource "$@"
            shift
            ;;
    esac
