
#include <stdio.h>
#include <stdarg.h>

char	*testvariadic(const char *str, ...)
{
	va_list	arg;

	va_start(arg, str);
	printf("%d\n", va_arg(arg, int));
	printf("%s\n", va_arg(arg, char *));
	printf("%c\n", va_arg(arg, char));
	printf("%d\n", va_arg(arg, int));
	printf("%d\n", va_arg(arg, int));

	return (0);
}	
int main()
{
	int	a;
	
	a = 4643;
	testvariadic("zgzz", a, "4373", 'z', "agasg", "agag");
	return (0);
}
