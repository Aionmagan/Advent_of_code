#include <stdio.h>
#include <stdlib.h>

#define ROCK 1
#define PAPER 2
#define SCISS 3

#define LOSS 0
#define DRAW 3
#define WIN 6

typedef struct 
{
	char shape; 
	int  val; 
}rps_t; 

int main(int argc, int argv)
{
	char  		 you,  elf;
	unsigned int eval, pval; 
	unsigned int score = 0; 
	unsigned int decrypted_score = 0; 
	short i; 
	
	rps_t val[]=
	{
		{.shape = 'A', .val = ROCK },
		{.shape = 'B', .val = PAPER},
		{.shape = 'C', .val = SCISS},
		{.shape = 'X', .val = ROCK },
		{.shape = 'Y', .val = PAPER},
		{.shape = 'Z', .val = SCISS}
	};
	
	while(1)
	{
		char buff[10];
		
		fgets(buff, sizeof(buff), stdin);
		if (buff[0] == '1') break;
		
		sscanf(buff, "%c %c", &elf, &you);
		
		for(i = 0; i < 6; ++i)
		{
			rps_t tmp = val[i];
			if (i < 3)
			{
				if (tmp.shape == elf) eval = tmp.val;
			}else 
			{
				if (tmp.shape == you) pval = tmp.val; 
			}
		}
		
		/* R - S = -2 = L
		 * S - P = 1  = L
		 * P - R = 1  = L
		 * S - R = 2  = W
		 * P - S = -1 = W
		 * R - P = -1 = W*/ 
		 
		int tmp = eval - pval; 
		switch(tmp)
		{
			case 0: 
				score += DRAW + pval;
				break;
			case 1:
			case -2:  
				score += LOSS + pval; 
				break;
			case -1:
			case 2: 
				score += WIN + pval; 
				break;
			default:break;
			
		}
		
		/*decrypted score section*/
		tmp = 0;  
		switch(you)
		{
			/*lose*/
			case 'X': 
				if     (eval == ROCK ) tmp += SCISS + LOSS;
				else if(eval == PAPER) tmp += ROCK  + LOSS;
				else if(eval == SCISS) tmp += PAPER + LOSS;
				break;
			/*draw*/
			case 'Y':
				tmp += DRAW + eval;
				break;
			/*win*/
			case 'Z':
				if     (eval == ROCK ) tmp += PAPER + WIN;
				else if(eval == PAPER) tmp += SCISS + WIN;
				else if(eval == SCISS) tmp += ROCK  + WIN;
				break;
			default:break;
		}
		
		decrypted_score += tmp; 
	}

	printf("Solution 1 = %d\n", score);
	printf("Solution 2 = %d\n", decrypted_score);
	return 0;
}
