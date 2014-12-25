/*
** 104intersection.c for 104 in /home/brugue_m/rendu/104intersection
** 
** Made by Maxime
** Login   <brugue_m@epitech.net>
** 
** Started on  Thu Dec 25 13:56:43 2014 Maxime
** Last update Thu Dec 25 14:32:52 2014 Maxime
*/
int		main(int ac, char **av)
{
  int		opt;
  int		x;
  int		y;
  int		z;
  int		Vx;
  int		Vy;
  int		Vz;
  int		last;
  int		i;

  if (ac == 1 || ac != 9)
    {
      printf("Usage : ./104intersection option x y z Vx Vy Vz Rayon/angle (selon option)\n");
      return (1);
    }
  else
    {
      opt = atoi(av[1]);
      x = atoi(av[2]);
      y = atoi(av[3]);
      z = atoi(av[4]);
      Vx = atoi(av[5]);
      Vy = atoi(av[6]);
      Vz = atoi(av[7]);
      last = atoi(av[8]);
      i = 2;
    }
  while (i < ac)
    {
      if (my_str_isnum(av[i]) == 1)
	{
	  printf("Tous les arguments ne sont pas des nombres !\n");
	  return (1);
	}
      else
	i++;
    }
  if (opt == 1)
    printf("sphère de rayon %d\n", last);
  else if (opt == 2)
    printf("cylindre de rayon %d\n", last);
  else if (opt == 3)
    printf("cône d'angle %d degrés\n", last);
  else
    {
      printf("Option 1 pour sphère, 2 pour cylindre et 3 pour cône\n");
      return (1);
    }
  printf("droite passant par le point (%d, %d, %d), de vecteur directeur (%d, %d, %d)\n", x, y, z, Vx, Vy, Vz);
  return (0);
}
