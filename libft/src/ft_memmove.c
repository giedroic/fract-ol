/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:00:53 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/05 14:29:42 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	if (!dest && !src)
		return (dest);
	s1 = dest;
	s2 = src;
	if (s2 < s1 && s1 < s2 + n)
	{
		while (n--)
			*(s1 + n) = *(s2 + n);
	}
	else
	{
		while (n--)
			*s1++ = *s2++;
	}
	return (dest);
}
