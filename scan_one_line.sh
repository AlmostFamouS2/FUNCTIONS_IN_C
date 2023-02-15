#!/bin/bash

[[ "$1" != "" ]] && for i in {1..1024}; do (echo </dev/tcp/$1/$i) &>- && echo -e "\x1b[32mPort: $i \x1b[0m"  || echo -n '.' &done  ||  echo " FALTOU O IP !" && exit
