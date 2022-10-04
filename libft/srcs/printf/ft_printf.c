/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:54:33 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 17:31:57 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		index;

	count = 0;
	index = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (ft_isargs(format[index]))
				count += scan_args(format[index], args);
		}
		else if (format[index])
			count += print_char(format[index]);
		index++;
	}
	va_end(args);
	return (count);
}
