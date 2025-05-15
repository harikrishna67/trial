OBJ:=$(patsubst %.c,%.o,$(wildcard *.c))
invertedsearch.exe:$(OBJ)
	gcc -o $@ $^
clean:
	rm *.exe *.o

