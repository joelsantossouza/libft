/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:49:08 by joesanto          #+#    #+#             */
/*   Updated: 2025/10/24 19:19:00 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static size_t	ft_min(size_t n1, size_t n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	new = 0;
	if (new_size)
		new = ft_memcpy(malloc(new_size), ptr, ft_min(old_size, new_size));
	free(ptr);
	return (new);
}
