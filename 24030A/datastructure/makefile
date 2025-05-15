res.exe : main.o foo.o foo2.o
	gcc -o res.exe main.o foo.o foo2.o
main.0 : main.c
	gcc -c main.c
foo.o : foo.c
	gcc -c foo.c
foo2.o : foo2.c
	gcc -c foo2.c
clean :
	rm *.o *.exe

