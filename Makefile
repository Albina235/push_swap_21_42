NAME = push_swap

NAME_B = checker

SRCS = src/push_swap.c	src/errors.c	src/median.c\
		src/sort_b_five.c	src/sort_big_second.c\
		src/sort_big.c	src/sort_five_three.c\
		src/function/push.c src/function/reverse_rotate.c\
		src/function/rotate.c src/function/swap.c\
		src/parser/bouble_sort.c src/parser/parser_add.c\
		src/parser/parser_check.c src/parser/parser_init.c

OBJ = ${SRCS:%.c=%.o}

SRCS_B = src/cheker.c	src/function/push.c src/function/reverse_rotate.c\
	src/function/rotate.c src/function/swap.c\
	src/parser/bouble_sort.c src/parser/parser_add.c\
	src/parser/parser_check.c src/parser/parser_init.c	src/errors.c src/median.c

OBJ_B = ${SRCS_B:%.c=%.o}

LIB = libft/libft.a

CCF = gcc -Wall -Werror -Wextra

RM = rm -rf

INCLUDE = src/

HEADER = push_swap.h

.PHONY : all clean fclean re bonus libft

all	:	libft ${NAME}

libft	:
			@$(MAKE) -C libft/

${NAME}	:	${OBJ}
			@echo	"Compilation of ${NAME}"
			@${CCF} ${OBJ} ${LIB} -o ${NAME}
			@echo "\nCompleted $(NAME)\n"

%.o	: %.c	${INCLUDE}${HEADER}
			@${CCF} -c $< -o $@ -I ${INCLUDE}

bonus:	libft ${OBJ_B}
			@${CCF} ${OBJ_B} ${LIB} -o ${NAME_B}
clean:
			@$(RM) ${OBJ} ${OBJ_B}
			@$(MAKE) -C libft clean
			@echo "\nCleaning done\n"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "All files were deleted\n"

re:			fclean all
			@echo "Remake done\n"
