# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jim <jim@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:17:45 by min-jo            #+#    #+#              #
#    Updated: 2022/11/04 12:07:08 by jim              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

HD_DIR		=	include/
SRC_DIR		=	src/
HIT_DIR		=	hit/
OBJECT_DIR	=	object/
MLX_DIR		=	minilibx_opengl_20191021

SRC_ORI		=	main.c mlx_init.c paint.c vector.c matrix.c camera.c object.c\
				object2.c object3.c\
				parse_arg.c parse_rt.c parse_rt2.c error.c\
				parse_rt_amb.c parse_rt_amb2.c\
				parse_rt_cam.c parse_rt_cam2.c parse_rt_cam3.c parse_rt_cam4.c\
				parse_rt_cam5.c parse_rt_cam6.c\
				parse_rt_lig.c parse_rt_lig2.c parse_rt_lig3.c parse_rt_lig4.c\
				parse_rt_lig5.c\
				parse_rt_sph.c parse_rt_sph2.c parse_rt_sph3.c parse_rt_sph4.c\
				parse_rt_sph5.c\
				parse_rt_pla.c parse_rt_pla2.c parse_rt_pla3.c parse_rt_pla4.c\
				parse_rt_pla5.c parse_rt_pla6.c parse_rt_pla7.c\
				parse_rt_cyl.c parse_rt_cyl2.c parse_rt_cyl3.c parse_rt_cyl4.c\
				parse_rt_cyl5.c parse_rt_cyl6.c parse_rt_cyl7.c\
				parse_rt_cyl8.c\
				transform.c	\
				hit.c	\
				sphere.c

HIT_ORI		=	hit.c

OBJECT_ORI	=	sphere.c

# SRC			=	$(addprefix $(SRC_DIR), $(SRC_ORI), \
# 							$(SRC_DIR)/$(HIT_DIR), $(HIT_ORI), \
# 							$(SRC_DIR)/$(OBJECT_DIR), $(OBJECT_ORI))
SRC			=	$(addprefix $(SRC_DIR), $(SRC_ORI))
BSRC		=	$(addprefix $(SRC_DIR), $(SRC_ORI))

OBJ			=	$(SRC:.c=.o)
BOBJ		=	$(BSRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -MD -g # -fsanitize=address # TODO
CPPFLAGS	+=	-I $(HD_DIR) -I $(MLX_DIR)
LIBADD		+=	-lm -lmlx -framework OpenGL -framework Appkit #-lpthread
LDFLAGS		+=	-L$(MLX_DIR)

all:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -O3 $< -c -o $@

$(NAME):	$(OBJ)
	@make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) -O3 $^ -o $@

bonus:		$(BOBJ)
	@make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) -O3 $^ -o $(NAME)
	touch bonus

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	rm -f $(OBJ:.o=.d)
	rm -f $(BOBJ:.o=.d)
	rm -f bonus
	@make -C $(MLX_DIR) clean 2> /dev/null

fclean:		clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY:		all clean fclean re bonus

-include $(OBJ:.o=.d)
-include $(BOBJ:.o=.d)
