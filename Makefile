


my_mat.o : my_mat.c my_mat.h												
	gcc  -c -fPIC -Wall  my_mat.c 
	
libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o

main.o: main.c my_mat.h
	gcc  -c -fPIC -Wall main.c 

my_graph: libmatrix.a main.o
	gcc -o connections main.o libmatrix.a 


clean :
	rm -f *.o connections libmatrix.a 
all: my_graph
