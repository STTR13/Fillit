
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tetrilist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:36:01 by nraziano          #+#    #+#             */
/*   Updated: 2018/11/29 12:36:03 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../fillit.h"

#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')

int main(int argc, char const *argv[])
{
	char *str;
	char *tmp_str;
	node *dest;
	//tetri *t[4];

	printf("Example of how to use BYTE_TO_BINARY: %c%c%c%c%c%c%c%c\n", BYTE_TO_BINARY(19));

	if (argc != 2)
		printf("%s\n", "Seulement un param possible");
	str = file_reader(argv[1]);
	tmp_str = str;
	//ft_putstr(str);
	//ft_putchar('\n');
	//t[0] = getvalid_tetri(&str, 'D');
	//print_tetri(t[0]);
	//ft_putchar(*str);
	//str++;
	//t[1] = getvalid_tetri(&str, 'A');
	//print_tetri(t[1]);
	//ft_putchar(*str);
	//str++;
	//t[2] = getvalid_tetri(&str, 'B');
	//print_tetri(t[2]);
	//ft_putchar(*str);
	//str++;
	//t[3] = getvalid_tetri(&str, 'C');
	//print_tetri(t[3]);
	//ft_putchar('\n');
	//dest = NULL;
	//printf("add_node: %d\n", add_node(&dest, t[0]));
	//printf("add_node: %d\n", add_node(&dest, t[1]));
	//printf("add_node: %d\n", add_node(&dest, t[2]));
	//printf("add_node: %d\n", add_node(&dest, t[3]));
	//ft_putchar('\n');
	//print_tetrilist(dest , 4);
	//free_node(&dest);
	//str = tmp_str;
	//printf("%d && %d\n\n", !str, ft_strlen(str) % 21 != 20);
	if (!(dest = get_tetrilist(str)))
	{
		printf("%s\n", "get_tetrilist returned false");
		free_node(&dest);
		return (0);
	}
	print_tetrilist(dest , 4);
	printf("%s\n", "YES WE DID IT");
	return 0;
}
