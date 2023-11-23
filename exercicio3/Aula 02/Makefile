UTIL=Util/FileManager.c Util/StopWatch.c
MAIN=Maior.c
BINARY=maior

all:
	gcc -Wall $(MAIN) $(UTIL) -o $(BINARY) -I Util/

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY) -I Util/

plot:
	gnuplot "plotdata" -p

clean:
	@rm *.o
