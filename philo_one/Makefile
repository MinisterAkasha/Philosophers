# NAME = philo_one
# INCLUDE = ./Includes
# CC = gcc
# FLAGS = -Wall -Wextra -Werror
# # C_FILES = $(shell find . -name "*.c" -execdir echo {} ';')
# C_FILES = main.c \
# 					/src/validate_arguments.c \
# 					/src/utils.c \

# OBJDIR = ./src/obj
# OBJ = $(C_FILES:%.c=%.o)
# O_FILES = $(addprefix $(OBJDIR), $(OBJ))

# #Tools to edit text
# RED = \033[1;31m
# GREEN = \033[1;32m
# YELLOW = \033[1;33m
# BLUE = \033[1;34m
# PURPLE = \033[1;35m
# CYAN = \033[1;36m
# WHITE = \033[1;37m
# UNDERLINE = \033[0;4m
# TEXT_RESET = \033[0;0m

# .PHONY: all clean fclean re

# all: $(OBJDIR) $(NAME)

# $(NAME): $(OBJ)
# 	@$(CC) $(FLAGS) -I$(INCLUDE)$(O_FILES) -o $@
# 	@echo "$(GREEN)Success!"

# $(OBJDIR):
# 	@mkdir -p $(OBJDIR)

# %.o: %.c $(INCLUDE)
# 	@echo "$(CYAN)Compiling $<"
# 	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $(OBJDIR)/$@

# clean:
# 	@echo "$(TEXT_RESET)"
# 	@rm -rf $(OBJDIR) ./Includes/*.h.gch
# 	@echo "$(YELLOW)Delete 'o' files"

# fclean: clean
# 	@echo "$(TEXT_RESET)"
# 	@rm -f $(NAME)
# 	@cd $(LIBFT_PATH) && make fclean
# 	@echo "$(YELLOW)Delete the binary file '$(NAME)'"

# re: fclean all


NAME = philo_one

INCLUDES = Includes/

COMP = gcc -Wall -Wextra -Werror  -I$(INCLUDES) -c -o

OBJ_DIR = obj/
SRC_DIR = src/
LIBFT = src/libft/

LIBFT_A = libft.a

SRC =  main.c

CFIND = $(SRC:%=$(SRC_DIR)%)

OFILE =	$(SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)

$(OBJ): $(CFIND)
	make $(OFILE)

$(OFILE):
	@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
	rm -rf $(OBJ) *.out *.h.gch $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re