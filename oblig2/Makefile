LDOPTS:=$(shell fltk-config --ldflags)
STD:=$(-std=c++11)

SRC=main.cpp animation_canvas.cpp is_vector.cpp
BINARY=fireworks

all: info fireworks


info:
	@echo "==================== BIULDING FOR FLTK ================================"
	@echo "Found FLTK-version: \t" $(fireworks) 
	@echo "Assumed options: \t" $(LDOPTS)
	@echo ""
	@echo 'Full options from "fltk-config --ldflags:"'
	@echo $(shell fltk-config --ldflags)
	@echo "======================================================================"
	$(RM) $(BINARY)



fireworks:
	@echo "Building for "$(FLTK)

	g++ $(STD) $(SRC) -o $(BINARY) $(LDOPTS)
	
	@echo m
	@echo 'Done. Run with ./'$(BINARY)
	@echo 


clean:
	$(RM) $(BINARY)