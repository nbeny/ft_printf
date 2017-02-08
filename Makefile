#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 00:13:09 by nbeny             #+#    #+#              #
#    Updated: 2017/02/08 00:14:03 by nbeny            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	ft_printf.a

SRCS	=	ft_flag_hhlld.c ft_flag_ztd.c   ft_handler_c.c  ft_handler_x.c\
		ft_flag_hhllo.c ft_flag_zto.c   ft_handler_d.c  ft_printf.c\
		ft_flag_hhllu.c ft_flag_ztu.c   ft_handler_o.c\
		ft_check.c      ft_flag_hhllx.c ft_flag_ztx.c   ft_handler_s.c

OBJS	=	ft_flag_hhlld.o ft_flag_ztd.o   ft_handler_c.o  ft_handler_x.o\
		ft_flag_hhllo.o ft_flag_zto.o   ft_handler_d.o  ft_printf.o\
		ft_flag_hhllu.o ft_flag_ztu.o   ft_handler_o.o\
		ft_check.o      ft_flag_hhllx.o ft_flag_ztx.o   ft_handler_s.o

HDRS	=	ft_printf.h

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I $(HDRS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)
re: fclean all
