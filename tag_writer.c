/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:49:56 by abaur             #+#    #+#             */
/*   Updated: 2019/11/21 16:40:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

/*
** Default writer for invalid tags.
*/

static int	w_unsupported(t_pftag tag, va_list args)
{
	(void)args;
	write(1, &tag.type, 1);
	return (1);
}

/*
** Returns the appropriate method to write the given tag.
**
** The returned method's prototype will is `int (t_pftag, va_list)`
** It moves the va_list forward as required by the tag,
** and returns the amount of characters printed.
*/

t_writer	pickwriter(t_pftag tag)
{
	(void)tag;
	return (w_unsupported);
}
