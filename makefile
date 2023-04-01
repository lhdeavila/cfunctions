# make
bienvenido:
	gcc -o arbol arbol.c getch.o
getch.o:
	gcc -c getch.c