UTIL=caminho.c ponto.c
MAIN=main.c
BINARY=ex1

all:
	gcc -Wall -g $(UTIL) $(MAIN) -lm -o $(BINARY)

run:
	./$(BINARY)
	
debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o