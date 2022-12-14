#File Directory things (might be overkill idk yet)
INCLUDE = -I$(SRC_DIR)/headers
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
dirguard = $(mkdir -p $(@D))

#Essential files and groups
SRCS := $(call rwildcard, $(SRC_DIR), *.cpp)
EXAMPLESRCS := $(call rwildcard, $(EXAMPLE_DIR), *.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

SHAREDOBJ := libsktui.so
SHARED_PATH := $(OBJ_DIR)/static

EXAMPLEOBJS := $(patsubst $(EXAMPLE_DIR)/%.cpp, $(EXAMPLE_OBJDIR)/%.o, $(EXAMPLESRCS))
EXAMPLEEXES := $(patsubst $(EXAMPLE_DIR)/%.cpp, $(EXAMPLE_DIR)/%.out, $(EXAMPLESRCS))

all: $(SHAREDOBJ) testfiles
	@echo ---- Generating $^ ---

$(SHAREDOBJ): $(OBJS)
	@mkdir -p $(SHARED_PATH)
	@mkdir -p $(EXAMPLE_OBJDIR)
	@echo ---- Generating Shared object: $^ ---
	$(CC) $(CCFLAGS) -shared -o $@ $^ -lm
	@cp $@ $(EXAMPLE_DIR)/

testfiles: $(EXAMPLEEXES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo ---- Compiling $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -fPIC -c $< -o $@

$(EXAMPLE_OBJDIR)/%.o: $(EXAMPLE_DIR)/%.cpp
	@echo ---- Compiling $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -c $^ -o $@
	
$(EXAMPLE_DIR)/%.out: $(EXAMPLE_OBJDIR)/%.o
	@echo ---- Linking $^ ----
	@mkdir -p $(@D)
	$(CC) $(CCFLAGS) -o $@ $^ -L$(EXAMPLE_DIR) -Wl,-rpath=$(EXAMPLE_DIR) -lsktui # -lm 

setup:
	@mkdir -p $(LOG_DIR)
	@mkdir -p $(SHARED_PATH)
	@mkdir -p $(REDIRECT_DIR)
	@mkdir -p $(SHARED_PATH)

clean:
	rm -rf $(OBJ_DIR)/
	rm -rf $(REDIRECT_DIR)/
	rm -rf $(SHARED_PATH)
	rm -rf $(LOG_DIR)/
	rm -rf $(EXAMPLE_OBJDIR)/
	find . -name "*.out" -type f -delete
	find . -name "*.o" -type f -delete
	find . -name "*.bin" -type f -delete
	find . -name "*.tmp" -type f -delete
	find . -name "*.so" -type f -delete
