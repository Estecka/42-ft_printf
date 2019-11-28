/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:50:38 by abaur             #+#    #+#             */
/*   Updated: 2019/11/28 12:39:08 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	w_deci(t_pftag *tag, va_list args)
{
	return (w_intbase(tag, args, "0123456789", 0));
}

int	w_udeci(t_pftag *tag, va_list args)
{
	return (w_intbase(tag, args, "0123456789", 1));
}

int	w_octa(t_pftag *tag, va_list args)
{
	return (w_intbase(tag, args, "01234567", 1));
}

int	w_hexa(t_pftag *tag, va_list args)
{
	return (w_intbase(tag, args, "0123456789abcdef", 1));
}

int	w_hexaup(t_pftag *tag, va_list args)
{
	return (w_intbase(tag, args, "0123456789ABCDEF", 1));
}
