/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:10:06 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/06 16:55:25 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int) start >= (int) ft_strlen(s))
	{
		sub = malloc(1 * sizeof(char));
		*sub = '\0';
		return (sub);
	}
	i = 0;
	if ((int) ft_strlen(s + start) < (int) len)
	{
		len = (size_t)(ft_strlen(s + start));
		sub = malloc((len + 1) * sizeof(char));
	}
	else
		sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
		*(sub + i++) = *(s++ + start);
	*(sub + i) = '\0';
	return (sub);
}
