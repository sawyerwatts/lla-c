# Libraries

There are shared objects (`.so` ) and archives / static objects (`.a`).

Shared objects are DLLs and static objects produce self-contained binaries.

## Shared Objects

Shared objects have their own ELFs (in the same memory space) and the loader will link the
application to the library at run time.

```sh
cd lib
gcc -Wall -Werror -o ../libteehee.so libtee.c -c -shared
cd ..
# Need -Ilib b/c that dir has the header for the shared object
# Need -l to link against lib (but omit ^lib and .so$ from arg)
# Need -L to specify library search path
gcc -Wall -Werror -o main main.c -Ilib -lteehee -L$(pwd) && ./main
# If the linker struggles to find the so, need to add custom lib dir to path:
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd) ./main
# To properly install the so, move it to /usr/lib (or wherever else that's on lib path)
```

## Static Objects

Static objects are object (`.o`) compressions and they are compiled into your app binary. These make
larger binaries (since they contain duplicates of potentially shared libraries).

```sh
cd lib
gcc libtee.c -c
ar rcs ../libteehee.a libtee.o
cd ..
# Need -Ilib b/c that dir has the header for the static object
gcc -Wall -Werror -o main main.c libteehee.a -Ilib && ./main
```

