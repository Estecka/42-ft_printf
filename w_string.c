/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:17:57 by abaur             #+#    #+#             */
/*   Updated: 2019/12/02 13:41:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	w_string(t_pftag *tag)
{
	char	*arg;
	int		count;

	count = 0;
	arg = (char*)tag->argument;
	initbuffer(tag);
	if (!arg)
		arg = "(null)";
	while (*arg)
	{
		count += tag->printer(tag, *arg);
		arg++;
	}
	count += flushtag(tag);
	return (count);
}
