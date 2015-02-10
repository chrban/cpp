GCC=g++
CCOPT=-std=c++11

OBJECTS=Blackjack.o Cards.o Player.o

EXEC=Blackjack

all: $(OBJECTS)
		$(GCC) $(CCOPT) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
		$(GCC) $(CCOPT) -c $< -o $@

clean:
		$(RM) $(OBJECTS)
		$(RM) $(EXE)