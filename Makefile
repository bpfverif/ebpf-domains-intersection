CC = gcc
CFLAGS = -Wall -Wextra -O3 -Iinclude -MMD -MP
BUILD_DIR = build
TARGET = $(BUILD_DIR)/intersection.out

SRCS = main.c \
       tnum.c \
       intersection_allwise.c \
       intersection_pairwise.c \
       find_witness.c \
       find_witness_combined.c

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

.PHONY: all clean