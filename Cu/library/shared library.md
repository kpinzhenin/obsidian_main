Создание дингамической библиотеки

Для включения есть несколько вариантов, все они основаны на том, как передавать ссылку на библиотеку загрузчику. При этом для сборки приложения все равно нужно указывать путь, где лежит библиотека. 
Указания имени библиотеки нужно без префикса "lib" и / в начале и конце пути к библиотеке
1. Ссылка на библиотеку передается при компоновке исполняемого файла:
	```c
	gcc main.o -Llib/shared -lmysharedlib -Wl,-rpath,lib/shared -o main_shared_lib
```
2. Самый простой способ - скопировать библиотку в стандартную директория с библиотеками - например /usr/lib
3. Добавить директорию с подключаемой библиотекой в переменную LD_LIBRARY_PATH:
	```c
	LD_LIBRARY_PATH="/home/teddy/otus-c-2024-07/otus-c-2024-07-pinzhenin/HW-4-libraries/lib/shared/"
	export LD_LIBRARY_PATH
	echo $LD_LIBRARY_PATH
	/home/teddy/otus-c-2024-07/otus-c-2024-07-pinzhenin/HW-4-libraries/lib/shared/
	```
	Важно : 
		путь в конце заканчивается /
		путь должен начинаться прям от корня
	https://wiki.astralinux.ru/pages/viewpage.action?pageId=190913831
4. Использования динамической библиотеку в коде происходит с использованием библиотеки "dlfcn.h".
	https://www.opennet.ru/man.shtml?topic=dlopen&category=3
	пример использования:
	```c
  1 #include <stdio.h>
  2 #include <dlfcn.h>
  3 #include <stdlib.h>
  4 
  5 int add (int a, int b); // signature of shared lib func
  6 
  7 int main(void)
  8 {
  9         void *hundle;
 10         int (*fptr_add)(int, int);
 11  
 12         hundle = dlopen("lib/shared/libmysharedlib.so", RTLD_LAZY);
 13         if(!hundle)
 14         {       
 15                 printf("Error to open lib \n");
 16                 exit(1);
 17         }
 18 //      fptr_add = add;
 19         fptr_add = dlsym(hundle, "add"); // add -symbolic name of func
 20         printf("add = %d \n", fptr_add(2, 2));
 21  
 22         dlclose(hundle);
 23 }
 24 #if 0
 25 int add (int a, int b)
 26 {
 27         return a + b;
 28 }
 29 #endif
	```