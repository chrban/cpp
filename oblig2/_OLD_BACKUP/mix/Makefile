LDOPTS:=$(shell fltk-config --ldflags)

SRC=main.cpp animation_canvas.cpp is_vector.cpp has_color.cpp dot.cpp rocket.cpp fireworks.cpp animated.cpp
SRC2=main.cpp animation_canvas.cpp is_vector.cpp has_color.cpp dot.cpp rocket2.cpp fireworks2.cpp animated.cpp NormalDotFactory.cpp AbstractDotFactory.cpp BlinkingDotFactory.cpp blinkingDot.cpp TintedDotFactory.cpp MixedDotFactory.cpp
BINARY=fireworks
BINARY2=fireworks2

all: clean fireworks

fireworks:
	g++ -std=c++11 $(SRC) -o $(BINARY) $(LDOPTS)
	@echo 'Done. Run with ./'$(BINARY)   --------------
	@echo 

fireworks2:
	g++ -std=c++11 $(SRC2) -o $(BINARY2) $(LDOPTS)
	@echo 'Done. Run with ./'$(BINARY2)   --------------
	@echo 


clean:
	@echo --------------CLEANING-----------------------------
	$(RM) $(BINARY)
	$(RM) $(BINARY2)
	@echo --------------DONE CLEANING------------------------



 