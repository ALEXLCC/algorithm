myfirst:myfirst.o myfirstmain.o
	g++ -o myfirst myfirst.o myfirstmain.o
myfirst.o myfirstmain.o:myfirst.hpp
	g++ -o myfirst.o -c myfirst.cc
	g++ -o myfirstmain.o -c myfirstmain.cc
clean:
	rm -f *.o
	rm -f myfirst
