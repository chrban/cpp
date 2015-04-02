LDOPTS:=$(shell fltk-config --ldflags)
STD:=$(-std=c++11)

SRC=main.cpp animation_canvas.cpp is_vector.cpp has_color.cpp dot.cpp rocket2.cpp fireworks2.cpp animated.cpp NormalDotFactory.cpp AbstractDotFactory.cpp BlinkingDotFactory.cpp blinkingDot.cpp TintedDotFactory.cpp MixedDotFactory.cpp
BINARY=fireworks2

all: clean fireworks2

fireworks2:
	g++ -std=c++11 $(SRC) -o $(BINARY) $(LDOPTS)
	@echo 'Done. Run with ./'$(BINARY)   --------------
	@echo 


clean:
	@echo --------------CLEANING-----------------------------
	$(RM) $(BINARY)
	@echo --------------DONE CLEANING------------------------



 