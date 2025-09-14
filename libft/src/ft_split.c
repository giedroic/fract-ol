/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:52:58 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/06 17:50:16 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_countelem(char const *s, char c)
{
	int	elements;

	if (!s)
		return (-1);
	elements = 0;
	while (*s)
	{
		if (*s != c)
		{
			elements++;
			while (*(s + 1) && *s != c)
				s++;
		}
		s++;
	}
	return (elements);
}

static char	**ft_mallocarray(char const *s, char c)
{
	char	**array;
	int		elements;
	int		len;
	int		i;

	elements = ft_countelem(s, c);
	array = malloc((elements + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < elements)
	{
		while (*s == c)
			s++;
		len = 0;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		*(array + i) = malloc((len + 1) * sizeof(char));
		if (!*(array + i++))
			return (NULL);
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		elements;
	int		i;
	int		j;

	array = ft_mallocarray(s, c);
	if (!array)
		return (NULL);
	elements = ft_countelem(s, c);
	i = 0;
	while (i < elements)
	{
		while (*s == c)
			s++;
		j = 0;
		while (*s && *s != c)
		{
			array[i][j] = *s++;
			j++;
		}
		array[i][j] = '\0';
		i++;
	}
	*(array + i) = NULL;
	return (array);
}
