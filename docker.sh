#!/bin/bash

docker run -e keymap=rmurri -e keyboard=ergodox --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
