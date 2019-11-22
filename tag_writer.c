/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_writer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:49:56 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 14:30:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#include "ft_printf.h"

/*
** Prints the tag's buffer on screen, and discards it.
*/

void 	flushtag(t_pftag *tag)
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
** Stages a character for writting into the tag's buffer.
** Automatically flushes the buffer when full.
*/

void	writetag(t_pftag *tag, char c)
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
