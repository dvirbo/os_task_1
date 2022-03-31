CC = gcc
FLAGS= -Wall -Werror -g
all: shell  server 
run: shell
	./$^
shell: shell.o 
	$(CC) $(FLAGS) $^ -o shell
server: server.o
	$(CC) $(FLAGS) $^ -o server
%.o: %.c
	$(CC) -c $< -o $@
clean:
	rm *.o shell server