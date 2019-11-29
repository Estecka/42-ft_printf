/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_character.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 14:11:40 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 20:38:36 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	w_character(t_pftag *tag)
{
	char	arg;
	int		result;

	result = 0;
	arg = (char)tag->argument;
	initbuffer(tag);
	result += tag->minused ?
		writeleft(tag, arg) :
		writeright(tag, arg);
	result += flushtag(tag);
	return (result);
}
