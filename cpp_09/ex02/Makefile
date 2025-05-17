# ============================
# 🎨 COLOR CONFIGURATION
# ============================
RED     = \033[91;1m
GREEN   = \033[92;1m
YELLOW  = \033[93;1m
BLUE    = \033[94;1m
PINK    = \033[95;1m
CLEAR   = \033[0m

# ============================
# 🔧 PROJECT CONFIG
# ============================
NAME    = PmergeMe
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     =	main.cpp \
			PmergeMe.cpp

OBJ_DIR = obj
OBJ     = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

DEPS    = 

# ============================
# 🧱 BUILD RULES
# ============================

all: $(NAME)

# Executable build
$(NAME): $(OBJ)
	@echo "$(PINK)✨ Linking executable...$(CLEAR)"
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)✅ Build successful!$(CLEAR)"

# Compiles each .cpp file into obj/.o
$(OBJ_DIR)/%.o: %.cpp $(DEPS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)📦 Compiling $< -> $@$(CLEAR)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✔ Done.$(CLEAR)"

# ============================
# 🧼 CLEANING RULES
# ============================

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(CLEAR)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✔ Object files removed.$(CLEAR)"

fclean: clean
	@echo "$(YELLOW)🧽 Removing executable...$(CLEAR)"
	@rm -rf $(NAME)
	@echo "$(GREEN)✔ Executable removed.$(CLEAR)"

re: fclean all

# ============================
# 🚀 QUICK TEST RULE
# ============================
test: re
	@echo "$(BLUE)🚀 Running program...$(CLEAR)"
	@./$(NAME)

.PHONY: all clean fclean re test