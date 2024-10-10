#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CXX = c++
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CPPFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98
MKFLAGS		= --no-print-directory

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS			= ./includes
SRCS			= ./sources
_SUBFOLDERS		= 
VPATH			= $(SRCS) $(addprefix $(SRCS)/, $(_SUBFOLDERS))
BINS			= bin

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
NAME			= ex02
_FILES			= main
OBJS			= $(_FILES:%=%.o)
TARGET			= $(addprefix $(BINS)/, $(OBJS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(BINS) $(TARGET)
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"

	$(CXX) $(CPPFLAGS) $(TARGET) -o $(NAME) -I $(DEPS)
	echo "$(GREEN)Done.$(RESET)"

$(BINS)/%.o : %.cpp
	echo "[$(CYAN)Compiling$(RESET)] $(CPPFLAGS) $(GREEN)$<$(RESET)"
	$(CXX) $(CPPFLAGS) -c $< -o $@ -I $(DEPS)

$(BINS):
	mkdir -p $(BINS)

clean:
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(BINS)$(RESET)"
	$(RM) $(BINS)

fclean: clean
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

re: fclean all

run: re
	./$(NAME)

leaks: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.SILENT:

