/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:23:51 by abaur             #+#    #+#             */
/*   Updated: 2019/11/26 14:20:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int			ft_vprintf(const char *format, va_list args);
int			ft_printf(const char *format, ...);

/*
** Internals
*/

typedef struct s_pftag	t_pftag;
typedef int	(*t_writer)(t_pftag*, va_list);

struct		s_pftag
{
	const char		*src;
	char			*buffer;
	char			*lcursor;
	char			*rcursor;

	char			type;
	t_writer		writer;

	int				padsize;

	unsigned short	sharped: 1;
	unsigned short	minused: 1;
	unsigned short	plused : 1;
	unsigned short	spaced : 1;
	unsigned short	zeroed : 1;
};

void		parsetag(const char **format, t_pftag *tag);

void		initbuffer(t_pftag *tag);
int			writeleft(t_pftag *tag, char c);
int			writeright(t_pftag *tag, char c);
int			flushtag(t_pftag *tag);

int			w_string(t_pftag *tag, va_list args);
int			w_character(t_pftag *tag, va_list args);

#endif
