#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{	
	int fd;
	int i;
	char buf[205];
	ssize_t	nos_bytes;

	i = 1;
	nos_bytes = 0;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error al obrir l'arxiu. \n");
		}
		else
		{
			nos_bytes = read(fd, buf, 15);
			close(fd);

			if (nos_bytes == 0)
			{
				ft_printf("arxiu buit. \n");
			}
			else 
			{
				ft_printf("El numero de caracters es %d, i el contingut es:\n%s \n", (int)nos_bytes, buf);
			}
		}
		i++;
	}	
/*
	int len;
	int i;

	int len2;
	int len3;
  
	ft_printf("\n");
	ft_printf("------------------------------------------String--(s)----------------------------------\n");
	char *s1 = "La guerra de las galaxias";
	char *s2 = "George Lucas";
	char *s3 = "1974";
	len = ft_printf("String: %s, director: %s, year: %s. %s\n", s1, s2, s3, NULL);

	i = printf("String: %s, director: %s, year: %s.\n", s1, s2, s3);
	printf("len: %d\n", len);
	printf("i: %d\n", i);

	ft_printf("--------------------------------------Hexadecimal--(x)-(X)-------------------------------\n");
	int  hex = 922;
	int hex2 = -42;
	len = ft_printf("hexa lowercase: %x y %x \n", hex, hex2);
	len2 = ft_printf("hexa uppercase: %X y %X \n", hex, hex2);
	i =      printf("lowerca printf: %x y %x \n", hex, hex2);
	len3 =   printf("uppercase prin: %X y %X \n", hex, hex2);
	ft_printf("len:  %d\n", len);
	ft_printf("len2: %d\n", len2);
	ft_printf("i:    %d\n", i);
	ft_printf("len3: %d\n", len3);


	ft_printf("---------------------------------------punter--(p)-----------------------------------\n");
	char punt;
  	char *ptr;
    	char **pptr;
    	char ***ppptr;

    	punt = '@';
    	ptr = &punt;
    	pptr = &ptr;
    	ppptr = &pptr;
    	len = ft_printf("Puntero hexa ft_printf: %p y %p\n", ppptr, NULL);
    	i =      printf("Puntero hexa printf:    %p y %p\n", ppptr, NULL);
    	ft_printf("len: %d\n", len);
   	ft_printf("i:   %d\n", i);

	ft_printf("-----------------------------------------char--(c)----------------------------------\n");
	char a = 'H';
	len = ft_printf("char: %%m%c \n", a);
	i = printf("char: %%m%c \n", a);
	printf("len: %d\n", len);
        printf("i: %d\n", i);
	
	ft_printf("----------------------------------------percentage---(%)-----------------------------\n");

	len = ft_printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	i = printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	ft_printf("-----------------------------------------integer-----(d)--------------------------------\n");
	len = ft_printf("%d", -2147483648);
	ft_printf("\n");
	i = printf("%d",  -3647);
	printf("\nlen: %d", len);
    	printf("\ni: %d\n", i);

	ft_printf("------------------------------------------unsigned-int--(u)---------------------------------\n");

	int j;
	int k;

	j = ft_printf("%u",-10);
	ft_printf("\n");
	k = printf("%u", -10);
	printf("\nft_print: %d\n", j);
	printf("printf: %d\n", k);
*/	return (0);
}
