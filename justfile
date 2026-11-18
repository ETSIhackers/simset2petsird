set shell := ['bash', '-ceuo', 'pipefail']

cmake_install_prefix := "$CONDA_PREFIX"
cmake_build_type := "Release"
cmake_build_dir := "cpp/build"
simset_root := cmake_build_dir + "/_simset"

@default: build

@help:
   echo 'Usage - "just [cmake_install_prefix=<CMAKE_INSTALL_PREFIX>] [cmake_build_dir=<BUILD_DIR>] [cmake_build_type=Release]"'
   echo 'The variables will be passed to CMake for the C++ build.'
   echo 'Defaults:'
   echo "  cmake_install_prefix=\$CONDA_PREFIX (which is currently set to \"$CONDA_PREFIX\")"
   echo '  cmake_build_type=Release'
   echo '  cmake_build_dir=cpp/build (this is relative to the STIR2PETSIRD folder)'
   echo 'Run "just --summary" for possible recipes (default recipe is "build")'

@simset:
   mkdir -p "{{simset_root}}"
   mkdir -p "{{simset_root}}"
   if [[ ! -d "{{simset_root}}/src/.git" ]]; then \
      git clone --depth 1 --branch stir-compatibility \
      https://github.com/NikEfth/simset.git "{{simset_root}}/src"; \
   fi

   cmake -G Ninja -S "{{simset_root}}/src" -B "{{simset_root}}/build" \
      -DCMAKE_INSTALL_PREFIX:PATH="$PWD/{{simset_root}}/install" \
      -DSIMSET_BUILD_TOOLS:BOOL=OFF
   cmake --build "{{simset_root}}/build" --parallel
   cmake --install "{{simset_root}}/build"

@configure:
   cmake -GNinja -S cpp -B {{cmake_build_dir}} \
      -DCMAKE_BUILD_TYPE:BOOL={{cmake_build_type}} \
      -DCMAKE_INSTALL_PREFIX:PATH={{cmake_install_prefix}} \
      -DSimSET_DIR:PATH="$PWD/{{simset_root}}/install/lib64/cmake/SimSET-2.9"

@build: simset configure
   cd {{cmake_build_dir}} && \
      cmake --build . --config {{cmake_build_type}} \
      # cmake --install .
