MESSAGE = hello
CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = ./src
OUTPUT_DIR = ./output

SRCS = $(SRC_DIR)/astronaut/astronaut.h \
    $(SRC_DIR)/astronaut/astronaut.cpp \
	$(SRC_DIR)/journey/journey.h \
    $(SRC_DIR)/journey/journey.cpp \
	$(SRC_DIR)/menu/menu.h \
    $(SRC_DIR)/menu/menu.cpp \
	$(SRC_DIR)/main.cpp
 
OUTPUT = main

run:
	./$(OUTPUT_DIR)/$(OUTPUT)

compile: $(OUTPUT_DIR)
	$(CXX) $(SRCS) -o $(OUTPUT_DIR)/$(OUTPUT)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)
