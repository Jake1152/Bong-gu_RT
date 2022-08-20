# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: min-jo <min-jo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:17:45 by min-jo            #+#    #+#              #
#    Updated: 2022/08/20 20:45:27 by min-jo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

HD_DIR		=	include/
SRC_DIR		=	src/
MLX_DIR		=	minilibx_opengl_20191021

SRC_ORI		=	main.c
BSRC_ORI	=

SRC			=	$(addprefix $(SRC_DIR), $(SRC_ORI))
BSRC		=	$(addprefix $(SRC_DIR), $(BSRC_ORI))

OBJ			=	$(SRC:.c=.o)
BOBJ		=	$(BSRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -MD
CPPFLAGS	+=	-I $(HD_DIR) $(MLX_DIR)
LIBADD		+=	-lm -lmlx -framework OpenGL -framework Appkit #-lpthread
LDFALGS		+=	-L$(MLX_DIR)

all:		$(NAME)

%.o:		%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -c -o $@

$(NAME):	$(OBJ)
	@make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) -O3 $^ -o $@

bonus:		$(BOBJ)
	@make -C $(MLX_DIR) 2> /dev/null
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBADD) -O3 $^ -o $(NAME)
	touch bonus

clean:
	rm -f $(OBJ)
	r m -f $(BOBJ)
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
