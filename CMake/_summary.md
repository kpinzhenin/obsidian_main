 - конфигурация - создается внутреннее представление проекта, при котором происходит выполнение функций и команд, описанных в файле конфигурации. Большая часть вывода в консоль, производится на этом этапе, включаю вывод команды `message` . В конце выводится сообщение о завершение этапа. Я так понимаю, что создается просто внутреннее представление проекта. 
 - Генерация - когда CMake завершает чтение и обработку файла CMakeLists.txt. На этом этапе создаются файлы проекта используя `internal representanion build up` созданного на этапе конфигурации. 

`target` обычно, это исполняемый или библиотека.
### Минимальный файл
```c
cmake_minimum_required( VERSION 3.10 )

project( cmake_project_name # it's not name for execution out
		VERSION 0.1.1 # project version
		LANGUAGES C )

add_executable( simple_out # name of out execution application
	            main.c )
```
### Добавление библиотеки
#### Создание и добавление библиотеки 
```c
# create the library
# "some_lib" inside include directory
add_library( simple_lib STATIC include/some_lib.c )
# create executable
add_executable( simple_out
	            main.c )
# link library to executed project
target_link_libraries( simple_out PRIVATE simple_lib )
```
### Подключение директории для поиска (заголовочных файлов)
```c
target_include_directories( targetName 
[dir1] # path to headers file
[dir2]
)
```
используется следующим образом
```CMake
include_directories( include )
add_executable( simple_out
	            main.c )
```

### Запуск из командной строки для разных структур проекта. [[Structure of project]]
#### для конфигурации отдельного скрипта в каждом src
/home/k.pinzhenin/cmake_ex/src_bld_ex/
├── build/
├── src/
│   └── CMakeLists.txt
├── ui_dir/
│   ├── build/
│   ├── src/
│   │   └── CMakeLists.txt

``` C
/* /home/k.pinzhenin/cmake_ex/src_bld_ex/src/CMakeLists.txt */
cmake_minimum_required( VERSION 3.20 )
project( cmake_dir_ex )

message( "inside main cmake src[${CMAKE_CURRENT_SOURCE_DIR} and bld[${CMAKE_CURRENT_BINARY_DIR}] " )

# simple call sub script
add_subdirectory( ../ui_dir/src ../ui_dir/build)
//===============================================================
/* /home/k.pinzhenin/cmake_ex/src_bld_ex/ui_dir/src/CMakeLists.txt */
cmake_minimum_required( VERSION 3.20 )
#project( cmake_dir_ex )

message( "inside SUB cmake src[${CMAKE_CURRENT_SOURCE_DIR} and bld[${CMAKE_CURRENT_BINARY_DIR}] " )
```
```bash
k.pinzhenin@SIS009498 UCRT64 ~/cmake_ex/src_bld_ex
$ cmake -Ssrc/ -Bbuild/

inside main cmake src[/home/k.pinzhenin/cmake_ex/src_bld_ex/src and bld[/home/k.pinzhenin/cmake_ex/src_bld_ex/build]
inside SUB cmake src[/home/k.pinzhenin/cmake_ex/src_bld_ex/ui_dir/src and bld[/home/k.pinzhenin/cmake_ex/src_bld_ex/ui_dir/build]
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/k.pinzhenin/cmake_ex/src_bld_ex/build
```

#### для главного скрипта в  корне и отдельных в каждом src
/home/k.pinzhenin/cmake_ex/src_bld_ex/
├── CMakeLists.txt
├── build/
├── src/│   
├── ui_dir/
│   ├── build/
│   ├── src/
│   │   └── CMakeLists.txt
``` C
/* /home/k.pinzhenin/cmake_ex/src_bld_ex/CMakeLists.txt */
cmake_minimum_required( VERSION 3.20 )
project( cmake_dir_ex )

message( "inside main cmake src[${CMAKE_CURRENT_SOURCE_DIR} and bld[${CMAKE_CURRENT_BINARY_DIR}] " )

# simple call sub script
add_subdirectory( ui_dir/src ui_dir/build)
//===============================================================
/* /home/k.pinzhenin/cmake_ex/src_bld_ex/ui_dir/src/CMakeLists.txt */
cmake_minimum_required( VERSION 3.20 )
#project( cmake_dir_ex )

message( "inside SUB cmake src[${CMAKE_CURRENT_SOURCE_DIR} and bld[${CMAKE_CURRENT_BINARY_DIR}] " )
```
``` bash
k.pinzhenin@SIS009498 UCRT64 ~/cmake_ex/src_bld_ex/build
$ cmake ..
inside main cmake src[/home/k.pinzhenin/cmake_ex/src_bld_ex and bld[/home/k.pinzhenin/cmake_ex/src_bld_ex/build]
inside SUB cmake src[/home/k.pinzhenin/cmake_ex/src_bld_ex/ui_dir/src and bld[/home/k.pinzhenin/cmake_ex/src_bld_ex/build/ui_dir/build]
-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/k.pinzhenin/cmake_ex/src_bld_ex/build

```