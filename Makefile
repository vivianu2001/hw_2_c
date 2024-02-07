


my_mat.o : my_mat.c my_mat.h												
	gcc  -c -fPIC -Wall  my_mat.c 
	
libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o

main.o: main.c my_mat.h
	gcc  -c -fPIC -Wall main.c 

my_graph: libmatrix.a main.o
	gcc -o my_graph main.o libmatrix.a
my_Knapsack: my_Knapsack.o
	gcc -o -fPIC -Wall my_Knapsack.o
my_Knapsack.o: my_Knapsack.c
	gcc -c -fPIC -Wall my_Knapsack.c
clean :
	rm -f *.o my_graph my_Knapsack *.a *.o 
all: libmatrix.a my_graph my_Knapsack
