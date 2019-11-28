/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_intbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:58:44 by abaur             #+#    #+#             */
/*   Updated: 2019/11/28 12:44:22 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

static int	intbaserec(t_pftag *tag, int value, const char *base, int dozen)
{
	int		digit;
	char	c;
	int		result;

	result = 0;
	if (value <= -dozen || dozen <= value)
		result += intbaserec(tag, value / dozen, base, dozen);
	digit = (value < 0) ? -(value % dozen) : (value % dozen);
	c = base[digit];
	result += tag->printer(tag, c);
	return (result);
}

static int	uintbaserec(t_pftag *tag, t_uint value, const char *base, int dozen)
{
	int				digit;
	char			c;
	int				result;

	result = 0;
	if ((unsigned int)dozen <= value)
		result += uintbaserec(tag, value / dozen, base, dozen);
	digit = value % dozen;
	c = base[digit];
	result += tag->printer(tag, c);
	return (result);
}

int			w_intbase(t_pftag *tag, va_list args, const char *base, short uint)
{
	int arg;
	int	result;

	result = 0;
	arg = va_arg(args, int);
	initbuffer(tag);
	if (!uint && arg < 0)
		tag->printer(tag, '-');
	if (uint)
		result += uintbaserec(tag, (unsigned int)arg, base, ft_strlen(base));
	else
		result += intbaserec(tag, arg, base, ft_strlen(base));
	result += flushtag(tag);
	return (result);
}
