/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joesanto <joesanto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:59:12 by joesanto          #+#    #+#             */
/*   Updated: 2025/09/28 20:17:14 by joesanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_islower(int c);
int		ft_isupper(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_stpcpy(char *dst, const char *src);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_mempcpy(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
