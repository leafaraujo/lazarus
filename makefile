CXX = g++                       
CXXFLAGS = -std=c++11 -Wall   
SRC_DIR = ./src                
OUTPUT_DIR = ./output           

SRCS = main.cpp \
       $(SRC_DIR)/astronaut/astronaut.cpp \
       $(SRC_DIR)/journey/journey.cpp \
       $(SRC_DIR)/menu/menu.cpp

OUTPUT = main

compile:
    $(CXX) $(CXXFLAGS) $(SRCS) -o $(OUTPUT_DIR)/$(OUTPUT)

run:
    ./$(OUTPUT_DIR)/$(OUTPUT)

eh:
    echo "eh"

.PHONY: compile run eh