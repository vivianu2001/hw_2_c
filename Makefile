


my_mat.o : my_mat.c my_mat.h												
	gcc  -c -fPIC -Wall  my_mat.c 
	
libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o

my_graph.o: my_graph.c my_mat.h
	gcc  -c -fPIC -Wall my_graph.c 

my_graph: libmatrix.a my_graph.o
	gcc -o my_graph my_graph.o libmatrix.a
my_Knapsack: my_Knapsack.c
	gcc -Wall -fPIC my_Knapsack.c -o my_Knapsack
clean :
	rm -f *.o my_graph my_Knapsack *.a *.o 
all: libmatrix.a my_graph my_Knapsack
