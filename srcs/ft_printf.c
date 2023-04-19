#include "../includes/ft_printf.h"
#include <stdarg.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	pr_length;

	pr_length = 0;
	if (format == 'c')
		pr_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		pr_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		pr_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		pr_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		pr_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		pr_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		pr_length += ft_printpercent();
	return (pr_length);
}

int ft_printf(const char *format, ...)
{
   int i;
   va_list args;
   int pr_lenght;

   i = 0;
   pr_lenght = 0;
   va_start(args, format);
   while (format[i])
   {
      if (format[i] == '%')
      {
         pr_lenght += ft_formats(args, format[i + 1]);
         i++;
      }
      else
         pr_lenght += ft_printchar(format[i]);
      i++;
   }
   va_end(args);
   return (pr_lenght);
}

