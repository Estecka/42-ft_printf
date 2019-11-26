/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:33:49 by abaur             #+#    #+#             */
/*   Updated: 2019/11/26 11:52:35 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <unistd.h>

/*
** Default writer for invalid tags.
*/

static int		w_unsupported(t_pftag *tag, va_list args)
{
	(void)args;
	write(1, tag->src, 1);
	return (1);
}

/*
** Returns the appropriate method to write the given tag type.
**
** The returned method's prototype will be `int (t_pftag*, va_list)`
** It moves the va_list forward as required by the tag,
** and returns the amount of characters printed.
** NULL is returned if the tag type is not supported.
*/

static t_writer	pickwriter(t_pftag *tag)
{
	char c;

	c = tag->type;
	if (c == 's')
		return (w_string);
	else
		return (NULL);
}

/*
** Parses a number and sets it as the tag's padding size.
** Alters the given tag accordingly.
** Leaves the cursor onto the last digit.
*/

static void		parsepadding(t_pftag *tag, const char **src)
{
	tag->padsize = 0;
	while (ft_isdigit(**src))
	{
		tag->padsize *= 10;
		tag->padsize += **src - '0';
		(*src)++;
	}
	(*src)--;
}

/*
** Parses the `#-+ 0' section of the tag.
** Alters the given tag and moves the cursor forward accordingly.
*/

static void		parseflags(t_pftag *tag, const char **src)
{
	while (**src)
	{
		if (**src == '#')
			tag->sharped = 1;
		else if (**src == '-')
			tag->minused = 1;
		else if (**src == '+')
			tag->plused = 1;
		else if (**src == ' ')
			tag->spaced = 1;
		else if (**src == '0')
			tag->zeroed = 1;
		else if (ft_isdigit(**src))
			parsepadding(tag, src);
		else
		{
			tag->type = **src;
			if (**src)
				(*src)++;
			return ;
		}
		(*src)++;
	}
}

/*
** Builds a pftag object after the given string.
** Disable incompatible tags when applicable.
** Moves `src` forward until the first caracter after the tag.
** If the tag is invalid, `src` is only moved by one.
*/

void			parsetag(const char **src, t_pftag *tag)
{
	ft_bzero(tag, sizeof(t_pftag));
	tag->src = *src;
	parseflags(tag, src);
	if (tag->plused)
		tag->spaced = 0;
	if (tag->minused)
		tag->zeroed = 0;
	tag->writer = pickwriter(tag);
	if (!tag->writer)
	{
		tag->writer = w_unsupported;
		tag->type = 0;
		*src = tag->src + 1;
	}
}
