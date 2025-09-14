/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:59:22 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/04 15:21:42 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	if (!n)
		return (n);
	i = 0;
	while (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i) && --n)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
