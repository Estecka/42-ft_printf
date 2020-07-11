/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:43:58 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 16:43:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "ft_printf.h"

int	ft_vprintfc(int colour, short bold, const char *format, va_list args)
{
	int r;

	r =
		ft_printf("\033[%d;%dm", bold ? 1 : 0, colour)
		+ ft_vprintf(format, args)
		+ write(0, "\033[0m", 5)
		;
	va_end(args);
	return (r);
}

int	ft_printfc(int colour, short bold, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	return (ft_vprintfc(colour, bold, format, args));
}
