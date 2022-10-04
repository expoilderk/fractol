/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreis-me <mreis-me@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:23:11 by mreis-me          #+#    #+#             */
/*   Updated: 2022/08/04 18:41:37 by mreis-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_nbrlen_ll(unsigned long long n)
{
	int	nlen;

	nlen = 0;
	if (n <= 0)
		nlen++;
	while (n != '\0')
	{
		nlen++;
		n = n / 16;
	}
	return (nlen);
}
