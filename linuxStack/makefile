stack:is_empty.o pop.o push.o stack.o main.o
	gcc -o stack is_empty.o pop.o push.o stack.o main.o
main.o:main.c
	gcc -c main.c -o main.o
stack.o:stack.c
	gcc -o stack.o -c stack.c
pop.o:pop.c
	gcc -c pop.c 
push.o:push.c
	gcc -c push.c -o push.o
is_empty.o:is_empty.c
	gcc -o is_empty.o -c is_empty.c
clean:
	rm -f *.o 
	rm -f stack
