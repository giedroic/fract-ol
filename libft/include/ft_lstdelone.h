/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiedroi <agiedroi@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:54:03 by agiedroi          #+#    #+#             */
/*   Updated: 2025/08/30 14:54:05 by agiedroi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTDELONE_H
# define FT_LSTDELONE_H
# include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*));
#endif
