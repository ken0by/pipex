# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:48:57 by rofuente          #+#    #+#              #
#    Updated: 2023/08/31 12:10:59 by rofuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ./include -I ./libft/include/
DEBUG	=	-g3 -fsanitize=address

NAME	=	pipex

SS	=	pipex.c ft_utils.c ft_error.c

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(SS:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

NAME_BONUS	=	pipex_bonus

SS_BONUS	=	pipex_bonus.c ft_utils_bonus.c ft_error_bonus.c

SRC_DIR_BONUS	=	./src_bonus/

OBJ_DIR_BONUS	=	./obj_bonus/
OBJ_FILES_BONUS	=	$(SS_BONUS:.c=.o)
OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS), $(OBJ_FILES_BONUS))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

##########COLORES##########
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

##########REGLAS##########
all: $(OBJ_DIR) $(NAME)

$(LIBFT) : $(LIBFT_PATH)
	@make -sC $(LIBFT_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

bonus: $(OBJ_DIR_BONUS) $(NAME_BONUS)

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)
$(OBJ_DIR_BONUS)%.o:$(SRC_DIR_BONUS)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@make clean -sC libft
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -sC libft
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all bonus clean fclean re
