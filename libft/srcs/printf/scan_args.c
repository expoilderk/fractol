/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 01:07:06 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 17:37:27 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	scan_args(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		count += print_nbr(va_arg(args, int));
	else if (format == 'u')
		count += print_ui(va_arg(args, unsigned int));
	else if (format == 'p')
		count += print_pointer(va_arg(args, void *), HEX_LOW);
	else if (format == 'x')
		count += print_hexa(va_arg(args, unsigned int), HEX_LOW);
	else if (format == 'X')
		count += print_hexa(va_arg(args, unsigned int), HEX_UPPER);
	else if (format == '%')
		count += print_char('%');
	return (count);
}
