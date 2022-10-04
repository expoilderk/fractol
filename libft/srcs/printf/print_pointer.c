/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:14:25 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 17:36:56 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_pointer(void *ptr, char *base)
{
	char				arr[20];
	unsigned long long	temp;
	int					size;
	int					count;

	size = 0;
	count = 0;
	temp = (unsigned long long)ptr;
	count += print_str("0x");
	if (temp == 0)
		count += print_str("0");
	while (temp > 0)
	{
		arr[size++] = base[temp % 16];
		temp /= 16;
	}
	size--;
	while (size >= 0)
		count += print_char(arr[size--]);
	return (count);
}
