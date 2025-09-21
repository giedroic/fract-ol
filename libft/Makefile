# Makefile for libft library module #

CFLAGS = -Wall -Wextra -Werror -I include

ARFLAGS = rcs

MKDIR = mkdir -p
RMDIR = rm -rf

LIBC = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
	ft_strlen ft_toupper ft_tolower ft_strchr ft_strrchr \
	ft_strncmp ft_calloc ft_strdup ft_atoi ft_memchr ft_memcmp \
	ft_strnstr ft_memset ft_bzero ft_memcpy ft_memmove \
	ft_strlcpy ft_strlcat

ADDITIONAL = ft_substr ft_strjoin ft_strtrim ft_split ft_itoa \
		ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd \
		ft_putendl_fd ft_putnbr_fd

BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
	ft_lstadd_back ft_lstdelone ft_lstclear \
	ft_lstiter ft_lstmap

FT_PRINTF = ft_printf ft_printf_utils

GET_NEXT_LINE = get_next_line

OBJ_DIR = obj/

OBJECT = $(LIBC) $(ADDITIONAL) $(BONUS) $(FT_PRINTF) $(GET_NEXT_LINE)
OBJECT := $(addprefix obj/,$(OBJECT))
OBJECT := $(addsuffix .o,$(OBJECT))

INCLUDE = $(LIBC) $(ADDITIONAL) $(BONUS) ft_printf get_next_line libft
INCLUDE := $(addprefix include/,$(INCLUDE))
INCLUDE := $(addsuffix .h,$(INCLUDE))

NAME = libft.a

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJECT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECT)

obj/%.o : src/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	$(MKDIR) $@

clean :
	$(RM) $(OBJECT)
	$(RMDIR) $(OBJ_DIR)

fclean :
	$(RM) $(NAME) $(OBJECT)
	$(RMDIR) $(OBJ_DIR)

re : fclean all
