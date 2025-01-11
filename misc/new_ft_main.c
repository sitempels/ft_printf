#include <stdio.h>

int	main(void)
{
	int	a;
	unsigned	b;
	long		c;
	int	*p;

	a = -1;
	b = 0;
	c = 53443434344868;
	p = &a;
	printf("%d\n%u\n%ui\n%p\n", a, b, c, p);
	return (0);
}
