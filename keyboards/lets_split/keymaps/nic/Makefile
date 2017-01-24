-include ../../../../Makefile

TAP_DANCE_ENABLE = yes

avrdude:
	make program
	./flash.sh $(BUILD_DIR)/$(KEYBOARD)_$(SUBPROJECT)_$(KEYMAP).hex

.PHONY: avrdude
