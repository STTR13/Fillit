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

#include "../fillit.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  char *str;
  node *test;

  printf("\033[1;31m");
  if (argc != 2)
  	printf("%s\n", "Seulement un param possible");
  str = file_reader(argv[1]);
  printf("%s\n", str);
  test = get_tetrilist(str);
  printf("GT!\n");
  while (test)
  {
	  print_tetri(test->te);
	  printf("%s\n", "error : print_tetri");
	  test = test->next;
  }
  return 0;
}
