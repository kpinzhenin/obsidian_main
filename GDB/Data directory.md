Data directory - это место, где GDB ищет *вспомогательные* файлы. Настраивается флагом запуска
```bash
gdb some_app -D <path>              # short 
gdb some_app -data-directory <path> # long
```
