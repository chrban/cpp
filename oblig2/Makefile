LDOPTS:=$(shell fltk-config --ldflags)
STD:=$(-std=c++11)

SRC=main.cpp animation_canvas.cpp is_vector.cpp has_color.cpp dot.cpp rocket.cpp fireworks.cpp animated.cpp
BINARY=fireworks

all: clean fireworks

fireworks:
	g++ -std=c++11 $(SRC) -o $(BINARY) $(LDOPTS)
	@echo 'Done. Run with ./'$(BINARY)   --------------
	@echo 


clean:
	@echo --------------CLEANING-----------------------------
	$(RM) $(BINARY)
	@echo --------------DONE CLEANING------------------------