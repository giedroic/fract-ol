/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:54:09 by agiedroi          #+#    #+#             */
/*   Updated: 2025/08/30 14:54:10 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTITER_H
# define FT_LSTITER_H
# include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));
#endif
