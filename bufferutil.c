/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufferutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:46:02 by abaur             #+#    #+#             */
/*   Updated: 2019/12/02 17:34:06 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"
#include "bufferutil.h"

static inline int	autoflush(t_buffer *buffer)
{
	if (buffer->rcursor < buffer->lcursor)
		return (flushbuffer(buffer));
	else
		return (0);
}

t_buffer 			*newbuffer(size_t capacity, char content)
{
	t_buffer	*buffer;
	char		*cursor;

	buffer = malloc(sizeof(t_buffer) + ((capacity + 1) * sizeof(char)));
	if (!buffer)
		return (NULL);
	buffer->capacity = capacity;
	buffer->flushmethod = ft_putchar;
	buffer->content = capacity ? (char*)(&buffer[1]) : NULL;
	buffer->lcursor = buffer->content;
	buffer->rcursor = &buffer->content[capacity];
	ft_memset(buffer->content, capacity, content);
	buffer->content[capacity] = '\0';
	return (buffer);
}

int					flushbuffer(t_buffer *buffer)
{
	int		result;
	size_t	i;

	if (!buffer->capacity)
		return (0);
	i = 0;
	while (i < buffer->capacity)
	{
		buffer->flushmethod(buffer->content[i]);
		i++;
	}
	buffer->capacity = 0;
	buffer->content = NULL;
	buffer->lcursor = NULL;
	buffer->rcursor = NULL;
	ft_bzero(buffer->content, buffer->capacity);
	return (result);
}

int					buffaddl(t_buffer *buffer, char value)
{
	if (!buffer->lcursor)
	{
		buffer->flushmethod(value);
		return (1);
	}
	*buffer->lcursor = value;
	buffer->lcursor++;
	return (autoflush(buffer));
}

int					buffaddr(t_buffer *buffer, char value)
{
	char	*cursor;

	if (!buffer->rcursor)
	{
		buffer->flushmethod(value);
		return (1);
	}
	cursor = buffer->rcursor;
	buffer->rcursor--;
	while (*(cursor + 1))
	{
		*cursor = *(cursor + 1);
		cursor++;
	}
	*cursor = value;
	return (autoflush(buffer));
}
