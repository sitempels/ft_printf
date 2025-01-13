
#include <stdarg.h>
#include <stdio.h>

/*char	cast_func(void *a)
{
	char	b;

	b = (char) a;
	return (b);
}
int	cast_int(void *a)
{
	int	b;

	b = (int) a;
	return (b);
}


int	testarg(const char *format, ...)
{
	va_list	arg;
	char	*ar1;
	char	argument;
	int		ar2;
	char	ar3;
	int		(*get_int)();

	get_int = cast_int;
	argument = '3';
	va_start(arg, format);
	ar1 = (char *) va_arg(arg, void *);
	ar2 =  get_int(va_arg(arg, void *), argument);
	ar3 =  cast_func(va_arg(arg, void *));
	printf("%s \n", ar1);
	printf("%d \n", ar2);
	printf("%c \n", ar3);
	va_end(arg);
	return (0);
}*/
int	testarg(int test)
{
	printf("%d\n", test);
	return (1);
}

int	testvarg(const char *str, ...)
{
	va_list	arg;

	va_start(arg, str);
	testarg(va_arg(arg, int));
	va_end (arg);
	return (1);
}

int	main(void)
{
	testvarg("test", 999LL);
	return (0);
}
