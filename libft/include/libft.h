/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:02:02 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/29 19:08:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** ERROR_PRINTING_MODE:
** 0 (STD_MODE): standard mode
** 1 (DEBUG_MODE): debug mode, with non-compliant messages
** --> has to be put on 0 before pushing the project!!
** colors can be combined: "\033[41;4;32m"
*/

# ifndef NULL
#  define NULL					((void *)0)
# endif

/*
** I/O define
*/
# define STDIN					0
# define STDOUT					1
# define STDERR					2

/*
** Boolean flags
*/
# define TRUE					1
# define FALSE					0

# define ERROR_PRINTING_MODE	1

# define COL_RESET				"\033[0m"
# define COL_UNDERLINED			"\033[4m"
# define COL_REVERSE			"\033[7m"
# define COL_BLACK				"\033[22;30m"
# define COL_RED				"\033[22;31m"
# define COL_GREEN				"\033[22;32m"
# define COL_YELLOW				"\033[22;33m"
# define COL_BLUE				"\033[22;34m"
# define COL_MAGENTA			"\033[22;35m"
# define COL_CYAN				"\033[22;36m"
# define COL_WHITE				"\033[1;37m"
# define COL_GRAY				"\033[1;30m"
# define COL_LIGHT_GRAY			"\033[22;37m"
# define COL_LIGHT_RED			"\033[1;31m"
# define COL_LIGHT_GREEN		"\033[1;32m"
# define COL_LIGHT_YELLOW		"\033[1;33m"
# define COL_LIGHT_BLUE			"\033[1;34m"
# define COL_LIGHT_MAGENTA		"\033[1;35m"
# define COL_LIGHT_CYAN			"\033[1;36m"
# define COL_BACK_RED			"\033[41m"
# define COL_BACK_GREEN			"\033[42m"
# define COL_BACK_YELLOW		"\033[43m"
# define COL_BACK_BLUE			"\033[44m"
# define COL_BACK_MAGENTA		"\033[45m"
# define COL_BACK_CYAN			"\033[46m"

/*
** ERROR(s1, s2, st, rt, fd):
** error string s1, error string s2 (optional), status of error (STD, DEBUG),
** return value, fildes to print on;
** use the DEBUG macro for a simple use:
** DEBUG by default puts a DEBUG_MODE status, returns -1 and prints on sdout
*/

# define E1(x)				err1(x, __FILE__, __func__, __LINE__)
# define ERR_I(s1, s2, st, rt, fd)	ft_err_i(E1(err2(s1, s2, st)), rt, fd)
# define ERR_P(s1, s2, st, rt, fd)	ft_err_p(E1(err2(s1, s2, st)), rt, fd)
# define DEBUG_END			__FILE__, __func__, __LINE__), EXIT_FAILURE, 1
# define DBG_I(s1, s2)		ft_err_i(err1(err2(s1, s2, DEBUG_MODE), DEBUG_END)
# define DBG_P(s1, s2)		ft_err_p(err1(err2(s1, s2, DEBUG_MODE), DEBUG_END)

/*
** ft_gnl: handles multiple fd at the same time
** 1024 seems to be the best trade-off nb of read/buffer size
*/

# define BUF_SIZE			1024
# define MALLOC_SIZE		65536
# define MAX_FD				512

typedef struct s_buf		t_buf;

struct		s_buf
{
	char			buf[BUF_SIZE + 1];
	size_t			buf_len;
	char			*rem;
	size_t			rem_len;
	size_t			malloc_size;
	size_t			search_index;
	char			is_init;
};

enum		e_err_status
{
	DEBUG_MODE = 0,
	STD_MODE = 1
};
# undef false
# undef true

enum		e_bool
{
	false = 0,
	true = 1
};

typedef struct s_list		t_list;
typedef struct s_error		t_error;
typedef enum e_err_status	t_err_status;
typedef enum e_bool			t_bool;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
	t_list	*prev;
};

struct		s_error
{
	const char		*msg1;
	const char		*msg2;
	t_err_status	status;
	const char		*file;
	const char		*func;
	int				line;
};

/*
** ft_memset.c
*/

void		*ft_memset(void *str, int chr, size_t n);
void		ft_bzero(void *str, size_t n);

/*
** ft_memcpy.c
*/

void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);

/*
** ft_mem_misc.c
*/

void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);

/*
** ft_map_iter.c
*/

void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char(*f)(unsigned int, char));

/*
** ft_str...
*/

char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		**ft_strsplit_str(char const *s1, char const *s2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrev(char *s);
size_t		ft_strlen(const char *str);

/*
** ft_strcpy.c / ft_strdup.c
*/

char		*ft_strncpy(char *str1, const char *str2, size_t len);
char		*ft_strcpy(char *str1, const char *str2);
char		*ft_strdup(const char *s1);

/*
** ft_strcat.c
*/

char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strchr.c
*/

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);

/*
** ft_strchr.c
*/

char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);

/*
** ft_print.c / ft_print_fd.c
*/

void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_puttab(char const **ss);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_puttab_fd(char const **ss, int fd);

/*
** ft_color.c
*/

void		ft_putstr_color(char const *s, char const *color);
void		ft_putstr_color_fd(char const *s, char const *color, int fd);
void		ft_color_switch_fd(char const *color, int fd);
void		ft_color_std_fd(int fd);

/*
** ft_error.c
*/

t_error		*err1(t_error *error, const char *file, const char *func, int line);
t_error		*err2(char *msg1, char *msg2, t_err_status status);
int			ft_err_i(t_error *err, int ret_value, int fd);
void		*ft_err_p(t_error *err, void *ret_value, int fd);

/*
** ft_minmax.c
*/

size_t		ft_min(size_t a, size_t b);
size_t		ft_max(size_t a, size_t b);
float		ft_min_float(float a, float b);
float		ft_max_float(float a, float b);

/*
** ft_is.c / ft_to.c
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
** ft_list1.c
*/

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
** ft_list2.c
*/

void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstadd_back(t_list **root, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** misc
*/

size_t		pow_a(int a, int b);
void		*ft_memalloc(size_t size);
void		*ft_realloc(void *ptr, size_t size);
int			get_next_line(int fd, char **line);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		ft_itoatab(int nbr, char *tab);
void		ft_qsort(int tab[], int beg, int end);

#endif
