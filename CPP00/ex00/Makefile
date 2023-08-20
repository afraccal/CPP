NAME = megaphone
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -f
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o : %.cpp
		$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re