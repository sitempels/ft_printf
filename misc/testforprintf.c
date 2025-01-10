#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*p;
	char	str[] = "Hello!";
	
	p = str;	
	printf("p: %p \n", p);
	printf("hex: %x \n", 'j');
	printf("heX: %X \n", 106);

	write(1, p, 10000000);
}
