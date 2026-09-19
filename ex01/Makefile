SRCS = Contact.class.cpp\
		Contact.class.hpp\
		Phonebook.class.cpp\
		Phonebook.class.cpp\

OBJS = ${SRCS:.c=.o}

NAME = phonebook

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

all:     ${NAME}

${NAME}: ${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}


%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:    
	rm -f ${OBJS}

fclean:    clean;
# 	rm -f ${NAME}
	rm -f a.out

re:    fclean all

.PHONY: all clean fclean re
