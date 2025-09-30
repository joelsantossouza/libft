/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:25:25 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/30 20:37:21 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_freearray(void **array)
{
	void	**parray;

	if (!array)
		return (0);
	parray = array;
	while (*parray)
	{
		free(*parray);
		*parray++ = 0;
	}
	free(array);
	return (0);
}
