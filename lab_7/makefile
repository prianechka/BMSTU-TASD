# Компилятор
CC := gcc

# Опции компиляции
CFLAGS := -std=c99 -Wall -Werror

OBJS := ./out/graph.o ./out/process.o ./out/list_graph.o ./out/memory.o ./out/output.o ./out/input.o


app.exe : $(OBJS) ./out/main.o
	$(CC) -o app.exe $(OBJS) ./out/main.o

./out/main.o : ./src/main.c ./inc/process.h
	$(CC) $(CFLAGS) -c $< -o ./out/main.o

./out/graph.o : ./src/graph.c ./inc/graph.h ./inc/memory.h ./inc/input.h ./inc/output.h ./inc/types.h
	$(CC) $(CFLAGS) -c $< -o ./out/graph.o

./out/process.o : ./src/process.c ./inc/process.h ./inc/types.h ./inc/memory.h ./inc/process.h ./inc/input.h ./inc/output.h ./inc/graph.h ./inc/list_graph.h
	$(CC) $(CFLAGS) -c $< -o ./out/process.o

./out/input.o : ./src/input.c ./inc/input.h ./inc/memory.h ./inc/types.h
	$(CC) $(CFLAGS) -c $< -o ./out/input.o

./out/output.o : ./src/output.c ./inc/output.h /inc/types.h
	$(CC) $(CFLAGS) -c $< -o ./out/output.o

./out/memory.o : ./src/memory.c ./inc/memory.h ./inc/types.h
	$(CC) $(CFLAGS) -c $< -o ./out/memory.o

./out/list_graph.o : ./src/list_graph.c ./inc/list_graph.h ./inc/memory.h ./inc/input.h ./inc/output.h ./inc/types.h
	$(CC) $(CFLAGS) -c $< -o ./out/list_graph.o
	

.PHONY : clean
clean :
	$(RM) ./out/*.o *.exe



