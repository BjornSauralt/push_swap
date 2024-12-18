NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= ./include/
SRC_DIR				= ./src/
OBJ_DIR				= ./obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I$(INC)
RM					= rm -f

# Source Files
PUSH_SWAP_FILE		=	swap_push_commands.c \
                		a_to_b.c \
                		b_to_a.c \
                		init.c \
                		main.c \
                		move.c \
                		push_and_swap.c \
                		reverse_rotate.c \
                		rotate.c \
                		tri.c \
                		utils.c \
                		verif.c

# Full paths for source files and object files
SRCS 				= $(addprefix $(SRC_DIR), $(PUSH_SWAP_FILE))
OBJS 				= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Build rules
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) compiled successfully."

# Rule to compile each .c file to its corresponding .o file
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

# Rule to build the libft library
$(LIBFT):
	@make -C ./libft
	@echo "Libft compiled successfully."

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft
	@echo "Cleaned object files."

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./libft
	@echo "Full clean completed."

re: fclean all

# Phony targets
.PHONY: all clean fclean re