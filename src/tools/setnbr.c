/*
** setnbr.c for SETNBR in /home/bougon_p/rendu/gfx_tekpaint
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Jan 22 05:11:57 2016 bougon_p
** Last update Sun Mar 13 10:48:40 2016 bougon_p
*/

#include "paint.h"

char    *set_line_null(char *str, int length)
{
  int   i;

  i = -1;
  while (++i < length)
    str[i] = 0;
  return (str);
}

char    *cleanstr(char *nbr)
{
  char  *clean;
  int   p;
  int   i;

  if ((clean = bunny_malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  clean = set_line_null(clean, 10);
  p = 0;
  while (nbr[p++] == '0' && p < 10);
  if (p == 10)
    {
      clean[0] = '0';
      clean[1] = 0;
      bunny_free(nbr);
      return (clean);
    }
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  bunny_free(nbr);
  return (clean);
}

char    *setnbr(int nbr)
{
  char  *numb;
  int   i;
  int   p;

  p = 8;
  if ((numb = bunny_malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  set_line_null(numb, 10);
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}
