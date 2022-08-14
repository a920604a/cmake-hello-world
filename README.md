# Cmake - Hello World

###### tags: `Cmake` `toturials`
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)



## What i can learn
- 認識cmake、看得懂Cmake
- 簡單使用Cmake tool
- 如何自己的Cmake 


## Cmake Introduction 
- CMake並不直接建構出最終的軟體，而是產生標準的建構檔（如Unix的Makefile)
-  CMake設定檔（CMakeLists.txt）
-  類似 使用Python語言開發 的 SCons
-  "Cross platform Make"的縮寫
-  install 
	```shell=
	sudo apt-get -y install cmake
	brew install cmake
	```

## step 1. Create a `CMakeLists.txt` file and Create `build` folder
```cpp=
// CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
	
project(hello VERSION 1.0)
add_executable(hello main.cpp)
```
```cpp=
mkdir ./build  
```

## Step 2. Simple hello world program
```cpp=
// main.cpp
#include <iostream>
int main()
{
    std::cout << "Hello World\n";
    return 0;
}
```

## step 3. Running CMake
```bash=
$ cd ./build
$ cmake ../ 
$ make 
$ ./hello
```
> `cmake ..`對上一層的CmakeLists.txt 
> cmake 產生 `CmakeCache.txt`、`CmakeFiles`、`cmake_install.cmake`、`Makefile`
> 一般來說，會建立 `build` 放置cmake 產生的東西。
> make 產生的可執行檔


- `make --directory=build` 

```cmake=
set_target_properties(target1 target2 ...
                      PROPERTIES prop1 value1
                      prop2 value2 ...)

set_target_properties(hello PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/")
```


## Adding a header file
1. create `include` folder
2. simple `Tim.h`
```cpp=
// Tim.h
#pragma once
#include <iostream>

class Tim
{
public:
    inline void boo()
    {
        std::cout << "Tim!\n";
    }
};
```
```cpp=
// main.cpp
#include <iostream>
#include "Tim.h"
int main()
{
    std::cout << "Hello World\n";
    Tim().boo();
    return 0;
}
```
3. modify `CMakeLists.txt` 
```cmake=
add_executable(hello main.cpp)
+ target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
```
> include_directories(include) 也可以

:::info
:bulb: Prefer the `target_include_directories()` command to add include directories to individual targets and optionally propagate/export them to dependents.
:::

4. build again
```bash=
$ cmake ../ 
$ make 
$ ./hello
```


- 如果 `CMakeLists.txt` 不是放在當前目錄，且指定生成的檔案放置的目錄
```cpp=
cmake -B/path/to/my/build/folder -S/path/to/my/source/folder
```

---


## Multiple source files
```cpp=
+ include_directories(src)
```
> `include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])`  Add the given directories to those the compiler uses to search for include files. 
> 

## Simple template CmakeLists.txt

```cmake=
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")


project(hello VERSION 1.0)


add_executable(hello main.cpp)
target_include_directories(hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(hello PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/")

```

> Specify the C++ Standard
> ```cmake=
> set(CMAKE_CXX_STANDARD 20)
> set(CMAKE_CXX_STANDARD_REQUIRED ON)
> ```
