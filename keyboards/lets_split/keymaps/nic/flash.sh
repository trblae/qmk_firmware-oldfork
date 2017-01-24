#!/bin/bash

HEX_PATH=$1

function usage {
  echo 'Usage:'
  echo '  $ sh flash.sh path/to/hex'
}

if ! [ $HEX_PATH ]; then
  usage
  exit
fi

echo "Getting initial serial state"
ls /dev/tty* > /tmp/1

echo "Reset your Pro Micro then hit any key..."
read -n 1 -s
ls /dev/tty* > /tmp/2

COM_PORT=`diff /tmp/1 /tmp/2 | grep '>' | sed -e 's/> //'`

if ! [ $COM_PORT ]; then
  echo "Serial port not found. Are you sure you're in bootloader mode?"
  exit
fi

avrdude \
  -p atmega32u4 \
  -c avr109 \
  -P $COM_PORT \
  -U flash:w:$HEX_PATH
