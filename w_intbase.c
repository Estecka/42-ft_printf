/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_intbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:58:44 by abaur             #+#    #+#             */
/*   Updated: 2019/12/03 12:02:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_ulong		subcast(unsigned long value, char type)
{
	if (type == 'p')
		return (t_ulong)(void*)value;
	if (type == 'i' || type == 'd')
		return (long)(int)value;
	if (type == 'u' || type == 'x' || type == 'X' || type == 'o')
		return (unsigned int)value;
	return (0);
}

static int	addprefix(t_pftag *tag, long value, short uint)
{
	int	(*printer)(t_buffer*, char);
	int	count;

	count = 0;
	printer = tag->zeroed ? buffaddl : tag->printer;
	if (!uint && value < 0)
		count += printer(tag->buffer, '-');
	else if (tag->type == 'p' || (tag->type == 'x' && tag->sharped))
		count += printer(tag->buffer, '0') + printer(tag->buffer, 'x');
	else if (tag->type == 'o' && tag->sharped)
		count += printer(tag->buffer, '0');
	return (count);
}

static int	intbaserec(t_pftag *tag, long value, const char *base, int dozen)
{
	unsigned char	digit;
	int				count;

	count = 0;
	if (value <= -dozen || dozen <= value)
		count += intbaserec(tag, value / dozen, base, dozen);
	digit = base[(value < 0) ? -(value % dozen) : (value % dozen)];
	count += tag->printer(tag->buffer, digit);
	return (count);
}

static int	uintbaserec(t_pftag *tag, t_ulong value, const char *base, int ten)
{
	unsigned char	digit;
	int				count;

	count = 0;
	if ((unsigned int)ten <= value)
		count += uintbaserec(tag, value / ten, base, ten);
	digit = base[value % ten];
	count += tag->printer(tag->buffer, digit);
	return (count);
}

int			w_intbase(t_pftag *tag, const char *base, short uint)
{
	long	arg;
	int		count;

	count = 0;
	arg = tag->argument;
	arg = subcast(arg, tag->type);
	count += addprefix(tag, arg, uint);
	if (uint)
		count += uintbaserec(tag, (unsigned long)arg, base, ft_strlen(base));
	else
		count += intbaserec(tag, arg, base, ft_strlen(base));
	count += flushbuffer(tag->buffer);
	return (count);
}
