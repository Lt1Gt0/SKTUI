#File Directory things (might be overkill idk yet)
INCLUDE = -I$(SRC_DIR)/headers
BUILD_DIR = bin
SRC_DIR = src
EXAMPLE_DIR = examples
EXAMPLE_OBJDIR = examples/obj
OBJ_DIR = obj
LOG_DIR = logs
REDIRECT_DIR = redirects

#Compiler and linker things
CC = g++
CCFLAGS = -g -Wall -Wextra
LD = ld
LDFLAGS = 

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

#Essential files and groups
SRCS := $(call rwildcard, $(SRC_DIR), *.cpp)
EXAMPLESRCS := $(call rwildcard, $(EXAMPLE_DIR), *.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
EXAMPLEOBJS := $(patsubst $(EXAMPLE_DIR)/%.cpp, $(EXAMPLE_OBJDIR)/%.o, $(EXAMPLESRCS))
EXAMPLEEXES := $(patsubst $(EXAMPLE_DIR)/%.cpp, $(EXAMPLE_DIR)/%.out, $(EXAMPLESRCS))

all: $(OBJS) testfiles 
	@mkdir -p $(LOG_DIR)
	@mkdir -p $(@D)
	@mkdir -p $(REDIRECT_DIR)
	@echo ---- Generating $^ ---

testfiles: $(EXAMPLEEXES)

$(OBJ): $(OBJS)
	@echo ---- Linking $^ ----
	@mkdir -p $(@D)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo ---- Compiling $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@

$(EXAMPLE_OBJDIR)/%.o: $(EXAMPLE_DIR)/%.cpp
	@echo ---- Compiling $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -c $< -o $@
	
$(EXAMPLE_DIR)/%.out: $(EXAMPLE_OBJDIR)/%.o
	@echo ---- Linking $^ ----
	@mkdir -p $(@D)
	$(CC) $^ -o $@

clean:
	rm -rf $(BUILD_DIR)/
	rm -rf $(OBJ_DIR)/
	rm -rf $(REDIRECT_DIR)/
	rm -rf $(LOG_DIR)/
	rm -rf $(EXAMPLE_OBJDIR)/
	find . -name "*.out" -type f -delete
	find . -name "*.o" -type f -delete
	find . -name "*.bin" -type f -delete
	find . -name "*.tmp" -type f -delete
