CC=gcc
CXX=g++
RM=rm -f

TARGET=./main

INCLUDES=-I./src/include -I.
INCLUDES=-I./src/include -I.

DIR_OBJ=./src/objs

SRCS=$(wildcard ./src/*.cc)

all: $(TARGET)
	@echo Made [ $? ] OK :\)
	
$(TARGET): $(OBJS)
	@echo Linking [$@]
	@$(CXX) -o $@ $^ $(CXXFLAGS) $(LDLIBS) $(LDFLAGS) 
	
$(DIR_OBJ)/%.o: ./src/%.cc
	@echo Compiling [$@]
	@mkdir -p $(DIR_OBJ)
	@$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)

clean:
	@$(RM) $(OBJS)
	@$(RM) *~ core
	@$(RM) ./main

distclean: clean
	@$(RM) $(TARGET)
	@$(RM) -r $(DIR_OBJ)
	
.PHONY: all clean distclean
