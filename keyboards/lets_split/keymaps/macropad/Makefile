RGBLIGHT_ENABLE = yes
USE_I2C = no

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif

avrdude: build
	ls /dev/tty* > /tmp/1; \
	echo "Reset your Pro Micro now"; \
	while [[ -z $$USB ]]; do \
	  sleep 1; \
	  ls /dev/tty* > /tmp/2; \
	  USB=`diff /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`; \
	done; \
	avrdude -p $(MCU) -c avr109 -P $$USB -U flash:w:$(BUILD_DIR)/$(TARGET).hex

.PHONY: avrdude
