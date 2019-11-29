/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_unsupported.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:57:11 by abaur             #+#    #+#             */
/*   Updated: 2019/11/29 20:41:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "ft_printf.h"

int		w_unsupported(t_pftag *tag)
{
	write(1, tag->src, 1);
	return (1);
}
