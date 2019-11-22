/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tag_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:33:49 by abaur             #+#    #+#             */
/*   Updated: 2019/11/22 11:46:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
** Builds a pftag object after the given string.
** Moves `src` forward until the end of the tag.
** If the tag is invalid, `src` is only moved by one.
*/

void	parsetag(const char **src, t_pftag *tag)
{
	char	*supported;

	supported = "s";
	ft_bzero(tag, sizeof(t_pftag));
	tag->type = ft_strcontain(supported, **src) ? **src : 0;
	(*src)++;
}
