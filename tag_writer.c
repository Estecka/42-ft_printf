/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:49:56 by abaur             #+#    #+#             */
/*   Updated: 2019/11/26 12:55:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"
#include "ft_printf.h"

/*
** Initializes the buffer of the given tag.
*/

void				initbuffer(t_pftag *tag)
{
	int	size;

	size = tag->padsize;
	if (tag->padsize < 1)
		return ;
	tag->buffer = malloc(1 + size);
	if (!tag->buffer)
		return ;
	ft_memset(tag->buffer, tag->zeroed ? '0' : ' ', size);
	tag->buffer[size] = '\0';
	tag->rcursor = tag->buffer + (size - 1);
	tag->lcursor = tag->buffer;
}

/*
** Prints the tag's buffer on screen, and discards it.
** Returns the amount of characters flushed.
*/

int					flushtag(t_pftag *tag)
{
	int		result;
	char	*cursor;

	result = 0;
	cursor = tag->buffer;
	if (cursor)
	{
		while (*cursor)
		{
			write(1, cursor++, 1);
			result += 1;
		}
		free(tag->buffer);
		tag->buffer = NULL;
		tag->lcursor = NULL;
		tag->rcursor = NULL;
	}
	return (result);
}

/*
** Checks whether the tag's buffer needs to be flushed.
** Returns the amount of characters that were flushed.
*/

static inline int	autoflush(t_pftag *tag)
{
	if (tag->rcursor < tag->lcursor)
		return (flushtag(tag));
	return (0);
}

/*
** Stages a character for writting into the left hand side of the tag's buffer.
** Behaviour is undefined if `writeright` was already called.
** Automatically flushes the buffer when full;
** Returns the amount of characters that were flushed.
*/

int					writeleft(t_pftag *tag, char c)
{
	if (!tag->lcursor)
	{
		write(1, &c, 1);
		return (1);
	}
	*tag->lcursor = c;
	tag->lcursor++;
	return (autoflush(tag));
}

/*
** Stages a character for writting into the right hand side of tag's buffer.
** Every previously written caracters are nudged to the left.
** Automatically flushes the buffer when full;
** Returns the amount of characters that were flushed.
*/

int					writeright(t_pftag *tag, char c)
{
	char	*cursor;

	if (!tag->rcursor)
	{
		write(1, &c, 1);
		return (1);
	}
	cursor = tag->rcursor;
	while (*(cursor + 1))
	{
		*cursor = *(cursor + 1);
		cursor++;
	}
	*cursor = c;
	tag->rcursor--;
	return (autoflush(tag));
}
