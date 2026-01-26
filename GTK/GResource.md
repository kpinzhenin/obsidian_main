Пока помещу здесь.
В gresource можно объединить .ui файлы интерфейсов, иконки и прочее. в файлы исходников `.c` и соответственно файл заголовочный `.h`.
Для генерации используется утилита `glib-compile-resources`
```bash
 glib-compile-resources.exe --target=rs_resource.c --generate-source resorces.gresource.xml
```
генерирует `.c`
```bash
glib-compile-resources.exe --target=rs_resource.h --generate-header resorces.gresource.xml
```
генерирует `.h`
Для генерации используется `.xml` файл описания, в нем просто указывается какие файлы используются для генерации и какой имя будут иметь при вызове из других исходников.
```xml
<?xml version="1.0" encoding="UTF-8"?>
<gresources>
	<gresource prefix="/app">
		<file>ui_rs485_frame.ui</file>
	</gresource>
 </gresources>
```
`.ui` файл тоже должен существовать