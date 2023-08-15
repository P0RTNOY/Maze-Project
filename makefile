CC = g++
CFLAGS = -g -std=c++17
INCLUDES = -I.

OBJS = main.o    Data.o    State.o   Solution.o   Maze2d.o   BFS.o  Command.o Maze2dGenerator.o SimpleMaze2dGenerator.o MyMaze2dGenerator.o  CLI.o  MazeSearchable.o  Astar.o

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c main.cpp

Data.o: Data.h Data.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Data.cpp

State.o: State.h State.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c State.cpp

Solution.o: Solution.h Solution.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Solution.cpp

Maze2d.o: Maze2d.h Maze2d.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Maze2d.cpp

BFS.o: BFS.cpp BFS.h
	$(CC) $(CFLAGS) $(INCLUDES) -c BFS.cpp

Command.o: Command.h Command.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Command.cpp

SimpleMaze2dGenerator.o: SimpleMaze2dGenerator.h SimpleMaze2dGenerator.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c SimpleMaze2dGenerator.cpp

MyMaze2dGenerator.o: MyMaze2dGenerator.h MyMaze2dGenerator.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c MyMaze2dGenerator.cpp


Maze2dGenerator.o: Maze2dGenerator.h Maze2dGenerator.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c Maze2dGenerator.cpp

CLI.o: CLI.h CLI.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c CLI.cpp


MazeSearchable.o: MazeSearchable.h MazeSearchable.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c MazeSearchable.cpp


Astar.o: Astar.cpp Astar.h
	$(CC) $(CFLAGS) $(INCLUDES) -c Astar.cpp


# RecursiveAlg.o: RecursiveAlg.h RecursiveAlg.cpp
# 	$(CC) $(CFLAGS) $(INCLUDES) -c RecursiveAlg.cpp


run: main
	./main

clean:
	rm -f $(OBJS) main



# prog: main.o    Data.o    State.o   Solution.o   Maze2d.o   BFS.o  Command.o Maze2dGenerator.o SimpleMaze2dGenerator.o MyMaze2dGenerator.o  CLI.o MazeSearchable.o Astar.o
# 	g++ main.o    Data.o    State.o   Solution.o   Maze2d.o   BFS.o  Command.o Maze2dGenerator.o SimpleMaze2dGenerator.o MyMaze2dGenerator.o  CLI.o MazeSearchable.o Astar.o-o prog 
# 	./prog

# main.o:
# 	g++ -c main.cpp

# Data.o:
# 	g++ -c Data.cpp

# State.o:
# 	g++ -c State.cpp

# Solution.o:
# 	g++ -c Solution.cpp

# Maze2d.o:
# 	g++ -c Maze2d.cpp

# BFS.o:
# 	g++ -c BFS.cpp

# Command.o:
# 	g++ -c Command.cpp

# SimpleMaze2dGenerator.o:
# 	g++ -c SimpleMaze2dGenerator.cpp

# MyMaze2dGenerator.o:
# 	g++ -c MyMaze2dGenerator.cpp


# Maze2dGenerator.o:
# 	g++ -c Maze2dGenerator.cpp

# CLI.o:
# 	g++ -c CLI.cpp


# MazeSearchable.o:
# 	g++ -c MazeSearchable.cpp



# Astar.o:
# 	g++ -c Astar.cpp




# RecursiveAlg.o:
# 	g++ -c RecursiveAlg.cpp





# clean:
# 	del *.o
