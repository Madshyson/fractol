#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguillot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 20:50:24 by tguillot          #+#    #+#              #
#    Updated: 2016/04/20 21:47:32 by mlavanan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = 	main.c \
		ft_mandelbrot.c \
		ft_burningships.c \
		ft_julia.c \
		initmandel.c \
		ft_menu.c \
		fill_palette.c \
		tools.c \
		put_pixel_to_img.c \
		ft_keyfunct.c \
		ft_meduse.c

OBJ = 	main.o \
		ft_menu.o \
		initmandel.o \
		ft_mandelbrot.o \
		ft_burningships.o \
		ft_julia.o \
		fill_palette.o \
		tools.o \
		put_pixel_to_img.o \
		ft_keyfunct.o \
		ft_meduse.o

HEADER = fractol.h\
		./libft/libft.h\

FINDLIBFT = -Llibft

LIBFTA = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = ./libft/

all: $(NAME)

$(NAME):
	@clear
	@echo "\033[35;4mRule all!\033[0m"
	@make fclean -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) -c $(SRC) $(HEADER)
	@gcc -o $(NAME) $(OBJ) $(LIBFTA) -lmlx -framework OpenGL -framework AppKit 

clean:
	@clear
	@echo "\033[35;4mRule clean!\033[0m"
	@rm -f $(OBJ)
	@rm -f fractol.h.gch
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@clear
	@echo "\033[35;4mRule fclean!\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
	@clear
	@echo "\033[35;4mRules fclean and all!\033[0m"

.PHONY: all, clean, fclean, re