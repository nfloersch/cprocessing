#
# Generic makefile for making an example program using the cprocessing library
#
CFLAGS = -g -fPIC

CPROCESSINGPATH=../..

CPROCESSINGLIB=$(CPROCESSINGPATH)/objects

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

all: $(TARGET)
	@echo $(TARGET) built

$(TARGET): $(OBJECTS) $(CPROCESSINGLIB)/libcprocessing.a
		gcc $(CFLAGS) -o $@ $(OBJECTS) -L$(CPROCESSINGLIB) -lcprocessing -lglut -lGL -lGLU

clean:
	rm -rf $(OBJECTS) $(TARGET)

%.o: %.cpp $(CPROCESSINGPATH)/cprocessing.hpp
	@echo compiling $<
	@gcc $(CFLAGS) -c $< -o $@ -I$(CPROCESSINGPATH)
