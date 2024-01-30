
CC=gcc
CFLAGS=-I.
TARGET = test.exe
DEPS = cache.h collatz.h
OBJECT_DIR = obj

_OBJ = cache.o collatz.o test.o  
OBJ = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJ))

$(OBJECT_DIR)/%.o: %.c $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY : clean
clean :
	rm -f $(OBJECT_DIR)/*.o $(TARGET)
