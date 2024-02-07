my_mat.o : my_mat.c my_mat.h												
	gcc  -c -fPIC -Wall  my_mat.c 
	
libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o

main.o: main.c my_mat.h
	gcc  -c -fPIC -Wall main.c 

my_graph: libmatrix.a main.o
	gcc -o my_graph main.o libmatrix.a 

my_Knapsack.o: my_Knapsack.c
	gcc -c -fPIC -Wall my_Knapsack.c

my_Knapsack: libmatrix.a my_Knapsack.o
	gcc -o my_Knapsack my_Knapsack.o libmatrix.a

clean :
	rm -f *.o my_graph my_Knapsack libmatrix.a 

all: my_graph my_Knapsack
