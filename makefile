# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -I./include

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Source files and objects
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable (with .exe extension for Windows compatibility)
# /Q = Quiet - Suppress confirmation requests
# /F = Force
# /S = Include all sub-directories
ifeq ($(OS),Windows_NT)
    TARGET = main.exe
    RM = del /Q /F
    RM_DIR = rmdir /Q /S
    MKDIR = mkdir
else
    TARGET = main
    RM = rm -f
    RM_DIR = rm -rf
    MKDIR = mkdir -p
endif

# Main target
# $@ = TARGET
# @$ = supress output in terminal
# 2> null = redirect error messages to nowhere
# || exit 0 = execute even if mkdir fails
# -o = next defines output name
$(TARGET): $(OBJS)
	@$(MKDIR) $(dir $@) 2> nul || exit 0
	$(CXX) $(OBJS) -o $@

# Compile source files
# -c = compile but dont link, therefor creating an object file
# $< = SRC_DIR/%.cpp (required input file)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR) $(BUILD_DIR) 2> nul || exit 0
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	$(RM) $(TARGET)
	$(RM_DIR) $(BUILD_DIR)

# Phony targets
# required incase there is a file called clean
# .PHONY instructs MAKE this is an action to perform, not a file to create
.PHONY: clean

# Make sure the build directory exists
$(shell $(MKDIR) $(BUILD_DIR) 2> nul)