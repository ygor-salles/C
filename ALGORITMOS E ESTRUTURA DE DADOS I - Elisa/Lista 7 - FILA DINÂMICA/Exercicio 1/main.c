
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "fila.h"

// funcao principal
int main(void) {
  
  Fila *se;
  Atendimento *xp, *xc, *np, *nc, *mesaN, *mesaX;
  int opcao, dado, contPreferencial = 0, contNegocial = 0, contCaixa = 0, n, id;
  char type, profile;
  Senha *aux, x;

  printf("Limite diário de atendimentos: ");
  scanf("%d", &n);

  se = criar_fila();
  
  for(int i = 0; i < n; i++)
    enfileirar(se,i);

  xp = criar_atendimento();
  xc = criar_atendimento();
  np = criar_atendimento();
  nc = criar_atendimento();
  mesaN = criar_atendimento();
  mesaX = criar_atendimento();

  printf("\nO que voce deseja: ");
  printf("\n1 - Retirar Senha");
  printf("\n2 - Chamar Senha");
  printf("\n=> ");
  scanf("%d",&opcao);

  int i = 0;
  if(opcao == 1){
      for(int i = 0; i < n; i++){
        printf("\n\nAtendimento: %d\n", i + 1);
        printf("\nTipo de atendimento: (X)Caixa (N)Negociavel: ");
        scanf("\n%c", &type);
        printf("\nPerfil do cliente: (P)Preferencial (C)Convencional: ");
        scanf("\n%c", &profile);

        if(type == 'x' && profile == 'p'){
          dado = desenfileirar(se);
          enfileirarAtendimento(xp, dado, 'x', 'p');
          imprimirAtendimento(xp);
        }
        if(type == 'x' && profile == 'c'){
          dado = desenfileirar(se);
          enfileirarAtendimento(xc, dado, 'x', 'c');
          imprimirAtendimento(xc);
        }
        if(type == 'n' && profile == 'p'){
          dado = desenfileirar(se);
          enfileirarAtendimento(np, dado, 'n', 'p');
          imprimirAtendimento(np);
        }
        if(type == 'n' && profile == 'c'){
          dado = desenfileirar(se);
          enfileirarAtendimento(nc, dado, 'n', 'c');
          imprimirAtendimento(nc);
        }
      }
  }

  printf("\n");
  int aleatorio;
  while(xp->tamanho > 0 || xc->tamanho > 0 || np->tamanho > 0 || nc->tamanho > 0)
  {
    aleatorio = rand() % 2;
    if(aleatorio == 1)
      type = 'n';
    else
      type = 'x';
    //Atendimento caixa
    if(type == 'x'){
      if(contPreferencial == 2){
        contPreferencial = 0;
        id = buscarAtendimento(xc,mesaX);
      }else{
      id = buscarAtendimento(xp,mesaX);
      contPreferencial++;
      }
      
      if(id == 1) contCaixa++;
    }
    //Atendimento negocial
    if(type == 'n'){
      if(contPreferencial == 2){
        contPreferencial = 0;
        id = buscarAtendimento(nc,mesaN);
      }else{
      id = buscarAtendimento(np,mesaN);
      contPreferencial++;
      }
      
      if(id == 1) contNegocial++;
    }

      //if(id == 1) printf("\nSenha: %c%c%d\n",x.tipo, x.perfil, x.senha);
  }

  imprimir_senha_por_mesa(mesaN, 1);
  printf("\n");
  imprimir_senha_por_mesa(mesaX, 0);
  printf("\nNegocial: %d\nCaixa: %d\n",contNegocial,contCaixa);

  liberar_fila(se);
  liberar_atendimento(xp);
  liberar_atendimento(xc);
  liberar_atendimento(np);
  liberar_atendimento(nc);
  
  printf("\nFinalizando...\n");
  return 0;
}
