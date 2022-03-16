# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evalorie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:18:39 by evalorie          #+#    #+#              #
#    Updated: 2021/10/20 16:38:02 by evalorie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	= 	ft_bzero.c		ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c 	ft_memset.c 	ft_strchr.c\
		 	ft_strlcat.c	ft_strlcpy.c 	ft_strlen.c\
			ft_isprint.c 	ft_atoi.c 		ft_memchr.c\
			ft_memcmp.c 	ft_memcpy.c 	ft_memmove.c\
			ft_strdup.c 	ft_strncmp.c 	ft_strnstr.c\
			ft_strrchr.c 	ft_tolower.c 	ft_toupper.c\
			ft_isdigit.c	ft_calloc.c		ft_itoa.c\
			ft_substr.c		ft_strjoin.c	ft_strtrim.c\
			ft_split.c		ft_strmapi.c	ft_striteri.c\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c\
			ft_putnbr_fd.c	get_next_line.c

SRCS_B 	= 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\

HEADER	=	libft.h

OBJ		=	${SRCS:%.c=%.o}

OBJ_B	= 	${SRCS_B:%.c=%.o}

CC 		= 	gcc

CFLAGS 	= 	-Wall -Werror -Wextra


.PHONY 	: 	all clean fclean re bonus

all 	: 	${NAME}

${NAME}	: 	${OBJ} ${HEADER}
	@ar rcs ${NAME} $?

%.o		:	%.c ${HEADER}
	@${CC} ${CFLAGS} -c $< -o $@

bonus	:	${OBJ_B}
	@ar rcs ${NAME} $?

clean 	:
	@rm -f ${OBJ} ${OBJ_B}

fclean 	: 	clean
	@rm -f ${NAME}

re		: 	fclean all
