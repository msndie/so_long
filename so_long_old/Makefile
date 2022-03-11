# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sclam <sclam@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/07 06:05:07 by sclam             #+#    #+#              #
#    Updated: 2021/11/15 18:02:03 by sclam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	srcs/main.c srcs/animation.c srcs/assets.c \
			srcs/assets2.c srcs/map.c srcs/wasd.c \
			srcs/render.c srcs/animation2.c srcs/map_check.c \
			srcs/patrols.c srcs/danger_wasd.c

LIBFT	=	-L./libft -lft

MLX_H	=	-Imlx

MLX		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME	=	so_long

CC		=	cc

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

HEAD	=	includes/so_long.h

%.o : %.c	${HEAD}
			${CC} ${CFLAGS} ${MLX_H} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEAD}
			make bonus -C ./libft
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