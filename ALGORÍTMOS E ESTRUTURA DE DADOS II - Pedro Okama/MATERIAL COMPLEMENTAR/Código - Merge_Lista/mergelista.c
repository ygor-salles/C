#include <stdlib.h>
#include <stdio.h>
#include "mergelista.h"

/* Link list no */
struct Node{
	int valor;
	struct Node* prox;};
        
        int comp =0;
        int mov =0;

int aumentaComp(){
    comp = comp+1;
    return comp;}

int aumentaMov(){
    mov = mov+1;
    return mov;}
        
/* sorts the linked list by changing prox pointers (not valor) */
void MergeSort(struct Node** headRef){
struct Node* head = *headRef;
struct Node* a;
struct Node* b;

if ((head == NULL) || (head->prox == NULL)){
	return;}//Caso base, se head ==NULL e head->prox for NULL também, então não há mais nós para serem verificados

/* Split head into 'a' and 'b' sublists */
particiona(head, &a, &b); 

/* Recursively sort the sublists */
MergeSort(&a);
MergeSort(&b);

/* answer = merge the two sorted lists together */
*headRef = integra(a, b);}

struct Node* integra(struct Node* a, struct Node* b){
struct Node* result = NULL;
/* Base cases */
if (a == NULL)
	return(b);

else if (b==NULL)
	return(a);

/* Pick either a or b, and recur */
if (a->valor <= b->valor){
        result = a;
	result->prox = integra(a->prox, b);}

else{
        result = b;
	result->prox = integra(a, b->prox);}

return(result);}

/* UTILITY FUNCTIONS */
/* Split the nos of the given list into front and back halves,
	and return the two lists using the reference parameters.
	If the length is odd, the extra no should go in the front list.
	Uses the lebre/tarta pointer strategy. */
void particiona(struct Node* no, struct Node** frente, struct Node** pos){
	struct Node* lebre;
	struct Node* tarta;
	tarta = no;
	lebre = no->prox;

	/* Advance 'lebre' two nos, and advance 'tarta' one no */
	while (lebre != NULL){
	lebre = lebre->prox;
	if (lebre != NULL){
		tarta = tarta->prox;
		lebre = lebre->prox;}}

	/* 'tarta' is before the midpoint in the list, so split it in two
	at that point. */
	*frente = no;
	*pos = tarta->prox;
	tarta->prox = NULL;}

/* Function to print nos in a given linked list */
void mostraLista(struct Node *no){
    while(no!=NULL){
    printf("%d ", no->valor);
    no = no->prox;}}

/* Function to insert a no at the beginging of the linked list */
void construct(struct Node** antigo, int valor){
/* allocate no */
struct Node* novo = (struct Node*) malloc(sizeof(struct Node));

/* put in the valor */
novo->valor = valor;

/* link the old list off the new no */
novo->prox = (*antigo); 

/* move the head to point to the new no */
(*antigo) = novo;} 

Node * limpar(Node *a){
    Node *aux;
    while (a != NULL)
    {
        aux = a;
        a = a->prox;
        free (aux);
    }
    
return a = NULL;}
