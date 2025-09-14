/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 02:38:07 by agiedroi          #+#    #+#             */
/*   Updated: 2025/01/08 23:24:38 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*value;

	if (((int)nmemb < 0 && (int)size < 0) || (int)(nmemb * size) < 0)
		return (NULL);
	value = malloc(size * nmemb);
	if (value)
		ft_bzero(value, nmemb * size);
	return (value);
}
