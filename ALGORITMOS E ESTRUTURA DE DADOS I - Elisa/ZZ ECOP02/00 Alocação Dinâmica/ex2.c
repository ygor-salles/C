#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
int **A;
int **B;
int **C;
int i, j;

A=(int**)malloc(20*sizeof(int*));
for(i=0; i<20; i++){
A[i]=(int*)malloc(20*sizeof(int));
}

B=(int**)malloc(20*sizeof(int*));
for(i=0;i<20;i++){
B[i]=(int*)malloc(20*sizeof(int));
}

C=(int**)malloc(20*sizeof(int*));
for(i=0;i<20;i++){
C[i]=(int*)malloc(20*sizeof(int));
}


for(i=0; i<20; i++){
for(j=0; j<10; j++){
A[i][j]=rand()%100;
}
}
for(i=0;i<20;i++){
for(j=0;j<10;j++){
B[i][j]=rand()%100;
}
}
for(i=0;i<20;i++){
for(j=0;j<10;j++){
C[i][j]=A[i][j]+B[i][j];
}
}
for(i=0;i<20;i++){
for(j=0;j<10;j++){
printf("Matriz A [%d][%d]=%d\n\n",i,j,A[i][j]);
}  
}
for(i=0;i<20;i++){
for(j=0;j<10;j++){
printf("Matriz B [%d][%d]=%d\n\n",i,j,B[i][j]);
}
}
for(i=0;i<20;i++){
for(j=0;j<10;j++){
printf("Matriz C [%d][%d]=%d\n\n",i,j,C[i][j]);
}
}
for(i=0; i<10; i++){
free(A[i]);
}//end for
for(i=0; i<10; i++){
free(B[i]);
}
for(i=0; i<10; i++){
free(C[i]);
}
free(A);
free(B);
free(C);
return 0;
}