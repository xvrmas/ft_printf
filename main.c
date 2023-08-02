#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int len;
	int i;
/*
	int len2;
	int len3;
  
	ft_printf("printf: %d\n", i);
	ft_printf("ft_pri: %d\n", len);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("------------------------------------------&c------------------------------------\n");
	char *s1 = "La guerra de las galaxias";
	char *s2 = "George Lucas";
	char *s3 = "1974";
	len = ft_printf("String: %s, director: %s, year: %s.\n", s1, s2, s3);

	i = printf("String: %s, director: %s, year: %s.\n", s1, s2, s3);
	printf("len: %d\n", len);
	printf("i: %d\n", i);

	ft_printf("------------------------------------------&x-&X---------------------------------\n");
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


	ft_printf("------------------------------------------&x-&X---------------------------------\n");
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

	ft_printf("------------------------------------------&x-&X---------------------------------\n");
	char a = 'H';
	len = ft_printf("char: %%m%c \n", a);
	i = printf("char: %%m%c \n", a);
	printf("len: %d\n", len);
        printf("i: %d\n", i);

	len = ft_printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	i = printf("Porcentaje: 100%%, 90%%, 75%% y 25%%\n");
	printf("len: %d\n", len);
        printf("i: %d\n", i);
*/
	len = ft_printf("%d %d", 2147483647, (int)-2147483648);
	printf("\n");
	i = printf("%d %d", 2147483647, (int)-2147483648);	


/*	len = ft_printf("%d", 647);
	ft_printf("\n");
	i = printf("%d",  647);
*/	printf("\nlen: %d", len);
    	printf("\ni: %d\n", i);
/*
	ft_printf("------------------------------------------&x-&X---------------------------------\n");

	int j;
	int k;

	j = ft_printf("%u",-10);
	ft_printf("\n");
	k = printf("%u", -10);
	printf("\nft_print: %d\n", j);
	printf("printf: %d\n", k);
*/	return (0);
}
