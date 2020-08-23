
NAME =		sld-win.out

SRC_DIR =	src
SRCS =		main.cpp		\
		render/renderer.cpp	\
		render/window.cpp

OBJ_DIR =	bin
OBJS =		$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CFLAGS=$(shell sdl2-config --cflags)
LFLAGS=$(shell sdl2-config --libs)

HEADERS =	inc/renderer.hpp
HEADERS_DIR=$(shell dirname $(HEADERS))

GPP =		g++

all: $(NAME)
	@echo "Done."

$(NAME) : $(OBJ_DIR) $(OBJS)
	@$(GPP) $(OBJS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR) : 
	@echo "Missing bin directory, creating it."
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(shell dirname $@)
	@$(GPP) -c $< -o $@ $(HEADERS_DIR:%=-I%) $(CFLAGS)
	@echo "Compiled : $(shell basename $<)"

clean :
	@echo "Cleaning binaries"
	@rm -rf $(OBJ_DIR)

fclean : clean
	@echo "Cleaning library"
	@rm -rf $(NAME)

re : fclean all

test:
	@sh test.sh
	@printf "\033[1;32mTest \033[1;0m:\n->"
