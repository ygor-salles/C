/*Crie um programa que receba tres valores (obrigatoriamente maiores que zero), repre- �
sentando as medidas dos tres lados de um tri � angulo. Elabore func� � oes que: �
Determinar se eles lados formam um triangulo, sabendo que: �
 O comprimento de cada lado de um triangulo � e menor do que a soma dos outros �
dois lados.
Determinar e mostrar o tipo de triangulo, caso as medidas formem um tri � angulo. Sendo �
que:
 Chama-se equilatero o tri � angulo que tem tr � es lados iguais. �
 Denominam-se isosceles o tri � angulo que tem o comprimento de dois lados iguais. �
 Recebe o nome de escaleno o triangulo que tem os tr � es lados diferentes.*/

#include<stdio.h>
#include<stdlib.h>

 int triangulo(int a, int b, int c)
    {
       if((a<(b+c))&&(b<(a+ c))&&(c<(a+b)))
         printf("As medidas digitadas formam um triangulo!\n");
         return 0;
         
       } 
 int triangulos(int a,int b, int c)
    {
      if(a==b && a==c && b==c)
       printf("E esse triangulo � equilatero!\n");
      if(((a==b && a!=c && b!=c))||(a==c && a!=b && c!=b))
         printf("E esse triangulo e isoceles!\n");
      if(a!=b && a!=c && b!=c)
         printf("E esse triangulo � escaleno!\n");
      return 0;
      }
 int main (void)
 {
     int medida1,medida2,medida3;
     
     printf("Digite a primeira medida: ");
     scanf("%d",&medida1);     
     printf("Digite a segunda medida: ");
     scanf("%d",&medida2);
     printf("Digite a terceira medida: ");
     scanf("%d",&medida3);
     triangulo(medida1,medida2,medida3);
     triangulos(medida1,medida2,medida3);
     system("pause");
     return 0;
     }
