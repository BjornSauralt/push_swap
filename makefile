NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

#FICHIERS ICI FDP
COMMANDS_DIR		=	$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/push_and_swap.c \
						$(SRC_DIR)commands/push_swap_commands.c \
						$(SRC_DIR)commands/reverse_rotate.c \

ALGORITHM_DIR		=	$(SRC_DIR)algorithm/init.c \
						$(SRC_DIR)algorithm/main.c \
						$(SRC_DIR)algorithm/tri.c \
						$(SRC_DIR)algorithm/utils.c \
						$(SRC_DIR)algorithm/free_error.c \
						$(SRC_DIR)algorithm/set.c \
						$(SRC_DIR)algorithm/ft_split.c \
						$(SRC_DIR)algorithm/init_add.c \
						$(SRC_DIR)algorithm/move.c \

SRCS 				= $(COMMANDS_DIR) $(ALGORITHM_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re


		
		
		
		
		

        
        
        
        
        
		
