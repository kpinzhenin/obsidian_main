 - конфигурация - создается внутреннее представление проекта, при котором происходит выполнение функций и команд, описанных в файле конфигурации. Большая часть вывода к консоль, производится на этом этапе, включаю вывод команды `message` . В конце выводится сообщение о завершение этапа. Я так понимаю, что создается просто внутреннее представление проекта. 
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
```c
include_directories( include )
add_executable( simple_out
	            main.c )
```