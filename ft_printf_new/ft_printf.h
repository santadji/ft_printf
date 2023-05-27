/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:51:02 by santadji          #+#    #+#             */
/*   Updated: 2023/05/27 19:03:20 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void				ft_type(va_list *args, char *str, int i, int *ret);
int					ft_printf(const char *format, ...);
void				ft_putnbr_fd_printf(int n, int fd, int *ret);
void				ft_putnbr_fd_unsigned_printf(unsigned int n, int fd, int *ret);
void				ft_putchar_fd_printf(char c, int fd, int *ret);
void				ft_putstr_fd_printf(char *s, int fd, int *ret);
void				ft_printmod(va_list *args, char *str, int *i, int *ret);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *str);
char				*ft_itoa_base(unsigned int n, char *base);

#endif
