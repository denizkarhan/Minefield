SRCS = *.c

OBJS = ${SRCS:.c=.o}

CC = cc

CCO = cc -c

CCFLAGS = -Wall -Werror -Wextra

NAME = BSQ

PLS = *.pl

PERL = perl

all: 
	${CCO} ${CCFLAGS} ${SRCS}

${NAME}:
	${CC} ${CCFLAGS} ${OBJS} -o ${NAME}

map:
	${PERL} ${PLS} 70 70 3

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} *.txt

re: fclean map all

.PHONY: all map clean fclean re
