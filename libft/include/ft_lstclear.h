/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:53:56 by agiedroi          #+#    #+#             */
/*   Updated: 2025/08/30 14:53:58 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTCLEAR_H
# define FT_LSTCLEAR_H
# include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*));
#endif
