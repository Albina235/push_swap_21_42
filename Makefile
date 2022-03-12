NAME = push_swap

SRCS = src/push_swap.c	src/errors.c	src/median.c\
		src/sort_b_five.c	src/sort_big_second.c\
		src/sort_big.c	src/sort_five_three.c\
		src/function/push.c src/function/reverse_rotate.c\
		src/function/rotate.c src/function/swap.c\
		src/parser/bouble_sort.c src/parser/parser_add.c\
		src/parser/parser_check.c src/parser/parser_init.c

OBJ = ${SRCS:%.c=%.o}

LIB = libft/libft.a

CCF = gcc -Wall -Werror -Wextra

RM = rm - rf

INCLUDE = src/

HEADER = push_swap.h

.PHONY : all clean fclean re bonus libft

all	:	libft ${NAME}

libft	:	
			@$(MAKE) -C libft/

${NAME}	:	${OBJ}
			@echo	"Compilation of ${NAME}"
			@${CCF} ${OBJ} ${LIB} -o ${NAME}
			@echo "\n Completed $(NAME)\n"

%.o	: %.c	${INCLUDE}${HEADER}
			@${CCF} -c $< -o $@ -I ${INCLUDE}
clean:
			@$(RM) ${OBJ}
			@$(MAKE) -C libft/ clean
			@echo "\nCleaning done\n"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)
			@echo "\tAll files were deleted\n"

re:			fclean all
			@echo "\tRemake done\n"
