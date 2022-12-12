#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char charcmp(char *str1, char *str2, int length)
{	
	int i, j; 
	
	for(i = 0; i < length; ++i)
	{
		for(j = 0; j < length; ++j)
		{
			if (str1[i] == str2[j])
			{
				return str1[i];
			}
		}
	}
	
	return '\0'; 
}

int ascii_offset(char ch)
{	
	return (ch - (isupper(ch) ? 38 : 96)); 
}

int badge_calculation(char *s, unsigned int str_len)
{
	static char*        str[3]    = {NULL};
	static int          store_str = 0;
	static unsigned int len[3];  
	unsigned int        i, j, k; 
	
	len[store_str] = str_len; 
	str[store_str] = calloc(str_len, sizeof(char));  
	strncpy(str[store_str], s, str_len); 
	store_str++; 
	
	if (store_str>2)
	{
		for(i = 0; i < len[0]; ++i)
		{
			if (strchr(str[1], str[0][i])!=NULL)
			{
				if (strchr(str[2],str[0][i])!=NULL)
				{
					char ch = str[0][i]; 
					free(str[0]); free(str[1]); free(str[2]);
					store_str = 0; 
					return ascii_offset(ch); 
				}
			}
		}
	}	
	
	return 0; 
}

int main(int argc, char** argv)
{	
	unsigned int str_length  = 0;
	unsigned int str_half    = 0;  
	unsigned int score       = 0; 
	unsigned int group_score = 0; 
	char         buff[200], tmp;
	char*        str1;
	char*        str2;
	
	while(1)
	{
		fgets(buff, sizeof(buff), stdin);
		if (buff[0] == '\n')break;
		
		str_length = strlen(buff);
		str_length--; //removing the '\n' that fgets collects
		str_half = str_length>>1; 
		
		/*realloc assigned garbage data
		 *too lazy to clean up so calloc 
		 *it is
		 */
		str1 = calloc(str_half, sizeof(char)); 
		str2 = calloc(str_half, sizeof(char)); 	
		
		strncpy(str1, buff           , str_half);
		strncpy(str2, &buff[str_half], str_half); 
		
		tmp = charcmp(str1, str2, str_half);
		
		score +=  ascii_offset(tmp);
		group_score += badge_calculation(buff, str_length);

		free(str1);
		free(str2); 	
	}

	printf("Solution 1 %d\n", score);
	printf("Solution 2 %d\n", group_score);
	return 0; 
}
