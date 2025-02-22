NAME = Daily_Quest_Tracker
GRAPH_NAME = Daily_Quest_Tracker_Graph
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC =   src/main.cpp \
        src/quests.cpp \
        src/updateCSV.cpp

GRAPH_SRC = src/displayProgress.cpp

OBJ_DIR = obj
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
GRAPH_OBJ = $(GRAPH_SRC:src/%.cpp=$(OBJ_DIR)/%.o)

# Color codes
RED = \033[31m
GREEN = \033[32m
MAGENTA = \033[35m
RESET = \033[0m

SHELL := /bin/bash

all: $(NAME)

# Graphical version with SFML
graph: check_sfml $(GRAPH_NAME)

check_sfml:
	@if ! dpkg -s libsfml-dev >/dev/null 2>&1; then \
		echo -e "$(MAGENTA)SFML not found, installing...$(RESET)"; \
		sudo apt-get update && sudo apt-get install -y libsfml-dev; \
	else \
		echo -e "$(GREEN)SFML is already installed!$(RESET)"; \
	fi
	@echo "Continuing with the graphical build..."

rm_sfml:
	@echo -e "$(RED)Removing SFML...$(RESET)"
	@sudo apt-get remove --purge -y libsfml-dev
	@rm -rdf ./sfml
	@echo -e "$(GREEN)SFML removed successfully!$(RESET)"

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ echo -ne "$(MAGENTA)Making $(NAME)"
	@ ( \
        trap 'echo -e "$(RED)Interrupted by user $(RESET)"; exit 1' INT; \
        $(CC) $(CFLAGS) -o $(NAME) $(OBJ) & \
        PID=$$!; \
        while kill -0 $$PID 2>/dev/null; do \
            echo -n "."; \
            sleep 0.4; \
            echo -n "."; \
            sleep 0.6; \
            echo -n "."; \
            sleep 0.4; \
        done; \
        wait $$PID; \
    )
	@ echo -ne "\n$(GREEN)Done!$(RESET)\n"

$(GRAPH_NAME): $(OBJ_DIR) $(OBJ) $(GRAPH_OBJ)
	@ echo -ne "$(MAGENTA)Making $(GRAPH_NAME)"
	@ ( \
        trap 'echo -e "$(RED)Interrupted by user $(RESET)"; exit 1' INT; \
        $(CC) $(CFLAGS) -DUSE_SFML -o $(GRAPH_NAME) $(OBJ) $(GRAPH_OBJ) $(LDFLAGS) & \
        PID=$$!; \
        while kill -0 $$PID 2>/dev/null; do \
            echo -n "."; \
            sleep 0.4; \
            echo -n "."; \
            sleep 0.6; \
            echo -n "."; \
            sleep 0.4; \
        done; \
        wait $$PID; \
    )
	@ echo -ne "\n$(GREEN)Done!$(RESET)\n"

# Custom rule to compile .cpp to .o
$(OBJ_DIR)/%.o: ./src/%.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

clean:
	@ echo -e "$(RED)Removing $(OBJ_DIR) $(RESET)"
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ echo -e "$(RED)Removing $(NAME) and $(GRAPH_NAME) $(RESET)"
	@ rm -f $(NAME) $(GRAPH_NAME)

re: fclean all

.PHONY: all clean fclean re check_sfml rm_sfml graph
