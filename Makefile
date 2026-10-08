#CC	 		= arm-none-eabi-gcc
#CFLAGS     ?= -mcpu=cortex-m0 -mthumb -Wall -Wextra -Werror
#LDFLAGS?	= -T link.ld -nostdlib
#LIBS = -lc -lm -lgcc



#compile c source to obj file
#main.o: main.c
#	$(CC) $(CFLAGS) -c $< -o $@

#link object files to create elf file
#firmware.elf: main.o
#	$(CC) $(LDFLAGS) $^ $(LIBS) -o $@




CC		= arm-none-eabi-gcc
OBJCOPY	= arm-none-eabi-objcopy
CFLAGS	= -mcpu=cortex-m0 -mthumb -Wall -Wextra -O2 -g
LDFLAGS = -T link.ld -nostdlib
LIBS	= -lc -lm -lgcc
SRCS 	= src/main.c \
		  src/startup.c \
		  src/drivers/clock.c \
		  src/drivers/gpio.c \
		  src/drivers/i2c.c \
		  src/drivers/timer.c \
		  src/lib/board.c \
		  src/lib/screen.c \
		  src/lib/input.c \

BUILD 	= build
INCDIRS = -Isrc/lib -Isrc/drivers
OBJS 	= $(SRCS:%.c=$(BUILD)/%.o)

all: $(BUILD)/firmware.elf $(BUILD)/firmware.bin

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCDIRS) -MMD -MP -c $< -o $@

$(BUILD)/firmware.elf: $(SRCS:.c=.o)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@

$(BUILD)/%.bin: $(BUILD)/%.elf
	$(OBJCOPY) -O binary $< $@

-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD)

.PHONY: all clean

#firmware.bin: firmware.elf
#$(OBJCOPY) -o binary $< $@

#flash: firmware.bin
#st-flash --reset write firmware.bin 0x08000000

#clean:
#rm -f *.o *.elf	*.bin

#.PHONY: all flash clean
