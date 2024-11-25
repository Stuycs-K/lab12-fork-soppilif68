DEFAULT: clean compile run
clean:
	rm -f *.o runme
compile runme: main.o
	gcc -o runme main.o
run: runme
	./runme
main.o: main.c
	gcc -c main.c
