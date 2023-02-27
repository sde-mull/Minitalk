CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME =	minitalk
RM =	rm -f
CD =	cd

GREEN = 	\033[0;32m
YELLOW = 	\033[0;33m
RED = 		\033[0;31m
RESET = 	\033[0m

NAME_CLIENT = client
NAME_SERVER = server
SRC_CLIENT = ft_client.c
SRC_SERVER = ft_server.c
SRCS = SRC_CLIENT SRC_SERVER
PRINTF = libft/printf
LIB_DIR = libft

all: $(NAME)

$(NAME): $(SRC_CLIENT) $(SRC_SERVER)
		@echo "$(YELLOW)[ Compiling minitalk... ] $(RESET)"
		@$(MAKE) all -C ./libft/printf
		@$(MAKE) all -C ./libft 
		@$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(LIB_DIR)/$(LIB_DIR).a $(SRC_CLIENT) -o client
		@$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(LIB_DIR)/$(LIB_DIR).a $(SRC_SERVER) -o server
		@echo "$(GREEN)[ minitalk is compiled! ] $(RESET)"

libft:
	$(MAKE) all -C ./libft

printf:
	$(MAKE) all -C ./libft/printf

clean:
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)[ Removing everything! ] $(RESET)"
	@$(CD) $(LIB_DIR)/$(PRINT_DIR) && make fclean
	@$(CD) $(LIB_DIR) && make fclean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(RED)[ Everything has been removed! ] $(RESET)"

re: fclean all

.PHONY: all printf clean fclean re