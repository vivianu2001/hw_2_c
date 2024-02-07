my_mat.o : my_mat.c my_mat.h												
	gcc -c -fPIC -Wall my_mat.c > compilation_my_mat_out.txt 2>&1
	
libmatrix.a: my_mat.o
	ar rcs libmatrix.a my_mat.o > compilation_libmatrix_out.txt 2>&1

main.o: main.c my_mat.h
	gcc -c -fPIC -Wall main.c > compilation_main_out.txt 2>&1

my_graph: libmatrix.a main.o
	gcc -o my_graph main.o libmatrix.a > compilation_my_graph_out.txt 2>&1

my_Knapsack.o: my_Knapsack.c
	gcc -c -fPIC -Wall my_Knapsack.c > compilation_my_Knapsack_out.txt 2>&1

my_Knapsack: my_Knapsack.o
	gcc -o my_Knapsack my_Knapsack.o > compilation_my_Knapsack_out.txt 2>&1

clean :
	rm -f *.o my_graph my_Knapsack libmatrix.a 

all: my_graph my_Knapsack
