CFLAGS = -W -Wall

INC_DIR = -I ./sys_driver/include \
		  -I ./star_driver

#LIB_DIR = -L ../dxbutils
#LDFLAGS = -pthread -ldxbutils

TARGET  = testcontrol

SRCS = \
	./sys_driver/src/star_gpio.c \
	./sys_driver/src/star_i2c.c \
	./star_driver/star_protocol.c \
	./star_driver/star_driver.c \
	test_control.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LIB_DIR) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c -o $@ $<
 
clean :
	rm -f $(OBJS) $(TARGET)
	rm -f *.o
