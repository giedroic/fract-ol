/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:33:33 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/06 17:01:51 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s_new;

	if (!s)
		return (NULL);
	i = 0;
	s_new = malloc(ft_strlen(s) + 1);
	if (!s_new)
		return (NULL);
	while (*(s + i))
	{
		*(s_new + i) = f(i, *(s + i));
		i++;
	}
	*(s_new + i) = '\0';
	return (s_new);
}
