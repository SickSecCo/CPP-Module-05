NAME = 			"No, you need form 28B, not 28C..."
FLAGS = 		-Wall -Werror -Wextra -std=c++98
COMPILE =		c++
FILE =			$(wildcard *.cpp)
RM =			rm -rf


all:
	$(COMPILE) $(FLAGS) $(FILE) -o $(NAME)

clean:
	$(RM) $(NAME) *.txt

fclean:	clean

re:	clean all
				
.PHONY:	all clean fclean re