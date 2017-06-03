#include "main.h"


struct device_t HAL = { my_atoi, my_add }; 

int  my_atoi(char *buff)
{
	int i;
	int sum=0;
	for(i=0; buff[i] != 0; i++ )
		sum = sum*10 + buff[i] - '0';  
	
	// ('1'-'0')*1000 + ('2'-'0')*100+  ('3'-'0')*10 + '4'-'0';
	return sum;
}

void  my_add(int  *value)
{
	++*value;
}
