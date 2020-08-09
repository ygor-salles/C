/* Karen de Souza Pompeu - 2016001610
   Bruno Felipe de Moraes - 2017009453
   COM120 - SISTEMAS OPERACIONAIS */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int i, j, cont;

	for(i=0; i<2; i++)
	{
		if (!fork())
		{
			printf("processo FILHO %d\n", getpid());
			
			if(!i)
			{
				cont = 1000;
				while(cont<1999) cont++;

				printf("Contador: %d\n", cont);
			}
			else
			{
				cont = 2000;
				while(cont<2999) cont++;

				printf("Contador: %d\n", cont);
			}

			if(!i)
			{
				for(j=0; j<2; j++)
				{
					if(!fork())
					{
						printf("processo FILHO %d\n", getpid());

						if(!j)
						{
							cont = 3000;
							while(cont<3999) cont++;

							printf("Contador: %d\n", cont);
						}
						else
						{
							cont = 4000;
							while(cont<4999) cont++;

							printf("Contador: %d\n", cont);
						}
						_exit(0);
					}
				}
			}
			_exit(0);
		}
	}

	printf("processo PAI %d\n", getpid());

	cont = 0;
	while(cont<999) cont++;

	printf("Contador: %d\n", cont);
}