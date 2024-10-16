/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:16:55 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/07 11:03:59 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
int		putulong_base(uint64_t num, const char *base_to);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putint(int nbr);
int		ft_putuint(uint32_t nbr);

#endif