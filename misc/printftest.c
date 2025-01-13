#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%YY Y %% %d % \n", (int)546);
	printf("%d\n", printf("%p, %p\n", LONG_MIN, LONG_MAX));
	printf("%d\n", printf("%p, %p\n", ULONG_MAX, -ULONG_MAX));

	return (0);
}
