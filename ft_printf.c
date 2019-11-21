/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:50:25 by abaur             #+#    #+#             */
/*   Updated: 2019/11/21 16:37:05 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

#include <unistd.h>
#include <stdarg.h>

/*
** Prints the arguments formatted with the given string.
** Returns the amount of characters printed.
*/

int			ft_vprintf(const char *format, va_list args)
{
	int			result;
	t_pftag		tag;
	t_writer	writer;

	if (!format)
		return (0);
	result = 0;
	while (*format)
		if (*format == '%')
		{
			format++;
			tag = parsetag(&format);
			writer = pickwriter(tag);
			result += writer(tag, args);
		}
		else
		{
			write(1, format++, 1);
			result += 1;
		}
	return (result);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}
