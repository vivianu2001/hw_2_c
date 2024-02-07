# include <stdio.h>
#include "my_mat.h"

 int main()
{	
    int i=0,j=0; 
	
    char c='D';
    int boolean=true;
  	while(boolean)
  {
		scanf("%c",&c);

		switch (c)
		{
		case 'A': 
			build_Matrix();

			break;

		case 'B':
			scanf("%d %d", &i,&j);
				if(is_Exist(i,j))
				   {
					   printf("True\n");
				   }
			else
				   {
					   printf("False\n");
				   }
			break;

		case 'C':
			scanf("%d %d", &i,&j);
			printf("%d\n",shortest_Path(i,j));
			break;

		case 'D':
			boolean=false;
			break;
		}


	}
	

	return 0;
}
