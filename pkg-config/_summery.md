Содержит метаданные о установленных пакетах - такие как флаги компиляции.
Облегчает доступ к флагам компиляции и подключаемым библиотекам.
Файлы pkg-config имеют расширение или suffix .pc

Ключевые определения начинаются со слова и заканчивается двоеточием
```
Name: foo
Description: The foo library
Version: 1.0.0
Cflags: -I${includedir}/foo
Libs: -L${libdir} -lfoo
```
также есть переменные, которые состоят из ключевого слова и знака =
```
prefix=/usr/local
exec_prefix=${prefix}
includedir=${prefix}/include
libdir=${exec_prefix}/lib
```

переменные используются для получения значений "ключевых определений". Значения "ключевых определений" экспортируются pkg-config.