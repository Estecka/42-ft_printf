/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logutil.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:13 by abaur             #+#    #+#             */
/*   Updated: 2020/01/03 13:47:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGUTIL_H
# define LOGUTIL_H

# include <stdarg.h>

# define CLEAR    0
# define RED     31
# define GREEN   32
# define YELLOW  33
# define BLUE    34
# define MAGENTA 35
# define CYAN    36

/*
** # define BEEP printf("Beep\n");
** # define BOOP printf("Boop\n");
*/

int	ft_printfc(int colour, short boldness, const char *format, ...);
int	ft_vprintfc(int colour, short boldness, const char *format,
	va_list arguments);

#endif
