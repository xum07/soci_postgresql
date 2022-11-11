# Introduction
A simple test program for the combination of [PostgreSQL](https://github.com/postgres/postgres) and [SOCI](https://github.com/SOCI/soci)

PostgreSQL and SOCI are both added as git submodules in this project. And the binary files of them under **gcc v11.3(Ubuntu 22.04)** are put under `opensource` folder. If under the same environment, just reuse the binary files, otherwise you need to download the git submodules and recompile them to cover the binary files in the `opensource` folder.

## PostgreSQL compilaion
1. Execute `./configure --prefix={install path} CFLAGS="-O2" --without-readline` if you want to get a release version with better performance. Besides, [bison](https://ftp.gnu.org/gnu/bison/) and [flex](https://github.com/westes/flex) are neccessary dependent libraries. At the same time, [readline](https://ftp.gnu.org/gnu/readline/)(do not install if you do not need to type sql by word) and [zlib](https://zlib.net/) are recommanded to install.
2. After that, execute `make & make install` to install executable binary file and libraries to `{install path}`
3. Add `LD_LIBRARY_PATH` and `PATH` before executing `initdb` and `pg_ctl` to help library search. Finally, type `pg_ctl -D {database files path} -l {log file path} start` to run PostgreSQL.

## SOCI compilation
Below is the guide in `cmake/modules/FindPostgreSQL.cmake` in SOCI project. Do not follow [the official documents about compilation](https://soci.sourceforge.net/doc/master/installation/) for some important details missing, just read the cmake project since it's very simple

```cmake
# If you have installed PostgreSQL in a non-standard location.
# (Please note that in the following comments, it is assumed that <Your Path>
# points to the root directory of the include directory of PostgreSQL.)
# Then you have three options.
# 1) After CMake runs, set POSTGRESQL_INCLUDE_DIR to <Your Path>/include and
#    POSTGRESQL_LIBRARY_DIR to wherever the library pq (or libpq in windows) is
# 2) Use CMAKE_INCLUDE_PATH to set a path to <Your Path>/PostgreSQL<-version>. This will allow find_path()
#    to locate POSTGRESQL_INCLUDE_DIR by utilizing the PATH_SUFFIXES option. e.g. In your CMakeLists.txt file
#    set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "<Your Path>/include")
# 3) Set an environment variable called ${POSTGRESQL_ROOT} that points to the root of where you have
#    installed PostgreSQL, e.g. <Your Path>.
```

Follow the above guide, the compilation of SOCI with PostgreSQL
1. use `export` command to set `CMAKE_INCLUDE_PATH` and `CMAKE_LIBRARY_PATH` both, or `POSTGRESQL_ROOT`, or directly set them in cmake options.
2. execute cmake command `mkdir build && cd build && cmake ../ -G "Unix Makefiles" -DWITH_BOOST=ON -DCMAKE_INSTALL_PREFIX={install path} -DWITH_POSTGRESQL=ON -DCMAKE_INCLUDE_PATH={postgresql_include} -DCMAKE_LIBRARY_PATH={postgresql_library}` under root path of project SOCI
3. Finally, execute `make && make install`

> A deeper introduction about SOCI please see [SOCI_guide](./doc/SOCI_guide.md)
