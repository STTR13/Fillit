/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
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
  tetri *dest;
  char letter = 'A';

  printf("\033[1;31m");
  if (argc != 2)
  	printf("%s\n", "Seulement un param possible");
  str = file_reader(argv[1]);
  if (!(dest = fillnew_tetri(&str, letter)))
  {
	  printf("%s\n", "error : fillnew_tetri");
	  free_tetri(&dest);
 	 return (0);
  }
  if (!isvalid_tetri(dest, 4))
  {
	  printf("%s\n", "error : isvalid_tetri");
	  free_tetri(&dest);
	  return (0);
  }
  print_tetriing(dest,16);
  printf("%d : %c%c%c%c%c%c%c%c\n", move_tetri(dest, -1, 0, 10), BYTE_TO_BINARY(2 & 3));
  print_tetriing(dest,16);
  movetopleft_tetri(dest, 16);
  printf("\n");
  print_tetriing(dest,16);
 //printf("\032[1;31m");
  printf("%s\n", "YES WE DID IT");
  return 0;
}
