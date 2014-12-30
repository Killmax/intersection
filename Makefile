##
## Makefile for 104 in /home/brugue_m/rendu/104intersection
## 
## Made by Maxime
## Login   <brugue_m@epitech.net>
## 
## Started on  Thu Dec 25 14:28:17 2014 Maxime
## Last update Tue Dec 30 16:50:06 2014 Maxime
##

NAME= 104intersection

SRC= 104intersection.c my_str_isnum.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) -g -lm

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all
