NAME = fractol

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

MLX42_DIR = MLX42

MLX42_BUILD_DIR = $(MLX42_DIR)/build

RM = rm -rf

SRC = main.c draw_and_calculate.c fractol_utils.c \

OBJS = $(SRC:.c=.o)

MLX_FLAGS = -L$(MLX42_BUILD_DIR) -l mlx42 -ldl -lglfw -pthread -lm


all: $(NAME)

$(NAME): $(OBJS)
	@echo "${CIAN}Compiling...${NC}"
	cmake -S $(MLX42_DIR) -B $(MLX42_BUILD_DIR)
	$(MAKE) -C $(MLX42_BUILD_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -Ilib/MLX42/include/MLX42 -o $(NAME)
	@echo "${LGREEN}Program compiled✅${NC}"


clean : 
	@$(RM) $(MLX42_BUILD_DIR) 
	@$(RM) $(OBJS)
	@echo "${MAGENTA}Objects deleted🧹${NC}"

fclean : clean
	@$(RM) $(NAME)
	@echo "${MAGENTA}All clean✨${NC}"

re: fclean all

.PHONY: all clean fclean re


