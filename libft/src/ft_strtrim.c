/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:40:56 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/06 17:56:16 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_makecopy(char const *s1, int beg, int end)
{
	char	*cpy;
	int		i;
	int		size;

	size = end - beg + 1;
	if (beg > end)
		cpy = malloc(1);
	else
		cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (size-- && beg <= end)
		*(cpy + i++) = *(s1 + beg++);
	*(cpy + i) = '\0';
	return (cpy);
}

static int	ft_isinset(char const *set, const char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;

	if (!s1)
		return (NULL);
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (ft_isinset(set, *(s1 + beg)))
		beg++;
	while (ft_isinset(set, *(s1 + end)) && end)
		end--;
	return (ft_makecopy(s1, beg, end));
}
