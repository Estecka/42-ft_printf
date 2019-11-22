/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:33:49 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 15:30:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#include <unistd.h>

/*
** Default writer for invalid tags.
*/

static int	w_unsupported(t_pftag *tag, va_list args)
{
	(void)args;
	write(1, tag->src, 1);
	return (1);
}

/*
** Returns the appropriate method to write the given tag type.
**
** The returned method's prototype will is `int (t_pftag*, va_list)`
** It moves the va_list forward as required by the tag,
** and returns the amount of characters printed.
** NULL is returned if the tag type is not supported.
*/

static t_writer	pickwriter(t_pftag *tag)
{
	(void)tag;
	return (NULL);
}

/*
** Parses the `#-+ 0' section of the tag.
** Alters the given tag and moves the cursor forward accordingly.
*/

static void	parseprefix(t_pftag *tag, const char **src)
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
		else
			return ;
		(*src)++;
	}
}

/*
** Parses the pad-size and type section of the tag.
** Alters the given tag and moves the cursor forward accordingly.
*/

static void	parsesuffix(t_pftag *tag, const char **src)
{
	while (ft_isdigit(**src))
	{
		tag->padsize *= 10;
		tag->padsize += **src - '0';
		(*src)++;
	}
	tag->type = **src;
	if (**src)
		(*src)++;
}

/*
** Builds a pftag object after the given string.
** Moves `src` forward until the first caracter after the tag.
** If the tag is invalid, `src` is only moved by one.
*/

void		parsetag(const char **src, t_pftag *tag)
{
	ft_bzero(tag, sizeof(t_pftag));
	tag->src = *src;
	parseprefix(tag, src);
	parsesuffix(tag, src);
	tag->writer = pickwriter(tag);
	if (!tag->writer)
	{
		tag->writer = w_unsupported;
		tag->type = 0;
		*src = tag->src + 1;
	}
}
