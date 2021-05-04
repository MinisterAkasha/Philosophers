NAME = philo_one
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./Includes
C_FILES = main.c \
		validate_arguments.c \
		utils.c \
		init.c \
		free.c \
		create_threads.c \
		write_message.c

OBJDIR = ./src/obj
OBJ = $(C_FILES:%.c=%.o)
O_FILES = $(addprefix $(OBJDIR)/, $(OBJ))

SRC_PATHS = ./src

vpath %.c $(SRC_PATHS)
vpath %.o $(OBJDIR)
vpath %.h $(INCLUDE)

#Tools to edit text
GREEN = \033[1;92m
YELLOW = \033[3;93m
BLUE = \033[3;34m
TEXT_RESET = \033[0;0m

.PHONY: all clean fclean re 

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -I$(INCLUDE) $(O_FILES) -o $@
	@echo "$(GREEN)Success!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

%.o: %.c $(INCLUDE)
	@echo "$(BLUE)Compiling $<"
	@$(CC) -I$(INCLUDE) -c $< -o $(OBJDIR)/$@

clean:
	@echo "$(TEXT_RESET)"
	@rm -rf $(OBJDIR) ./Includes/*.h.gch
	@echo "$(YELLOW)Delete 'o' files"

fclean: clean
	@echo "$(TEXT_RESET)"
	@rm -f $(NAME)
	@echo "$(YELLOW)Delete the binary file '$(NAME)'"
	@echo

re: fclean all