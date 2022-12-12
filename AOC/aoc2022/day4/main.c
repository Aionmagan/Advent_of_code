#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int int_cmp(unsigned int* v1, unsigned int* v2, int l1, int l2)
{	
	unsigned int i, j;
	
	for(i = 0; i < l1; ++i)
	{
		for(j = 0; j < l2; ++j)
		{
			if (v1[i] == v2[j]) {return 1; }
		}
	}
	
	return 0; 
}

int main(int argc, char** argv)
{
	unsigned int x, y, z, w;
	unsigned int i, l1, l2;    
	unsigned int score = 0;
	unsigned int gscore = 0;
	unsigned int *v1, *v2;  
	char         buff[100];
	 
	while(1)
	{
		fgets(buff, sizeof(buff), stdin);
		if (buff[0] == '\n') break;
		
		sscanf(buff, "%u-%u,%u-%u", &x, &y, &z, &w);
		
		//getting length for pointer
		for(i = x, l1 = 0; i <= y; ++i, ++l1);
		for(i = z, l2 = 0; i <= w; ++i, ++l2); 
		
		v1 = calloc(l1, sizeof(int));
		v2 = calloc(l2, sizeof(int)); 
		 
		for(i = x; i <= y; ++i)
			v1[i-x]=i;
		
		for(i = z; i <= w; ++i)
			v2[i-z]=i; 

		if((x <= z && y >= w) || 
		  (z <= x && w >= y)) score++; 

		gscore += int_cmp(v1, v2, l1, l2);
		
		free(v1);
		free(v2); 
	}

	printf("Solution 1 = %d\n", score);
	printf("Solution 2 = %d\n", gscore);
	return 0; 
}
