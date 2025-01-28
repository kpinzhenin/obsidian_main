в make можно вызвать bash скрипт следующим образом, покаду нра примере pkg-config
```
// Makefile

 # build filename
   SRC_FILENAME=example-0
   SRC_GLIB_FILENAME=glib_fileTree
  
 # glib gcc flags
  CFLAGS_GLIB=$(shell pkg-config --cflags glib-2.0)
  LFLAGS_GLIB=$(shell pkg-config --libs glib-2.0)

17 build_glib2.0: $(SRC_GLIB_FILENAME).c
 18 >·······gcc $(CFLAGS_GLIB) -o $(SRC_GLIB_FILENAME) $(SRC_GLIB_FILENAME).c $(LFLAGS_GLIB)
```