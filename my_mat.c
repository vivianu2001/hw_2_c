#include <stdio.h>
#include "my_mat.h"
#define n 10
#define INF -1

int arr[n][n];
int floyd[n][n];




void build_Matrix()
{  
	int num=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			scanf("%d",&num);
			arr[i][j]= num;
		}
	}
	
}

void floyd_Warshall();

int is_Exist(int i,int j)
{
	if(i==j)
	{
		return 0;
	}
	
	
	floyd_Warshall();
	return (floyd[i][j]!=INF);


}

int shortest_Path(int i,int j)
{
	if(i==j)
	{
		return -1;
	}
	
	if(is_Exist(i,j))
	{

		return floyd[i][j];
	}
	else
	{
		return -1;
	}

}

void floyd_Warshall()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			floyd[i][j]=INF;
			
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j< n; ++j)
		{
			if(arr[i][j]!=0)
			{
				floyd[i][j]=arr[i][j];
				
			}
		}

	}

	  for (int i = 0; i < n; ++i)
	 {
	 	floyd[i][i]=0;
	 	
	 }

	for (int k  = 0; k < n; ++k)
	{

		 for (int i = 0; i < n; ++i)
		 {
		 	for (int j = 0; j < n ; ++j)
		 	{
		 		if(floyd[i][k]==INF|| floyd[k][j]==INF)
		 		{
		 			continue;
		 		}
		 		if(floyd[i][j]==INF||floyd[i][j]>floyd[i][k]+floyd[k][j])
		 		{
		 			floyd[i][j]= floyd[i][k]+floyd[k][j];
		 			
		 		}
		 	}
		 }
     }

}
