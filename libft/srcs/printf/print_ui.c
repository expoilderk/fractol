/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:43:28 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 17:37:18 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_ui(unsigned int nb)
{
	char			arr[15];
	unsigned int	temp;
	int				size;
	int				count;

	size = 0;
	count = 0;
	if (nb == 0)
		count += print_char('0');
	temp = nb;
	while (temp > 0)
	{
		arr[size++] = temp % 10 + '0';
		temp /= 10;
	}
	size--;
	while (size >= 0)
		count += print_char(arr[size--]);
	return (count);
}
