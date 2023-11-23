UTIL=jogo.c catalogo.c
MAIN=main.c
BINARY=ex2

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -lm -o $(BINARY)

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o