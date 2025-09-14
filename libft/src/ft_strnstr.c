/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:19:52 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/04 16:04:16 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (!len)
		return (NULL);
	i = 0;
	while (*big && i < len)
	{
		j = 0;
		while (*(big + j) == *(little + j) && *(little + j))
			j++;
		if (!(*(little + j)) && i + j <= len)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
