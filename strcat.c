#include <stdio.h>

char *_strcat(char *dest, char *source)
{
	char *des = dest;

    	while (*des != '\0')
    	{
		des++;
    	}	

	while (*source != '\0')
	{
		*des = *source;
		des++;
		source++;
    	}	
    
	*des = '\0';

	return (dest);
}
