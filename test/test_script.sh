#!/bin/bash

make re -C tetrigen/
i=1
while [[ "$i" -le "5" ]] ; do
	echo "($i)"
	./tetrigen/tetrigen -v -f 26
	sleep 1
	./../fillit test.fillit
	((j++))
	echo ""
	((i++))
done
make fclean -C tetrigen/
rm test.fillit
