CC=gcc

CFLAGS=-Wall -lwiringPi
#all:
#	@echo This is make all

all: $(TARGET)

$(TARGET):$(TARGET).c
	$(CC)  $^ -o $@ $(CFLAGS)
	
