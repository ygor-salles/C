INSERTIONSORT

void insertionSort (TipoItem *A, int n)
{
    int i, j, min;
    TipoItem aux;

    for(i=2; i<=n; i++){
        aux = A[i];
        j = i-1;
	A[0] = aux;
        while(aux.Chave < A[j].Chave){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = aux;
    }

}


Complexidade O(n) melhor caso, O(n²) caso médio e pior caso

*Pega a posição i, e varre o vetor até a posição que tenha o valores maiores que ele (para trás);
desloca todo mundo pra frente e insere ele na posição que ficou vaga.