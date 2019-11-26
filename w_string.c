/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:17:57 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 17:38:52 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	w_string(t_pftag *tag, va_list args)
{
	char	*arg;
	int		count;

	count = 0;
	arg = va_arg(args, char*);
	while (*arg)
	{
		writetotag(tag, *arg);
		arg++;
		count++;
	}
	return (count);
}
