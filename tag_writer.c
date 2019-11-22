/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:49:56 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 17:16:32 by abaur            ###   ########.fr       */
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

void	initbuffer(t_pftag *tag)
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
	tag->cursor = &tag->buffer[size - 1];
	tag->limit = tag->buffer;
}

/*
** Prints the tag's buffer on screen, and discards it.
*/

void	flushtag(t_pftag *tag)
{
	char *cursor;

	cursor = tag->buffer;
	if (cursor)
	{
		while (*cursor)
			write(1, cursor++, 1);
		free(tag->buffer);
		tag->buffer = NULL;
		tag->limit = NULL;
		tag->cursor = NULL;
	}
}

/*
** Stages the given prefix into the tag's buffer.
** Automatically flushes the buffer when full.
** Behaviour is undefined if data was already sent written to the tag.
*/

void	prefixtotag(t_pftag *tag, const char *prefix)
{
	int		i;
	char	*buffer;

	buffer = tag->buffer;
	if (!buffer)
		return (void)ft_putstr_fd(prefix, 1);
	i = 0;
	while (buffer[i] && prefix[i])
	{
		buffer[i] = prefix[i];
		i++;
	}
	if (!buffer[i])
		flushtag(tag);
	if (prefix[i])
		ft_putstr_fd(prefix + i, 1);
}

/*
** Stages a character for writting into the tag's buffer.
** Automatically flushes the buffer when full.
*/

void	writetotag(t_pftag *tag, char c)
{
	char	*cursor;

	if (!tag->cursor)
		return (void)write(1, &c, 1);
	cursor = tag->cursor;
	while (*(cursor + 1))
	{
		*cursor = *(cursor + 1);
		cursor++;
	}
	*cursor = c;
	tag->cursor++;
	if (tag->cursor < tag->limit)
		flushtag(tag);
}
