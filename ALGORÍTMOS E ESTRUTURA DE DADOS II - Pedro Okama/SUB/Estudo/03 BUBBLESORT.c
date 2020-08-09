BUBBLESORT

void bubbleSort(TipoItem *V, int n)
{
    int i, j;
    TipoItem aux;

    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            if (V[j].Chave > V[j+1].Chave) {
                aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }
}

Complexidade O(n) melhor caso, O(n²) caso médio e pior caso

Começa do início e compara seu elemento com o próximo da frente, se o elemento comparado for maior 
que o seu próximo ambos trocam de posição entre si,  método bolha.