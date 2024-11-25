DEFAULT: clean compile run
clean:
	rm *.o runme
compile main.o: main.c
	gcc -o main.o
run: main.o
	./runme
main.o:
	gcc -c main.c
