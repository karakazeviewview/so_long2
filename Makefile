NAME 	= so_long

BNAME	= so_long_bonus

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

BSRCS 	=	./Bonus/ft_join_strings_bonus.c				\
			./Bonus/ft_itoa_bonus.c						\
			./Bonus/ft_get_map_bonus.c					\
			./Bonus/ft_movement_bonus.c 				\
			./Bonus/ft_split_bonus.c					\
			./Bonus/ft_put_image_bonus.c				\
			./Bonus/ft_put_text_bonus.c					\
			./get_next_line/get_next_line_utils.c		\
			./get_next_line/get_next_line.c				\
			./ft_printf/ft_printf.c			    		\
			./ft_printf/ft_printfutils.c			    \
			./ft_printf/ft_printfutils2.c			    \
			./ft_printf/ft_printfutils3.c			    \
			./ft_printf/ft_printfutils4.c			    \
			./ft_printf/ft_printfutils5.c			    \
			./ft_printf/ft_printf_bonus.c			    \
			./ft_printf/ft_printf_bonus2.c			    \
			./Bonus/ft_check_file_is_valid_bonus.c		\
			./Bonus/ft_check_map_utils_bonus.c			\
			./Bonus/ft_check_map_bonus.c				\
			./Bonus/ft_animation_bonus.c				\
			./Bonus/ft_animation_utils_bonus.c			\
			./Bonus/ft_exit_door_bonus.c				\
			./Bonus/so_long_bonus.c


SRCS 	=	./Mandatory/ft_join_strings.c				\
			./Mandatory/ft_itoa1.c						\
			./Mandatory/ft_get_map.c					\
			./Mandatory/ft_movement.c 					\
			./Mandatory/ft_split.c						\
			./Mandatory/ft_put_image.c					\
			./Mandatory/ft_put_text.c					\
			./get_next_line/get_next_line_utils.c	    \
			./get_next_line/get_next_line.c			    \
			./ft_printf/ft_printf.c			    		\
			./ft_printf/ft_printfutils.c			    \
			./ft_printf/ft_printfutils2.c			    \
			./ft_printf/ft_printfutils3.c			    \
			./ft_printf/ft_printfutils4.c			    \
			./ft_printf/ft_printfutils5.c			    \
			./ft_printf/ft_printf_bonus.c			    \
			./ft_printf/ft_printf_bonus2.c			    \
			./Mandatory/ft_check_file_is_valid.c		\
			./Mandatory/ft_check_map_utils.c			\
			./Mandatory/ft_animation.c					\
			./Mandatory/ft_animation_utils.c			\
			./Mandatory/ft_check_map.c					\
			./Mandatory/ft_exit_door.c					\
			./mandatory/so_long.c

all: $(NAME)

bonus: $(BNAME)

OBJS	= $(SRCS:.c=.o)

BOBJS	= $(BSRCS:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

$(BNAME) : $(BOBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit  $^ -o $@

clean:
	@rm -f $(OBJS) $(BOBJS)

fclean: clean
	@rm -f $(OBJS) $(BOBJS) $(NAME) $(BNAME)

re: fclean all
