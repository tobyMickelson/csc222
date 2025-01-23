TARGET_EXEC := blackjack
TARGET_TEST := test
BUILD_DIR := ./build
SRC_DIRS := ./src

CXX := clang++
STD := c++11

LDLIBS := -lncursesw
LDPATHS := -L/Users/1008814/.local/homebrew/opt/ncurses/lib
LDFLAGS :=

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
OBJS_MAIN := $(filter-out %/test.cpp.o, $(OBJS))
OBJS_TEST := $(filter-out %/main.cpp.o, $(OBJS))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) --std=$(STD) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS_MAIN) -o $@ $(LDFLAGS) $(LDPATHS) $(LDLIBS)

$(BUILD_DIR)/$(TARGET_TEST): $(OBJS)
	$(CXX) $(OBJS_TEST) -o $@ $(LDFLAGS) $(LDPATHS) $(LDLIBS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: test
test: $(BUILD_DIR)/$(TARGET_TEST)
	./$(BUILD_DIR)/$(TARGET_TEST)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
