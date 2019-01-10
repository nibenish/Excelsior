CXX = gcc -g
LDFLAGS =
CXXFLAGS = -o
OBJS = Excelsior
FILES = game.c
DEPS = excelsior.h

all : $(FILES)
	$(CXX) $(CXXFLAGS) Excelsior game.c $(DEPS)

game : game.c text.h
	$(CXX) $(CXXFLAGS) Excelsior $< $(DEPS)

clean :
	rm -rf *.o $(OBJS) *.dSYM *.gch *.log
