#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv)
{
	unsigned int added_cal;
	unsigned int cal; 
	unsigned int total; 
	unsigned int highest_cal[3] = {0,0,0};
	short i = 0;  
	char buff[100]; 
	 
	while(1)
	{
		fgets(buff, sizeof(buff), stdin); 
		
		if (buff[0]=='\n')
		{
			for(i = 0; i < 3; ++i)
			{
				if (added_cal > highest_cal[i])
				{
					highest_cal[i] = added_cal;
					qsort(highest_cal, 3, sizeof(unsigned int), compare);
					break; 
				}
			}
			
			added_cal = 0; 
		}else
		{	
			cal = 0; 
			sscanf(buff, "%u", &cal); 
			
			if (cal == -1) break; 
			
			added_cal += cal; 
		}
	}
	
	total = 0;
	total += highest_cal[0];
	total += highest_cal[1]; 
	total += highest_cal[2];
	
	printf("Solution 1 = %d\n", highest_cal[2]);
	printf("Solution 2 = %d\n", total);
	return 0; 
}
