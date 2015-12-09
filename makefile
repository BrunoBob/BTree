EXEC = Btree

all : $(EXEC)

main.o : $(EXEC).h main.c
	gcc -c -Wall main.c

$(EXEC).o : $(EXEC).h $(EXEC).c
	gcc -c -Wall $(EXEC).c

$(EXEC) : main.o $(EXEC).o
	gcc main.o -Wall $(EXEC).o -o $(EXEC)

clean :
	rm *.o $(EXEC)
