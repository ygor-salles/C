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


Complexidade O(n) melhor caso, O(n�) caso m�dio e pior caso

*Pega a posi��o i, e varre o vetor at� a posi��o que tenha o valores maiores que ele (para tr�s);
desloca todo mundo pra frente e insere ele na posi��o que ficou vaga.