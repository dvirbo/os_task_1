all: shell Server
	./$^

shell: shell.c
	gcc shell.c $^ -o shell 

Server: Server.c
	gcc Server.c $^ -o server 

.PHONY: clean

clean:
	rm -f *.o * shell server
