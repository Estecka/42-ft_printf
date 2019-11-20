/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:50:25 by abaur             #+#    #+#             */
/*   Updated: 2019/11/21 13:04:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <unistd.h>
#include <stdarg.h>

/*
** Detects the correct tag format to use and prints it.
** Moves `format` forward until the end of the current tag.
** Moves `args` forward as required.
** Return the amount of characters printed for this tag.
*/

static int	printtag(const char **format, va_list args)
{
	(void)args;
	(*format)++;
	if (**format == '%')
	{
		write(1, *format, 1);
		return (1);
	}
	else if (**format)
	{
		// Do the thing
		// return (the thing);
	}
	return (0);
}

/*
** Prints the arguments formatted with the given string.
** Returns the amount of characters printed.
*/

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int		pass;

	va_start(args, format);
	if (!format)
		return (0);
	result = 0;
	pass = 1;
	while (pass > 0)
	{
		pass = 0;
		while (*format && *format != '%')
		{
			write(1, format, 1);
			pass += 1;
			format++;
		}
		pass = printtag(&format, args);
		result += pass;
		format++;
	}
	va_end(args);
	return (result);
}
