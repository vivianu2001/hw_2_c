my_mat.o : my_mat.h												
	gcc -c -fPIC -Wall my_mat.c
	
main.o: main.c my_mat.h
	gcc -c -fPIC -Wall main.c 

my_graph: main.o
	gcc -o my_graph main.o 

my_Knapsack.o: my_Knapsack.c
	gcc -c -fPIC -Wall my_Knapsack.c 

my_Knapsack: my_Knapsack.o
	gcc -o my_Knapsack my_Knapsack.o

clean :
	rm -f *.o my_graph my_Knapsack 

all: my_graph my_Knapsack
