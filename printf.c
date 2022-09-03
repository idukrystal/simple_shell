#include "main.h"

/**
 * _printf - alt version of printf
 * @format: string
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int len = _strlen(format), i, tot = 0;
	char tmp;
	char *tmp_string;
	va_list args;

	va_start(args, format);
	for (i = 0; i < len; i++)
	{
		tmp = format[i];

		if (tmp == '%')
		{
			switch (format[++i])
			{
			case 'c':
				tmp = va_arg(args, int);
				break;
			case 's':
				tmp_string = va_arg(args, char*);
				tot += write(1, tmp_string, _strlen(tmp_string));
				continue;
			case 'i':
			case 'd':
				tot += print_number(va_arg(args, int));
				continue;
			}
		}
		tot += write(1, &tmp, 1);
	}
	va_end(args);
	return (tot);
}
