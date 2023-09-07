# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiras-s <jmiras-s@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 16:55:22 by jmiras-s          #+#    #+#              #
#    Updated: 2023/08/10 19:37:27 by jmiras-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
DEP_CLIENT = $(SRC_CLIENT:.c=.d)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
DEP_SERVER = $(SRC_SERVER:.c=.d)

LIB = libft/libft.a

%.o: %.c $(LIBS) Makefile
	@$(CC) $(CFLAGS) -MMD -I./ -c $< -o $@

all:
	@$(MAKE) --no-print-directory -C libft
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT):: $(OBJ_CLIENT)
	@$(MAKE) --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB) -o $@
	@echo "Client compiled"

$(SERVER):: $(OBJ_SERVER)
	@$(MAKE) --no-print-directory -C libft
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB) -o $@
	@echo "Server compiled"

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(DEP_SERVER) $(DEP_CLIENT)
	@$(RM) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(DEP_SERVER_BONUS) $(DEP_CLIENT_BONUS)
	@$(MAKE) clean --no-print-directory -C libft
	@echo "Removed"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEP_CLIENT)
-include $(DEP_SERVER)
