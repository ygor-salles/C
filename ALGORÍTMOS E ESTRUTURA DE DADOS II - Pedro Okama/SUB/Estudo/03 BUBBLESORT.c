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

Complexidade O(n) melhor caso, O(n�) caso m�dio e pior caso

Come�a do in�cio e compara seu elemento com o pr�ximo da frente, se o elemento comparado for maior 
que o seu pr�ximo ambos trocam de posi��o entre si,  m�todo bolha.