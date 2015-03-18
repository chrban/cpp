GCC=g++
CCOPT=-std=c++11

OBJECTS=Blackjack.cpp Cards.cpp Player.cpp

EXEC=Blackjack

all: $(OBJECTS)
		$(GCC) $(CCOPT) $(OBJECTS) -o $(EXEC)
		$(GCC) $(CCOPT) Oppvarming.cpp -o Oppvarming

%.o: %.cpp
		$(GCC) $(CCOPT) -c $< -o $@



clean:
		$(RM) $(OBJECTS)
		$(RM) $(EXE)