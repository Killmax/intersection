/*
** 104intersection.c for 104 in /home/brugue_m/rendu/104intersection
** 
** Made by Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Dec 30 17:15:18 2014 Maxime
** Last update Fri Mar 13 13:38:25 2015 bruguet Maxime
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int		main(int ac, char **av)
{
  int		opt;
  int		x;
  int		y;
  int		z;
  int		Vx;
  int		Vy;
  int		Vz;
  int		R;
  int		i = 1;
  float		x1;
  float		x2;
  float		delta;
  float		a;
  float		b;
  float		c;

  if (ac != 9)
    {
      printf("Usage : ./104intersection option x y z Vx Vy Vz angle/rayon (selon option)\n");
      return (1);
    }
  while (i < ac)
    {
      if (my_str_isnum(av[i]) == 1)
	{
	  printf("Le %de argument n'est pas un nombre !\n", i);
	  return (1);
	}
      else
	i++;
    }
  opt = atoi(av[1]);
  x = atoi(av[2]);
  y = atoi(av[3]);
  z = atoi(av[4]);
  Vx = atoi(av[5]);
  Vy = atoi(av[6]);
  Vz = atoi(av[7]);
  R =  atoi(av[8]); //* 180) / M_PI;
  if (opt == 1)
    {
      printf("sphère de rayon %d\n", R);
      a = Vx * Vx + Vy * Vy + Vz * Vz;
      b = (2 * x * Vx) + (2 * y * Vy) + (2 * z * Vz);
      c = x * x + y * y + z * z - R * R;
    }
  else if (opt == 2)
    {
      printf("cylindre de rayon %d\n", R);
      a = Vx * Vx + Vy * Vy;
      b = (2 * x * Vx) + (2 * y * Vy);
      c = x * x + y * y - R * R;
    }
  else if (opt == 3)
    {
      printf("cône d'angle %d degrés\n", R);
      a = Vx * Vx + Vy * Vy - ((Vz * Vz) / (tan(R) * tan(R)));
      b = (2 * x * Vx) + (2 * y * Vy)  - ((2 * z * Vz) / (tan(R) * tan(R)));
      c = x * x + y * y - ((z * z) / (tan(R) * tan(R)));
    }
  else
    {
      printf("Option 1 pour sphère, 2 pour cylindre, 3 pour cône\n");
      return (1);
    }
  printf("droite passant par le point (%d, %d, %d), de vecteur directeur (%d, %d, %d)\n", x, y, z, Vx, Vy, Vz);
  delta = b * b - 4 * a * c;
  if (delta == 0)
    {
      printf("Nombre de point : 1\n");
      x1 = -(b / 2 * a);
      printf("Point 1 : (%.3f, %.3f, %.3f)\n", x + x1 * Vx, y + x1 * Vy, z + x1 * Vz);
    }
  else if (delta < 0)
    printf("Nombre de point : 0\n");
  else if (delta > 0)
    {
      printf("Nombre de point : 2\n");
      x1 = ((-b) - sqrt(delta)) / (2 * a);
      x2 = ((-b) + sqrt(delta)) / (2 * a);
      printf("Point 1 : (%.3f, %.3f, %.3f)\n", x + x1 * Vx, y + x1 * Vy, z + x1 * Vz);
      printf("Point 2 : (%.3f, %.3f, %.3f)\n", x + x2 * Vx, y + x2 * Vy, z + x2 * Vz);
    }
  return (0);
}
