NAME =			philo

HEADERS =		philo.h

SOURCES =		main.c \
						util.c

OBJECTS =		$(SOURCES:.c=.o)

CC =				cc
CFLAGS =		-Wall -Werror -Wextra

RM =				rm -rf

all:				${NAME}

${NAME}:		${OBJECTS}
						${CC} ${CFLAGS} ${OBJECTS} -o $@

%.o:				%.c ${HEADERS}
						${CC} ${CFLAGS} -c $< 

clean:
						${RM} ${OBJECTS}

fclean:			clean
						${RM} ${NAME}	

re:					fclean all

.PHONY:			all, clean, fclean, re

