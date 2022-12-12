#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	//char **stacks;
	char stacks[9][19]; 
	char buff[100];
	int count[9]={0}; 
	
	while(1)
	{
		fgets(buff, sizeof(buff), stdin);
		if (buff[0] == '\n') break;
		
		//stacks = malloc( 9 * sizeof(stacks));
		//stacks[len] = malloc(stacks[len],(count[len] + 1) * sizeof(*stacks[len]));
		int index  = 0; 
		for(int i = 0; buff[i]!='\0'; i+=4, ++index)
		{
			//printf("buff = %c\n", buff[i]);
			//printf("i = %d, len = %d\n", i, len);
			//create a new stack 
			//stacks[len] = realloc(stacks[len],(count[len] + 1) * sizeof(*stacks[len]));
			
			//store values
			if (buff[i] == '[')
			{
				stacks[index][count[index]] = buff[i+1];
				printf("*stacks= %c\n", *stacks[index]);
				printf("count[len] = %d\n", count[index]);
				count[index]++; 
				//stacks[len]++; //move to the next memory block 
			}
			
/*			stacks[len]--; 
				printf("*stacks[i][j]= %c\n", *stacks[len]);
				stacks[len]++;
*/
		}
	
	}
	
	//for(int i = 0; i < 9; ++i) {stacks[i]-=2;printf("count[%d] = %d\n", i, count[i]);} //reset point position
		
		for(int i = 0; i < 9; ++i)
		{
			for(int j = 0; j < count[i]; ++j)
			{
				//printf("count [%d] = %d", i, count[i]);
				printf("stacks[%d] = %c\n", i, stacks[i][j]);
			}
			
			printf("id %d = %s\n", i, stacks[i]);
		}
	
	return 0; 
}
