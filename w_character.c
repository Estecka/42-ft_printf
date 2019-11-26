/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_character.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:11:40 by abaur             #+#    #+#             */
/*   Updated: 2019/11/26 14:30:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	w_character(t_pftag *tag, va_list args)
{
	char	arg;
	int		result;

	result = 0;
	arg = va_arg(args, int);
	initbuffer(tag);
	result += tag->minused ?
		writeleft(tag, arg) :
		writeright(tag, arg);
	result += flushtag(tag);
	return (result);
}
