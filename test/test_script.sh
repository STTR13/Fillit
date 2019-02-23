#!/bin/bash

sh clone_tetrigen.sh
make re -C tetrigen/
make re -C ../
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
make fclean -C ../
rm test.fillit
sh clean_tetrigen.sh
