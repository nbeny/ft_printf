NAME	=	libftprintf.a

SRC	=	src/ft_printf.c src/ft_check.c src/ft_dispatcher.c\
		src/ft_handler_c.c src/ft_handler_s.c src/ft_handler_p.c src/ft_handler_d.c\
		src/ft_handler_o.c src/ft_handler_u.c src/ft_handler_x.c\
		src/ft_flag_hhlld.c src/ft_flag_hhllo.c src/ft_flag_hhllu.c src/ft_flag_hhllx.c\
		src/ft_flag_jzd.c src/ft_flag_jzo.c src/ft_flag_jzu.c src/ft_flag_jzx.c\
		src/ft_flags_char.c src/ft_flags_int.c

OBJ	=	ft_printf.o ft_check.o ft_dispatcher.o\
		ft_handler_c.o ft_handler_s.o ft_handler_p.o ft_handler_d.o\
		ft_handler_o.o ft_handler_u.o ft_handler_x.o\
		ft_flag_hhlld.o ft_flag_hhllo.o ft_flag_hhllu.o ft_flag_hhllx.o\
		ft_flag_jzd.o ft_flag_jzo.o ft_flag_jzu.o ft_flag_jzx.o\
		ft_flags_char.o ft_flags_int.o


HDR	=	ft_printf.h

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -I $(HDR) -c $(SRC)
		libtool -o $(NAME) ./libft/libft.a
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all clean
