# Let's Split - nic

## Flashing

Flashing is easiest with the included script. You'll need `avrdude` installed.

```
$ make avrdude SUBPROJECT=rev2
```

Output:

```
~/code/qmk_firmware/keyboards/lets_split/keymaps/nic master*
❯ make avrdude SUBPROJECT=rev2
Getting initial serial state
Reset your Pro Micro then hit any key...

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude: Device signature = 0x1e9587 (probably m32u4)
avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
         To disable this feature, specify the -D option.
avrdude: erasing chip
avrdude: reading input file "../../../..//.build/lets_split_rev2_nic.hex"
avrdude: input file ../../../..//.build/lets_split_rev2_nic.hex auto detected as Intel Hex
avrdude: writing flash (18772 bytes):

Writing | ################################################## | 100% 1.43s

avrdude: 18772 bytes of flash written
avrdude: verifying flash memory against ../../../..//.build/lets_split_rev2_nic.hex:
avrdude: load data flash data from input file ../../../..//.build/lets_split_rev2_nic.hex:
avrdude: input file ../../../..//.build/lets_split_rev2_nic.hex auto detected as Intel Hex
avrdude: input file ../../../..//.build/lets_split_rev2_nic.hex contains 18772 bytes
avrdude: reading on-chip flash data:

Reading | ################################################## | 100% 0.19s

avrdude: verifying ...
avrdude: 18772 bytes of flash verified

avrdude: safemode: Fuses OK (E:CB, H:D8, L:FF)

avrdude done.  Thank you.
```
