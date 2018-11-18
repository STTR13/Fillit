/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:00:51 by staeter           #+#    #+#             */
/*   Updated: 2018/11/17 17:00:53 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

typedef struct	tetri
{
	char			letter;
	unsigned short	tab[4];
}				tetri;

/*
**		reader.c
*/
char			*reader(int filedesc);
char			*standi_reader(void);
char			*file_reader(const char *filename);

/*
**		check.c
*/
int				isvalid_tetri(const tetri *te);
tetri			*getvalid_tetri(char **str, char letter);
tetri			*get_tetritab(const char *str);

/*
**		tetri.c
*/
void			free_tetri(tetri **te);
tetri			*new_tetri(void);
int				fill_tetri(tetri *te, char **str, char letter);
tetri			*fillnew_tetri(char **str, char letter);

#endif
