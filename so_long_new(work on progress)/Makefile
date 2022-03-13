# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sclam <sclam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 06:05:07 by sclam             #+#    #+#              #
#    Updated: 2022/03/12 16:47:10 by sclam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c srcs/assets.c srcs/assets2.c \
			srcs/map_check.c srcs/map_read.c srcs/render.c \
			srcs/tilemap.c srcs/wasd.c srcs/animation.c \
			srcs/enemy.c \

LIBFT	=	-L./libft -lft

MLX_H	=	-Imlx

MLX		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME	=	so_long

CC		=	cc

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

HEAD	=	so_long.h

%.o : %.c	${HEAD}
			${CC} ${CFLAGS} ${MLX_H} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEAD}
			make -C ./libft
			make -C ./mlx
			${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT} ${MLX}

all:		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}
			make clean -C ./libft

fclean:		
			${RM} ${OBJS}
			${RM} ${NAME}
			make fclean -C ./libft
			make fclean -C ./mlx

re:			fclean all

.PHONY:		all clean fclean re bonus