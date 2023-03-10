# Reversing de binario producido por "../direccionado.c", compilado de la siguiente forma
```sh
	gcc ../direccionado.c --static -o binario
```

### para conocer las syscalls (entorno:ubuntu)
```sh
	cat /usr/include/i386-linux-gnu/asm/unistd_32.h | grep "__NR_"
```

### sintaxis  AT&T e INTEL, respectivamente.
```sh

gdb -q ./binario

(gdb) disass _exit

(gdb) set disassembly-flavor intel

(gdb) disass _exit

```