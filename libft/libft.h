/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzeikan <vzeikan@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:24:49 by vzeikan           #+#    #+#             */
/*   Updated: 2026/10/01 15:22:26 by vzeikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# define TRUE 1
# define FALSE 0

// Constants used with ft_itoa_base()
# define MAX_DIGIT_COUNT 25
# define DECIMAL "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define OCTAL "01234567"

# define FTOA_MAX_PRECISION 9
# define FTOA_BUFSIZE 35

typedef char			t_bool;
typedef unsigned char	t_byte;
typedef const t_byte	t_cbyte;
typedef unsigned int	t_uint;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//List functions defined in ft_list.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_uint	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
//List functions defined in ft_list_algo.c
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//String functions defined in ft_string.c
size_t	ft_strlen(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
//Character classification fundtions defined in ft_ctype.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
//Memory functions defined in ft_memory.c
void	*ft_memset(void *dest, int ch, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t count);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memchr(const void *ptr, int ch, size_t count);
int		ft_memcmp(const void *lhs, const void *rhs, size_t count);
//Character conversion functions defined in ft_conversion.c
int		ft_toupper(int ch);
int		ft_tolower(int ch);
int		ft_atoi(const char *src);
char	*ft_itoa(int n);
//Memory extension functions defined in ft_memory_ext.c
void	ft_bzero(void *dest, size_t count);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t count, size_t size);
//Print functions defined in ft_print.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//String algorithms defined in ft_string_algo.c
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
//String split algorithm defined in ft_split.c
char	**ft_split(const char *s, char c);
//String algorithms defined in ft_string_algo2.c
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
size_t	ft_index_of(const char *src, char ch);
//Number to string conversions defined in ft_str_conversion.c
int64_t	ft_atoi_base(const char *src, const char *base);
char	*ft_itoa_base(int64_t n, const char *base, char *buf);
char	*ft_utoa_base(uint64_t n, const char *base, char *buf);
char	*ft_ftoa(float value, int precision, char *buf);
#endif