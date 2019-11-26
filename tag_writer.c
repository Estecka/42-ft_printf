/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:49:56 by abaur             #+#    #+#             */
/*   Updated: 2019/11/26 11:29:33 by abaur            ###   ########.fr       */
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
	tag->lcursor = tag->buffer + (size - 1);
	tag->rcursor = tag->buffer;
}

/*
** Prints the tag's buffer on screen, and discards it.
*/

void				flushtag(t_pftag *tag)
{
	char *cursor;

	cursor = tag->buffer;
	if (cursor)
	{
		while (*cursor)
			write(1, cursor++, 1);
		free(tag->buffer);
		tag->buffer = NULL;
		tag->lcursor = NULL;
		tag->rcursor = NULL;
	}
}

/*
** Checks whether the tag's buffer needs to be flushed.
*/

static inline void	autoflush(t_pftag *tag)
{
	if (tag->rcursor < tag->lcursor)
		flushtag(tag);
}

/*
** Stages a character for writting into the left hand side of the tag's buffer.
** Behaviour is undefined if `writeright` was already called.
** Automatically flushes the buffer when full.
*/

void				writeleft(t_pftag *tag, char c)
{
	if (!tag->lcursor)
		return (void)write(1, &c, 1);
	*tag->lcursor = c;
	tag->lcursor++;
	autoflush(tag);
}

/*
** Stages a character for writting into the right hand side of tag's buffer.
** Every previously written caracters are nudged to the left.
** Automatically flushes the buffer when full.
*/

void				writeright(t_pftag *tag, char c)
{
	char	*cursor;

	if (!tag->rcursor)
		return (void)write(1, &c, 1);
	cursor = tag->rcursor;
	while (*(cursor + 1))
	{
		*cursor = *(cursor + 1);
		cursor++;
	}
	*cursor = c;
	tag->rcursor--;
	autoflush(tag);
}
