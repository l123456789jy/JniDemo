# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("jnidemo")




#定义一个库，这个库需要有一个名字xhook，这个名字可以被其他库依赖
add_library(crypto_3 SHARED IMPORTED)
#配置so库的路径 ${PROJECT_SOURCE_DIR}就是当前CMakeLists.txt文件所在的路径app/src/main/cpp
set_target_properties(crypto_3 PROPERTIES IMPORTED_LOCATION
        ${PROJECT_SOURCE_DIR}/lib/libcrypto_3.so)

#定义一个库，这个库需要有一个名字xhook，这个名字可以被其他库依赖
add_library(libhv SHARED IMPORTED)
#配置so库的路径 ${PROJECT_SOURCE_DIR}就是当前CMakeLists.txt文件所在的路径app/src/main/cpp
set_target_properties(libhv PROPERTIES IMPORTED_LOCATION
        ${PROJECT_SOURCE_DIR}/lib/libhv.so)


#定义一个库，这个库需要有一个名字libssl_3，这个名字可以被其他库依赖
add_library(libssl_3 SHARED IMPORTED)
#配置so库的路径 ${PROJECT_SOURCE_DIR}就是当前CMakeLists.txt文件所在的路径app/src/main/cpp
set_target_properties(libssl_3 PROPERTIES IMPORTED_LOCATION
        ${PROJECT_SOURCE_DIR}/lib/libssl_3.so)


# 添加 SO 库的库文件搜索路径
# link_directories("cpp/lib")
# 添加 SO 库的头文件搜索路径
include_directories("cpp/include/hv")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
# 创建动态库名字为"native-lib"，并且依赖下面2个cpp文件
add_library( # Sets the name of the library.
             native-lib
             # Sets the library as a shared library.
             SHARED
             # Provides a relative path to your source file(s).
             native-lib.cpp
             JniTest.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
# 查找 NDK 中的 "log" 库，并将路径存储在 "log-lib" 变量中

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )



# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 将 "log-lib",crypto_3 等其他的库链接到 "native-lib" 库
target_link_libraries( # Specifies the target library.
                       native-lib
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                        crypto_3
                        libhv
                        libssl_3
                         )