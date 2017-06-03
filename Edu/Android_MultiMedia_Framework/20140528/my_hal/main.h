
int  my_atoi(char *buff);
void  my_add(int *value);

struct device_t
{
	int   (*atoi)(char *);
	void  (*add)(int *);
};
