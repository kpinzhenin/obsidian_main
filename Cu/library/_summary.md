Библиотке бывают статические (.lib, .o) и динамические (.dll, .so).
Отличие заключается в моменте подключения или использования библиотеки. 
Статические подключаются на этапе компоновки (линковки) исполняемого файла.
Динамические могут быть подключены на любом этапе жизни приложения - от запуска до завершения.
динамические библиотеки имеют следующие форматы файлов:
.dll (PE, PE32+, COM, MZ)
.so (ELF, COFF)
.dylib(Mach-O)

в Linux статческие библиотеки создаются утилитой [[ar]] 
ассемблерный код генерируется утилитой [[as]]
компоновщик исполняемых файлов - [[ld]]

анализ исполняемых файлов - objdump, readelf, size, nm, strings

LD_LIBRARY_PATH - переменная среды, где будут производиться поиск динамических библиотек в среде Linux
name mangling