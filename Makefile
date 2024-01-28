##
## EPITECH PROJECT, 2024
## my_navy
## File description:
## Makefile
##

CC	=	gcc -g3

SRCS_FILE	=	src/main.c						\
				src/connection/guest_connection.c		\
				src/connection/host_connection.c		\
				src/game/check_win.c				\
				src/game/game_loop.c				\
				src/listener/signal_listener.c			\
				src/map/enemy_map.c				\
				src/map/my_map.c				\
				src/parser/map_parser.c				\
				src/protocol/protocol_service.c			\
				src/protocol/reader/bytes_reader.c		\
				src/protocol/signal/signal_manager.c		\
				src/protocol/signal/signal_sender.c		\

COMMONS_FILE	=	lib/commons/my_str_dup.c				\
					lib/commons/my_rev_str.c		\
					lib/commons/my_get_nbr.c		\
					lib/commons/my_str_utils.c		\
					lib/commons/my_str_to_word_array.c	\
					lib/commons/my_put_int.c		\

HRCS	=	include

TARGET	=	my_navy

BUILD_DIR = build

OBJS	=	$(addprefix $(BUILD_DIR)/, $(SRCS_FILE:.c=.o))
OBJS	+=	$(addprefix $(BUILD_DIR)/, $(COMMONS_FILE:.c=.o))

all:	$(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@

$(TARGET):	$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LIB)

re:	fclean all

clean:
	rm -f $(OBJS)
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(TARGET)
