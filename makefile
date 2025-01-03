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
						$(SRC_DIR)commands/move.c \
						$(SRC_DIR)commands/push_and_swap.c \
						$(SRC_DIR)commands/push_swap_commands.c \
						$(SRC_DIR)commands/reverse_rotate.c \

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/init.c \
						$(SRC_DIR)push_swap/main.c \
						$(SRC_DIR)push_swap/tri.c \
						$(SRC_DIR)push_swap/utils.c \
						$(SRC_DIR)push_swap/verif.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/set.c \

SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

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


		
		
		
		
		

        
        
        
        
        
		