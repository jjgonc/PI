// 1
int length (LInt l){
    int length = 0;
    if (l == NULL) return 0; 
    else{ 
        while (l != NULL){
          length++;
          l = l->prox;
    }
    }
    return length;
}


// 2
void freeList (LInt l){
    LInt tmp;
    while (l->prox != NULL){
   		 tmp = l;
   		 l=l->prox;
    	 free (tmp);
 	  }
}

// 3 
void freeList (LInt l){
    LInt tmp;
    while (l->prox != NULL){
   		 tmp = l;
   		 l=l->prox;
    		free (tmp);
 	  }
}

// 4

#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}



LInt reverseL(LInt l) {
    LInt next = NULL;
    LInt aux;
    
    if (l == NULL)      //sem isto dava segmentation fault
		return l;
		
    while(aux != NULL) {  //tambem dava: while (l != NULL) { ...
        aux = l->prox;
        l->prox = next;
        next = l;
        l = aux;
    }
    return next;        //atenção aqui
}





/*

10 TESTES CORRETOS, MAS NAO SEI SE SERIA POSSIVEL FAZER ASSIM 


LInt reverseL (LInt l){
    LInt ant=NULL;
    LInt prox;
    LInt atual=l;
    while(atual != NULL){
        prox=atual->prox;
        atual->prox=ant;
        ant=atual;
        atual=prox;
    }
    l=ant;
    return l;
}

*/

// 5 

/*

void insertOrd (LInt* l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    LInt prev = NULL;
    for(;*l && (*l)->valor < x; prev = (*l), l = &((*l)->prox));                    //EXPLICAR ISTO
    if(prev) {
        new->prox = (*l);
        prev->prox = new;
    }
    else {
        new->prox = (*l);
        *l = new;
    }
}

*/




void insertOrd (LInt* l, int x) {
    LInt list = *l;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;                                 //lista so com o valor x
    new->prox = NULL;
    if(list->valor > x) {                           //se o valor da cabeça for maior que x coloca-se o x ja no inicio
        *l = new;                                   //l passa a ser o new (fica com o valor de x)
        new->prox = list;                           //e coloca-se logo a seguir a lista toda que foi dada (x:lista)
    }
    else {
        while(list->prox) {                         //enquanto list->prox for != NULL
            LInt next = list->prox;                 //tirar a cabeça à lista
            if(next->valor > x) {                   //se a head da cauda for maior que que x
                list->prox = new;                   //deixamos o que foi percorrido ate agora e colocamos no prox o x
                new->prox = next;                   //e a seguir ao new colocamos o restante da lista
                break;
            }
            list = list->prox;
            next = next->prox;              //PARA QUE SERVE ISTO????
        }
        list->prox = new;
    }
}



/*

http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A%20%20insertOrd%20%28%26lista,%2010%29%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false

*/  

/*
void insertOrd (LInt* l, int x) {
    LInt lista = *l; 
    LInt maiores;
    LInt nodo = malloc (sizeof (struct lligada));
         nodo->valor = x;
         nodo->prox = NULL;
    
    if (lista->valor >= x) {
      *l = nodo; 
      nodo->prox = lista;
    }
    while (lista->prox != NULL && lista->prox->valor < x) {
        lista = lista->prox;
    }
    maiores = lista->prox;
    nodo->prox = maiores;
    lista->prox = nodo;
}

*/


// 6



int removeOneOrd (LInt *l, int x){
    LInt ant;
    LInt atual;
    atual = *l;
    
    if (atual == NULL) return 1;
    
    if (atual->valor == x) { 
    *l = (*l)->prox;
    return 0;
    }
    
    while (atual != NULL){
       if (atual->valor == x){
            ant->prox = atual->prox;
            return 0;
        } 
        ant = atual;
        atual = atual->prox;
        
        
    }
    return 1;
}



/*

http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0Aint%20removeOneOrd%20%28LInt%20*%20lista,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20ant,%20atual%3B%0A%0A%20%20%20%20atual%20%3D%20*lista%3B%0A%0A%20%20%20%20if%20%28atual%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%201%3B%0A%0A%20%20%20%20if%20%28atual-%3Evalor%20%3D%3D%20x%29%20%7B%0A%20%20%20%20%20%20%20%20*lista%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20while%20%28atual-%3Eprox%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20ant%20%3D%20atual%3B%0A%20%20%20%20%20%20%20%20atual%20%3D%20atual-%3Eprox%3B%0A%0A%20%20%20%20%20%20%20%20if%20%28atual-%3Evalor%20%3D%3D%20x%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant-%3Eprox%20%3D%20atual-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%201%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false


/*

//DA SEG FAULT (MAS TANTO NO TERMINAL COMO NO PYTHON TUTOR DÁ DIREITO)

int removeOneOrd (LInt *l, int x){
    LInt lista = *l;
    int r = 1;
    
    if (lista->valor == x) {
        LInt tmp = lista;
        lista = lista->prox;
        free (tmp);
        *l = lista;
    }
    
    if (lista == NULL) {
        return 1;
    }
    while (lista->prox != NULL) {
    if (lista->prox->valor == x) {
        lista->prox = lista->prox->prox;
        return 0;
    }
    lista = lista->prox;
    }
    return r;
}

*/


// 7



void merge (LInt *r, LInt l1, LInt l2){
    LInt lista = newLInt (3, NULL);  // Cria-se uma lista com um nodo "falso" que é removido no fim   (por exemplo o 3)
    *r =lista;                      // ter um apontador para percorrer a lista (???)
    
    while (l1 != NULL && l2 != NULL){
        
        if (l1->valor < l2->valor){
            lista->prox = l1;               //DUVIDA : nao devia ser o valor??? e nao a lligada toda
            l1 = l1->prox;
        }
        
        else {
            lista->prox = l2;
            l2 = l2->prox;
        }
        
        lista = lista->prox;
    }
    if (l1==NULL) 
        lista->prox = l2;
    else if (l2==NULL) 
        lista->prox = l1;
    
    lista = *r;         //passos para a remoçao do nodo falso que foi criado no inicio   (lista guarda o nodo a ser removido)
    *r = lista->prox;   //avançar a lista 1 nodo para a frente (para eliminar o do inicio)
    free (lista);       //o nodo 3 é libertado da memoria
    
}






// 8

void insere (LInt *l, LInt r) {
     while ((*l)!=NULL) 
     l=&((*l)->prox);
     (*l)=r;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    
     LInt aux;
     while(l!=NULL){
          aux=l->prox;
          l->prox=NULL;
          if(l->valor < x) insere(mx,l);
          else insere(Mx,l);
          l=aux;
     }
}



OUTRO MODO: 

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt min, max;
    min = newLInt (3, NULL);
    max = newLInt (0, NULL);
    *mx = min;
    *Mx = max;
     LInt aux;
     while(l!=NULL){
          if(l->valor < x) {
              min->prox = l;
              min = min->prox;
          }
          else {
              max->prox = l;
              max = max->prox;
          }
          l = l->prox;
     }
     min->prox = NULL;
     max->prox = NULL;
     
     LInt headmx = *mx;
     *mx = headmx->prox;
     free (headmx);
     
     LInt headMx = *Mx;
     *Mx = headMx->prox;
     free (headMx);
}

// 9


int verificatamanho (LInt l){
    int n=0;
    while (l!=NULL){
        l = l->prox;
        n++;
    }
    return n;
}


//Nesta funçao, devolve-se a primeira parte da lista, e *l fica a apontar para a segunda parte!
//NOTA: ao dividir a meio um inteiro, ficamos sempre com o valor arrendondado "para baixo" às unidades!

LInt parteAmeio (LInt *l){
    LInt start = *l;  //fica a apontar para o inicio da lista
    LInt current = *l;  //anda com a lista
    int size;
    size = verificatamanho (current);
    
    /* Se o comprimento da lista for igual a 1 significa que a lista x = {8} parte-se em
       y = {8} e x = {}, logo x (o return) passa a ser um apontador nulo */ 
    if (size <= 1) return NULL;
    
    
    
    /* Percorre a lista até ao ultimo elemento que fica em y */ 
    int meio = size/2;
    int i;
    for (i=0; i+1 < meio ; i++){
        current = current->prox;
    }
    
    
    *l = current->prox;   //a lista l passa a apontar para o começo da segunda lista (lista x, como diz no enunciado)
    current->prox = NULL;   // O ultimo elemento de y corta a ligacão à lista x
    
    return start;
}




// 10



int removeAll (LInt *head, int x){
    int contaRM = 0; // Contador de número removidos

    /* Loop que atualizada o apontador *head enquanto o primeiro elemento da lista ligada
       é igual ao número a ser removido */
    while (*head != NULL){
        if ((*head)->valor == x){
            *head = (*head)->prox;
            contaRM++;
        } else {
            break;
        } 
    } 

    /* Se no final do loop *head for um apontador nulo (ex: todos os elementos foram removidos)
       a função acaba prematuramente */
    if (*head == NULL){
        return contaRM;
    }

    LInt current = *head; // Apontador que percorre a lista
    LInt prev; // Apontador sempre 1 indice atrás de current

    /* Loop que percorre o resto da lista e:
          - Se o valor guardado em current é x, então current avança 1 nodo para a frente, 
          e prev->prox passa a apontar para esse nodo. contaRM aumenta 1
          - Caso contrário prev e current andam ambos um nodo para a frente */
    while (current != NULL){
        if (current->valor == x){
            current = current->prox;
            prev->prox = current;
            contaRM++;
        } else {
            prev = current;
            current = current->prox;
        } 
    } 
    return contaRM;
}


//            http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0Aint%20removeOneOrd%20%28LInt%20*%20lista,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20ant,%20atual%3B%0A%0A%20%20%20%20atual%20%3D%20*lista%3B%0A%0A%20%20%20%20if%20%28atual%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%201%3B%0A%0A%20%20%20%20if%20%28atual-%3Evalor%20%3D%3D%20x%29%20%7B%0A%20%20%20%20%20%20%20%20*lista%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20while%20%28atual-%3Eprox%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20ant%20%3D%20atual%3B%0A%20%20%20%20%20%20%20%20atual%20%3D%20atual-%3Eprox%3B%0A%0A%20%20%20%20%20%20%20%20if%20%28atual-%3Evalor%20%3D%3D%20x%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant-%3Eprox%20%3D%20atual-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%200%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%201%3B%0A%7D%0A%0A/*%0A%0Aint%20removeAll%20%28LInt%20*l,%20int%20x%29%7B%0A%20%20%20%20LInt%20current%20%3D%20*l%3B%0A%20%20%20%20LInt%20ant%20%3D%20*l%3B%0A%20//%20%20%20LInt%20ant%20%3D%20*l%3B%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28current-%3Evalor%20!%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%20-1%3B%0A%7D%0A*/%0A%0Aint%20removeAll%20%28LInt%20*head,%20int%20x%29%7B%0A%20%20%20%20int%20contaRM%20%3D%200%3B%20//%20Contador%20de%20n%C3%BAmero%20removidos%0A%0A%20%20%20%20/*%20Loop%20que%20atualizada%20o%20apontador%20*head%20enquanto%20o%20primeiro%20elemento%20da%20lista%20ligada%0A%20%20%20%20%20%20%20%C3%A9%20igual%20ao%20n%C3%BAmero%20a%20ser%20removido%20*/%0A%20%20%20%20while%20%28*head%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28%28*head%29-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20*head%20%3D%20%28*head%29-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%0A%20%20%20%20/*%20Se%20no%20final%20do%20loop%20*head%20for%20um%20apontador%20nulo%20%28ex%3A%20todos%20os%20elementos%20foram%20removidos%29%0A%20%20%20%20%20%20%20a%20fun%C3%A7%C3%A3o%20acaba%20prematuramente%20*/%0A%20%20%20%20if%20%28*head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20contaRM%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20LInt%20current%20%3D%20*head%3B%20//%20Apontador%20que%20percorre%20a%20lista%0A%20%20%20%20LInt%20prev%3B%20//%20Apontador%20sempre%201%20indice%20atr%C3%A1s%20de%20current%0A%0A%20%20%20%20/*%20Loop%20que%20percorre%20o%20resto%20da%20lista%20e%3A%0A%20%20%20%20%20%20%20%20%20%20-%20Se%20o%20valor%20guardado%20em%20current%20%C3%A9%20x,%20ent%C3%A3o%20current%20avan%C3%A7a%201%20nodo%20para%20a%20frente,%20%0A%20%20%20%20%20%20%20%20%20%20e%20prev-%3Eprox%20passa%20a%20apontar%20para%20esse%20nodo.%20contaRM%20aumenta%201%0A%20%20%20%20%20%20%20%20%20%20-%20Caso%20contr%C3%A1rio%20prev%20e%20current%20andam%20ambos%20um%20nodo%20para%20a%20frente%20*/%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28current-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev-%3Eprox%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20contaRM%3B%0A%7D%0A%0Aint%20skipNodo%20%28LInt%20l,%20int%20x%29%7B%0A%20%20int%20i%3B%0A%20%20for%20%28i%3D1%3B%20i!%3Dx%3B%20i%2B%2B%29%7B%0A%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%7D%0A%20%20l-%3Eprox%20%3D%20l-%3Eprox-%3Eprox%3B%0A%20%20return%201%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A%20%20removeAll%20%28%26lista%20,%205%29%3B%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false


/*


int removeAll (LInt *l, int x) {
    int n = 0;
    LInt prev = NULL;
    while (*l) {
        if ((*l)->valor == x) {
            if (!prev) (*l) = (*l)->prox;           // (!prev) é o mesmo que (prex == NULL)
            else prev->prox = (*l)->prox;
            n++;
        }
        else {
            prev = (*l);
            l = &(*l)->prox;
        }
    }
    return n;
}

*/




// 11  


int length (LInt head){
    int i;
    for (i = 0; head != NULL; i++){
    	head = head->prox;
    }
    return i;
}

/* Ver pergunta25 */
void removeInt (LInt head, int x){
	LInt prev = head; 
	head = head->prox; 
	while (head != NULL){
		if (head->valor == x){
			prev->prox = head->prox;
			free(head);
			head = prev->prox;
		} 
		else {
			prev = prev->prox;
			head = head->prox;
		} 
	} 
}



int removeDups (LInt *head){
	int sizeStart = length(*head); // tamanho inicial
	if (sizeStart == 0){
		return 0;
	}
	LInt cur = *head;

	/* remove-se os repetidos */
	while (cur != NULL){
    	removeInt (cur, cur->valor);
    	cur = cur->prox;
    } 
    int sizeFinal = length(*head); // tamanho final
    return (sizeFinal - sizeStart); // removidos = tamanho final - inicial
}



//12


//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0Aint%20removeAll%20%28LInt%20*head,%20int%20x%29%7B%0A%20%20%20%20int%20contaRM%20%3D%200%3B%20//%20Contador%20de%20n%C3%BAmero%20removidos%0A%0A%20%20%20%20/*%20Loop%20que%20atualizada%20o%20apontador%20*head%20enquanto%20o%20primeiro%20elemento%20da%20lista%20ligada%0A%20%20%20%20%20%20%20%C3%A9%20igual%20ao%20n%C3%BAmero%20a%20ser%20removido%20*/%0A%20%20%20%20while%20%28*head%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28%28*head%29-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20*head%20%3D%20%28*head%29-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%0A%20%20%20%20/*%20Se%20no%20final%20do%20loop%20*head%20for%20um%20apontador%20nulo%20%28ex%3A%20todos%20os%20elementos%20foram%20removidos%29%0A%20%20%20%20%20%20%20a%20fun%C3%A7%C3%A3o%20acaba%20prematuramente%20*/%0A%20%20%20%20if%20%28*head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20contaRM%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20LInt%20current%20%3D%20*head%3B%20//%20Apontador%20que%20percorre%20a%20lista%0A%20%20%20%20LInt%20prev%3B%20//%20Apontador%20sempre%201%20indice%20atr%C3%A1s%20de%20current%0A%0A%20%20%20%20/*%20Loop%20que%20percorre%20o%20resto%20da%20lista%20e%3A%0A%20%20%20%20%20%20%20%20%20%20-%20Se%20o%20valor%20guardado%20em%20current%20%C3%A9%20x,%20ent%C3%A3o%20current%20avan%C3%A7a%201%20nodo%20para%20a%20frente,%20%0A%20%20%20%20%20%20%20%20%20%20e%20prev-%3Eprox%20passa%20a%20apontar%20para%20esse%20nodo.%20contaRM%20aumenta%201%0A%20%20%20%20%20%20%20%20%20%20-%20Caso%20contr%C3%A1rio%20prev%20e%20current%20andam%20ambos%20um%20nodo%20para%20a%20frente%20*/%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28current-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev-%3Eprox%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20contaRM%3B%0A%7D%0A%0A/*%0Aint%20skipNodo%20%28LInt%20l,%20int%20x%29%7B%0A%20%20int%20i%3B%0A%20%20for%20%28i%3D1%3B%20i!%3Dx%3B%20i%2B%2B%29%7B%0A%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%7D%0A%20%20l-%3Eprox%20%3D%20l-%3Eprox-%3Eprox%3B%0A%20%20return%201%3B%0A%7D%0A*/%0A%0A%0A//Fun%C3%A7ao%20que%20devolve%20o%20indice%20onde%20esta%20%20maior%20elemento%20da%20lista.%0Aint%20verificaMaior%20%28LInt%20l%29%7B%0A%20%20%20%20int%20valorMaior%20%3D%20%28l-%3Evalor%29%3B%0A%20%20%20%20while%20%28l%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28l-%3Evalor%20%3E%20valorMaior%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20valorMaior%20%3D%20l-%3Evalor%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20valorMaior%3B%0A%7D%0A%0A%0Aint%20removeMaiorL%20%28LInt%20*l%29%7B%0A%20%20%20%20int%20r%3B%0A%20%20%20//%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20ant%20%3D%20*l%3B%0A%20%20%20%20LInt%20current%20%3D%20*l%3B%0A%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%0A%20%20%20%20int%20valor%20%3D%20verificaMaior%20%28ant%29%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28current-%3Evalor%20!%3D%20valor%29%20%7B%0A%20%20%20%20%20%20%20%20ant%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20ant-%3Eprox%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%0A%20%20%20%20%0A%20%20%20%20return%20valor%3B%0A%7D%0A%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A//removeAll%20%28%26lista%20,%205%29%3B%20%0A%20%20removeMaiorL%20%28%26lista%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false





//Funçao que devolve o indice onde esta  maior elemento da lista.
int verificaMaior (LInt l){
    int valorMaior = (l->valor);
    while (l != NULL){
        if (l->valor > valorMaior){
            valorMaior = l->valor;
        }
        l = l->prox;
    }
    return valorMaior;
}


int removeMaiorL (LInt *l){
    int r;
    LInt ant = *l;
    LInt current = *l;
    current = current->prox;
    
    int valor = verificaMaior (ant);
    
    while (current->valor != valor) {
        ant = current;
        current = current->prox;
    }
    ant->prox = current->prox;
    
    
    return valor;
}





/*
//OUTRO MODO:

int verificaMaior (LInt *l) {
    LInt curr = *l;
    int max = curr->valor;
    while (curr) {
        if (curr->valor > max) max = curr->valor;
        
        curr = curr->prox;
    }
    return max;
}



int removeMaiorL (LInt *l){
    int maior = verificaMaior(l);           //ATENCAO AQUI (AO QUE É PASSADO)
    LInt current = *l;
    while (current->prox->valor != maior) {
        current = current->prox;
    }
    current->prox = current->prox->prox;
    return maior;
}



*/


// 13




void init (LInt *l){
    LInt lista = *l;
    LInt current = *l;
    if (lista->prox == NULL) {
        free (lista);
        *l = NULL;
    }
    
    else{
    while (lista->prox->prox != NULL){
        lista = lista->prox;
        current = current->prox;
    }
    lista = lista->prox;
    free (lista);
    current->prox = NULL;
    }
}



//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0ALInt%20newLInt%20%28int%20v,%20LInt%20t%29%7B%0A%20%20%20%20LInt%20new%20%3D%20%28LInt%29%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28new!%3DNULL%29%20%7B%0A%20%20%20%20%20%20%20%20new-%3Evalor%20%3D%20v%3B%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%20%3D%20t%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20new%3B%0A%7D%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0Aint%20removeAll%20%28LInt%20*head,%20int%20x%29%7B%0A%20%20%20%20int%20contaRM%20%3D%200%3B%20//%20Contador%20de%20n%C3%BAmero%20removidos%0A%0A%20%20%20%20/*%20Loop%20que%20atualizada%20o%20apontador%20*head%20enquanto%20o%20primeiro%20elemento%20da%20lista%20ligada%0A%20%20%20%20%20%20%20%C3%A9%20igual%20ao%20n%C3%BAmero%20a%20ser%20removido%20*/%0A%20%20%20%20while%20%28*head%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28%28*head%29-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20*head%20%3D%20%28*head%29-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%0A%20%20%20%20/*%20Se%20no%20final%20do%20loop%20*head%20for%20um%20apontador%20nulo%20%28ex%3A%20todos%20os%20elementos%20foram%20removidos%29%0A%20%20%20%20%20%20%20a%20fun%C3%A7%C3%A3o%20acaba%20prematuramente%20*/%0A%20%20%20%20if%20%28*head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20contaRM%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20LInt%20current%20%3D%20*head%3B%20//%20Apontador%20que%20percorre%20a%20lista%0A%20%20%20%20LInt%20prev%3B%20//%20Apontador%20sempre%201%20indice%20atr%C3%A1s%20de%20current%0A%0A%20%20%20%20/*%20Loop%20que%20percorre%20o%20resto%20da%20lista%20e%3A%0A%20%20%20%20%20%20%20%20%20%20-%20Se%20o%20valor%20guardado%20em%20current%20%C3%A9%20x,%20ent%C3%A3o%20current%20avan%C3%A7a%201%20nodo%20para%20a%20frente,%20%0A%20%20%20%20%20%20%20%20%20%20e%20prev-%3Eprox%20passa%20a%20apontar%20para%20esse%20nodo.%20contaRM%20aumenta%201%0A%20%20%20%20%20%20%20%20%20%20-%20Caso%20contr%C3%A1rio%20prev%20e%20current%20andam%20ambos%20um%20nodo%20para%20a%20frente%20*/%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28current-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev-%3Eprox%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20contaRM%3B%0A%7D%0A%0A/*%0Aint%20skipNodo%20%28LInt%20l,%20int%20x%29%7B%0A%20%20int%20i%3B%0A%20%20for%20%28i%3D1%3B%20i!%3Dx%3B%20i%2B%2B%29%7B%0A%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%7D%0A%20%20l-%3Eprox%20%3D%20l-%3Eprox-%3Eprox%3B%0A%20%20return%201%3B%0A%7D%0A*/%0A%0A%0Avoid%20init%20%28LInt%20*l%29%7B%0A%20%20%20%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20current%20%3D%20*l%3B%0A%20%20%20%20while%20%28lista-%3Eprox-%3Eprox%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20free%20%28lista%29%3B%0A%20%20%20%20current-%3Eprox%20%3D%20NULL%3B%0A%7D%0A%0A%0A%0A%0Avoid%20appendL%20%28LInt%20*l,%20int%20x%29%7B%0A%20%20%20%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20novo%3B%0A%20%20%20%20while%20%28lista-%3Eprox%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20novo%20%3D%20newLInt%20%28x,%20NULL%29%3B%0A%20%20%20%20lista-%3Eprox%20%3D%20novo%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A//removeAll%20%28%26lista%20,%205%29%3B%20%0A%20%20//init%20%28%26lista%29%3B%0A%20%20appendL%20%28%26lista,%209%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false



//14



void appendL (LInt *l, int x){
    LInt lista = *l;
    LInt novo = newLInt (x, NULL);
    
    
    if ((*l) == NULL){
        (*l) = novo;
    }
    
    else {
    while ((*l)->prox != NULL){
        (*l) = (*l)->prox;
    }
    (*l)->prox = novo;
    *l=lista;
    }
}



//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0ALInt%20newLInt%20%28int%20v,%20LInt%20t%29%7B%0A%20%20%20%20LInt%20new%20%3D%20%28LInt%29%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28new!%3DNULL%29%20%7B%0A%20%20%20%20%20%20%20%20new-%3Evalor%20%3D%20v%3B%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%20%3D%20t%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20new%3B%0A%7D%0A%0Avoid%20insertOrd%20%28LInt*%20l,%20int%20x%29%20%7B%0A%20%20%20%20LInt%20list%20%3D%20*l%3B%0A%20%20%20%20LInt%20new%20%3D%20malloc%28sizeof%28struct%20lligada%29%29%3B%0A%20%20%20%20new-%3Evalor%20%3D%20x%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//lista%20so%20com%20o%20valor%20x%0A%20%20%20%20new-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20if%28list-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20o%20valor%20da%20cabe%C3%A7a%20for%20maior%20que%20x%20coloca-se%20o%20x%20ja%20no%20inicio%0A%20%20%20%20%20%20%20%20*l%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//l%20passa%20a%20ser%20o%20new%20%28fica%20com%20o%20valor%20de%20x%29%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20list%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20coloca-se%20logo%20a%20seguir%20a%20lista%20toda%20que%20foi%20dada%20%28x%3Alista%29%0A%20%20%20%20%7D%0A%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20while%28list-%3Eprox%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//enquanto%20list-%3Eprox%20for%20!%3D%20NULL%0A%20%20%20%20%20%20%20%20%20%20%20%20LInt%20next%20%3D%20list-%3Eprox%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//tirar%20a%20cabe%C3%A7a%20%C3%A0%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20if%28next-%3Evalor%20%3E%20x%29%20%7B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//se%20a%20head%20da%20cauda%20for%20maior%20que%20que%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//deixamos%20o%20que%20foi%20percorrido%20ate%20agora%20e%20colocamos%20no%20prox%20o%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20new-%3Eprox%20%3D%20next%3B%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20//e%20a%20seguir%20ao%20new%20colocamos%20o%20restante%20da%20lista%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%20%20%20%20list%20%3D%20list-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20next%20%3D%20next-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20list-%3Eprox%20%3D%20new%3B%0A%20%20%20%20%7D%0A%7D%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0Aint%20removeAll%20%28LInt%20*head,%20int%20x%29%7B%0A%20%20%20%20int%20contaRM%20%3D%200%3B%20//%20Contador%20de%20n%C3%BAmero%20removidos%0A%0A%20%20%20%20/*%20Loop%20que%20atualizada%20o%20apontador%20*head%20enquanto%20o%20primeiro%20elemento%20da%20lista%20ligada%0A%20%20%20%20%20%20%20%C3%A9%20igual%20ao%20n%C3%BAmero%20a%20ser%20removido%20*/%0A%20%20%20%20while%20%28*head%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28%28*head%29-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20*head%20%3D%20%28*head%29-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20break%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%0A%20%20%20%20/*%20Se%20no%20final%20do%20loop%20*head%20for%20um%20apontador%20nulo%20%28ex%3A%20todos%20os%20elementos%20foram%20removidos%29%0A%20%20%20%20%20%20%20a%20fun%C3%A7%C3%A3o%20acaba%20prematuramente%20*/%0A%20%20%20%20if%20%28*head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20contaRM%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20LInt%20current%20%3D%20*head%3B%20//%20Apontador%20que%20percorre%20a%20lista%0A%20%20%20%20LInt%20prev%3B%20//%20Apontador%20sempre%201%20indice%20atr%C3%A1s%20de%20current%0A%0A%20%20%20%20/*%20Loop%20que%20percorre%20o%20resto%20da%20lista%20e%3A%0A%20%20%20%20%20%20%20%20%20%20-%20Se%20o%20valor%20guardado%20em%20current%20%C3%A9%20x,%20ent%C3%A3o%20current%20avan%C3%A7a%201%20nodo%20para%20a%20frente,%20%0A%20%20%20%20%20%20%20%20%20%20e%20prev-%3Eprox%20passa%20a%20apontar%20para%20esse%20nodo.%20contaRM%20aumenta%201%0A%20%20%20%20%20%20%20%20%20%20-%20Caso%20contr%C3%A1rio%20prev%20e%20current%20andam%20ambos%20um%20nodo%20para%20a%20frente%20*/%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20if%20%28current-%3Evalor%20%3D%3D%20x%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev-%3Eprox%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20contaRM%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20prev%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20contaRM%3B%0A%7D%0A%0A/*%0Aint%20skipNodo%20%28LInt%20l,%20int%20x%29%7B%0A%20%20int%20i%3B%0A%20%20for%20%28i%3D1%3B%20i!%3Dx%3B%20i%2B%2B%29%7B%0A%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%7D%0A%20%20l-%3Eprox%20%3D%20l-%3Eprox-%3Eprox%3B%0A%20%20return%201%3B%0A%7D%0A*/%0A%0A%0Avoid%20init%20%28LInt%20*l%29%7B%0A%20%20%20%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20current%20%3D%20*l%3B%0A%20%20%20%20while%20%28lista-%3Eprox-%3Eprox%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20free%20%28lista%29%3B%0A%20%20%20%20current-%3Eprox%20%3D%20NULL%3B%0A%7D%0A%0Avoid%20appendL%20%28LInt%20*l,%20int%20x%29%7B%0A%20%20%20%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20novo%3B%0A%20%20%20%20novo%20%3D%20newLInt%20%28x,%20NULL%29%3B%0A%20%20%20%20%0A%20%20%20%20%0A%20%20%20%20if%20%28%28*l%29%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20%28*l%29%20%3D%20novo%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20else%20%7B%0A%20%20%20%20while%20%28%28*l%29-%3Eprox%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20%28*l%29%20%3D%20%28*l%29-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20%28*l%29-%3Eprox%20%3D%20novo%3B%0A%20%20%20%20*l%3Dlista%3B%0A%20%20%20%20%7D%0A%7D%0A%0A/*%0Avoid%20appendL%20%28LInt%20*l,%20int%20x%29%7B%0A%20%20%20%20LInt%20lista%20%3D%20*l%3B%0A%20%20%20%20LInt%20novo%3B%0A%20%20%20%20while%20%28lista-%3Eprox%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20lista%20%3D%20lista-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20novo%20%3D%20newLInt%20%28x,%20NULL%29%3B%0A%20%20%20%20lista-%3Eprox%20%3D%20novo%3B%0A%7D%0A%0A*/%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A//removeAll%20%28%26lista%20,%205%29%3B%20%0A%20%20//init%20%28%26lista%29%3B%0A%20%20appendL%20%28%26lista,%209%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false



/*
//OUTRO MODO:
void appendL (LInt *l, int x){
    LInt current = *l;
    LInt novo = newLInt (x, NULL);
    
    if (current == NULL) {
        *l = novo;
    }
    
    else {
        while (current->prox != NULL) {
            current = current->prox;
        }
        current->prox = novo;
        
    }
}
*/


//15

void concatL (LInt *a, LInt b){
    LInt lista = *a;
    if (*a == NULL) *a = b;
    else {
    while (lista->prox != NULL){
        lista = lista->prox;
    }
    lista->prox = b;
    }
}



//16

http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0ALInt%20newLInt%20%28int%20v,%20LInt%20t%29%7B%0A%20%20%20%20LInt%20new%20%3D%20%28LInt%29%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28new!%3DNULL%29%20%7B%0A%20%20%20%20%20%20%20%20new-%3Evalor%20%3D%20v%3B%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%20%3D%20t%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20new%3B%0A%7D%0A%0ALInt%20cloneL%20%28LInt%20head%29%7B%0A/*%20%20%20%20if%20%28head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20NULL%3B%0A%20%20%20%20%7D*/%0A%20%20%20%20LInt%20new%20%3D%20newLInt%28head-%3Evalor,%20NULL%29%3B%20%0A%20%20%20%20LInt%20current%20%3D%20head%3B%20%20%20%20%0A%20%20%20%20LInt%20currentNew%20%3D%20new%3B%20%20%20%0A%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20if%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20currentNew-%3Eprox%20%3D%20newLInt%28current-%3Evalor,%20NULL%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20currentNew%20%3D%20currentNew-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%20%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20new%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A%20%20cloneL%20%28lista%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false


//17


LInt cloneRev (LInt l){
  //  LInt current = l;
    LInt new = NULL;
            
    if (l == NULL) return NULL;
    else {
        while (l != NULL){
            new = newLInt (l->valor, new);
            l = l->prox;
        }
    }
    return new;
}

//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0ALInt%20newLInt%20%28int%20v,%20LInt%20t%29%7B%0A%20%20%20%20LInt%20new%20%3D%20%28LInt%29%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28new!%3DNULL%29%20%7B%0A%20%20%20%20%20%20%20%20new-%3Evalor%20%3D%20v%3B%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%20%3D%20t%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20new%3B%0A%7D%0A%0ALInt%20cloneRev%20%28LInt%20head%29%7B%0A%20%20%20%20LInt%20current%20%3D%20head%3B%20//%20Apontador%20que%20percorre%20a%20lista%0A%0A%20%20%20%20/*%20Se%20head%20for%20um%20apontador%20nulo%20a%20fun%C3%A7%C3%A3o%20retorna%20um%20apontador%20nulo%20*/%0A%20%20%20%20if%20%28head%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20return%20NULL%3B%0A%20%20%20%20%7D%0A%20%20%20%20LInt%20new%20%3D%20NULL%3B%20//%20Apontador%20da%20nova%20lista%0A%0A%20%20%20%20/*%20A%20fun%C3%A7%C3%A3o%20newLInt%20insere%20o%20novo%20nodo%20sempre%20antes%20da%20lista,%20assim%20percorremos%20a%20lista%0A%20%20%20%20current%20e%20vamos%20inserindo%20os%20n%C3%BAmeros%20em%20new%20do%20fim%20para%20o%20in%C3%ADcio%20atualizando%20sempre%20o%0A%20%20%20%20apontador%20new,%20que%20no%20final%20do%20loop%20aponta%20para%20a%20posi%C3%A7%C3%A3o%20inicial%20*/%0A%20%20%20%20while%20%28current%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20new%20%3D%20newLInt%28current-%3Evalor,%20new%29%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%7D%20%0A%20%20%20%20return%20new%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B5,%206,%207,%205,%208,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%205%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A%20%20cloneRev%20%28lista%29%3B%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false


//18

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

int maximo (LInt l){
    int maior = l->valor;
    while (l != NULL){
        if (l->valor > maior) maior = l->valor;
        else l = l->prox;
    }
    return maior;
}


//19



int sizeLista (LInt l){
    int n = 0;
    while (l){
        l=l->prox;
        n++;
    }
    return n;
}



int take (int n, LInt *l){
    LInt current = *l;      //vai ser para libertar
    LInt proxANull = *l;    //vai ficar no nodo anterior
    LInt listaTamanho = *l;   //testar o tamanho da lista
    int i;
    int tamanho = sizeLista (listaTamanho);
    
    if (current == NULL) return 0;      //se a lista for vazia, entao tem tamanho zero
    
    if (tamanho < n) return tamanho;       //Se a lista tiver n ou menos nodos, a função não altera a lista.
    
    if (n==0) {         //se pedir para partir no inicio, a lista fica sem nada
        *l = NULL;
    }
    
    for (i=0; i < n && current != NULL; i++){
        proxANull = current;
        current = current->prox;
    }
    free (current);
    proxANull->prox = NULL;
    return n;
}


//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0Aint%20take%20%28int%20n,%20LInt%20*l%29%7B%0A%20%20%20%20LInt%20current%20%3D%20*l%3B%0A%20%20%20%20LInt%20proxANull%20%3D%20*l%3B%0A%20%20%20%20int%20i%3B%0A%20%20%20%20if%20%28n%3D%3D0%29%20%7B%0A%20%20%20%20%20%20%20%20*l%20%3D%20NULL%3B%0A%20%20%20%20%7D%0A%20%20%20%20for%20%28i%3D0%3B%20i%20!%3D%20n%20%26%26%20current%20!%3D%20NULL%3B%20i%2B%2B%29%7B%0A%20%20%20%20%20%20%20%20proxANull%20%3D%20current%3B%0A%20%20%20%20%20%20%20%20current%20%3D%20current-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20free%20%28current%29%3B%0A%20%20%20%20proxANull-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20return%20n%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B61,%2062,%2063,%2064,%2065,%2066,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%206%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A%20%20take%20%285,%26lista%29%3B%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false





//20



int drop (int n, LInt *l){
    int i = 0;
    LInt curr = *l;
    LInt ant = *l;
    while (i<n && curr != NULL) {
        ant = curr;
        curr=curr->prox;
        free (ant);
        i++;
    }
    *l = curr;
    return i;
}




/*
//OUTRO MODO :


int tamanho (LInt lista) {
    int i = 0;
    while (lista) {
        lista = lista->prox;
        i++;
    }
    return i;
}




int drop (int n, LInt *l){
    int i = 0;
    LInt current = *l;
    int tam = tamanho (current);
    if ((*l) == NULL) return 0;
    
    else if (tam < n) {
        free (current);
        *l = NULL;
        return tam;
    }
    else {
    while (i<n && (*l) != NULL) {
        (*l) = (*l)->prox;
        i++;
    }
    }
    return n;
}

*/


//21

LInt NForward (LInt l, int N){
    int i =0;
    while ((l != NULL) && (i!=N)){
        l = l->prox;
        i++;
    }
    return l;               // ATENÇAO
}


//22

int listToArray (LInt l, int v[], int N){
    int i = 0;
    while (l != NULL && i != N) { 
        v[i] = l->valor;
        i++;
        l = l->prox;
    }
    return i;
}


//23



LInt arrayToList (int v[], int N){
	// Se v for um array vazio, a função retorna um apontador nulo 
    if (N == 0){
        return NULL;
    }
    LInt head = newLInt(v[0], NULL); // Cria-se o primeiro nodo com o primeiro elemento de v
    LInt current = head; // Apontador que percorre a lista

    // Loop que insere na posição a seguir ao nodo current um novo nodo com valor v[i], depois current passa a apontar para o nodo seguinte. Nota: o loop começa em i = 1 porque ao inicializar head é lhe atribuido logo uma componente valor correspondente a v[0] 
    int i;
    for (i = 1; i < N; i++){
        current->prox = newLInt(v[i], NULL);
        current = current->prox;
    } 
    return head; // É retornado o apontador para o primeiro nodo da lista
}





/*
LInt arrayToList (int v[], int N){
    int i =N-1;
    LInt old = NULL, novo;
    
    while (i >= 0){
        novo = malloc( sizeof (struct lligada));
        novo->valor = v[i];
        novo->prox = old;
        old = novo;
        i--;
    }
    return old;
}

*/



//24



LInt somasAcL (LInt l) {
    
    if (l == NULL) return NULL;   //descartamos logo a possibilidade de ser nulo
    
    int count = l->valor;         //contador das somas
    LInt sum;                     //lista ligada com os somatorios
    sum = newLInt (count, NULL);  //iniciar a lligada
    LInt inicio = sum;            //endereço do primeiro nodo da lista que vamos devolver
    LInt original = l;            //uma vez que a lista l tem que permanecer inalterada
    original = original->prox;     
    
    while (original != NULL) {
        count += original->valor;
        sum->prox = newLInt (count , NULL);
        sum = sum->prox;
        original = original->prox;
    }
    return inicio;
}






/*
LInt somasAcL (LInt l) {
    int count = l->valor;
    LInt listaAcc = newLInt (l->valor, NULL);
    l = l->prox;
    LInt head = listaAcc;
    
    while (l != NULL){
        count += l->valor;
        listaAcc->prox = newLInt (count, NULL);
        listaAcc = listaAcc->prox;
        l=l->prox;
    }
    return head;
}
*/
//      http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0ALInt%20newLInt%20%28int%20v,%20LInt%20t%29%7B%0A%20%20%20%20LInt%20new%20%3D%20%28LInt%29%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28new!%3DNULL%29%20%7B%0A%20%20%20%20%20%20%20%20new-%3Evalor%20%3D%20v%3B%0A%20%20%20%20%20%20%20%20new-%3Eprox%20%20%3D%20t%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20new%3B%0A%7D%0A%0ALInt%20somasAcL%20%28LInt%20l%29%20%7B%0A%20%20%20%20int%20count%20%3D%20l-%3Evalor%3B%0A%20%20%20%20LInt%20listaAcc%20%3D%20newLInt%20%28l-%3Evalor,%20NULL%29%3B%0A%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%20%20LInt%20head%20%3D%20listaAcc%3B%0A%20%20%20%20while%20%28l%20!%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20count%20%2B%3D%20l-%3Evalor%3B%0A%20%20%20%20%20%20%20%20listaAcc-%3Eprox%20%3D%20newLInt%20%28count,%20NULL%29%3B%0A%20%20%20%20%20%20%20%20listaAcc%20%3D%20listaAcc-%3Eprox%3B%0A%20%20%20%20%20%20%20%20l%3Dl-%3Eprox%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20head%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B1,2,3,4,%2065,%2066,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%204%29%3B%0A//%20%20removeOneOrd%20%28%26lista,%206%29%3B%0A%20%20somasAcL%20%28lista%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false




//25

void removeInt (LInt head, int n) {
    LInt ant = head;
    head = head->prox;
    while (head) {
        if (head->valor == n) {
            ant->prox = head->prox;
            free(head);
            head = ant->prox;
        }
        else {
            ant = head;
            head = head->prox;
        }
    }
}



void remreps (LInt l){
    while (l) {
        removeInt (l, l->valor);
        l = l->prox;
    }
}


//26

LInt rotateL (LInt l){
    if (l == NULL || l->prox == NULL) return l;
    
    LInt head = l;
    l = l->prox;
    LInt inicio = l;
    
    while (l->prox != NULL) {
        l = l->prox;
        }
        
    l->prox = head;
    head->prox = NULL;

    return inicio;
}


//27



LInt parte (LInt l) {

    if (l == NULL) return l;

    LInt atual = l->prox;
    LInt ant = l;
    LInt new = newLInt (0, NULL);
    LInt auxn = new;
    int i;

    for (i = 2; atual != NULL; i++) {
        if (i % 2 == 0) {
            auxn->prox = atual;
            auxn = auxn->prox;
            ant->prox = atual->prox;
            atual = atual->prox;
            auxn->prox = NULL;
        }
        else {
            ant = ant->prox;
            atual = atual->prox;
        }
    }

    auxn = new;
    new = new->prox;
    free (auxn);

    return new;
}

// http://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%20%0A%20%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A%0ALInt%20newLInt%20%28int%20x,%20LInt%20l%29%20%7B%0A%20%20LInt%20new%20%3D%20malloc%20%28sizeof%20%28struct%20lligada%29%29%3B%0A%20%20new-%3Evalor%20%3D%20x%3B%0A%20%20new-%3Eprox%20%3D%20l%3B%0A%20%20%0A%20%20return%20new%3B%0A%7D%0A%0A%0ALInt%20cons%20%28int%20x,%20LInt%20xs%29%20%7B%0A%20%20LInt%20r%3B%0A%20%20r%20%3D%20malloc%20%28sizeof%28struct%20lligada%29%29%3B%0A%20%20r-%3Evalor%20%3D%20x%3B%0A%20%20r-%3Eprox%20%3D%20xs%3B%0A%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0ALInt%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20LInt%20r%20%3D%20NULL%3B%0A%20%20int%20i%3B%0A%20%0A%20%20for%20%28i%3DN-1%3B%20i%3E%3D0%3B%20i--%29%0A%20%20%20%20%20%20r%20%3D%20cons%20%28v%5Bi%5D,%20r%29%3B%0A%20%20%20%20%20%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0A%20int%20length%20%28LInt%20l%29%20%7B%0A%0A%20%20%20%20int%20x%20%3D%200%3B%0A%0A%20%20%20%20while%20%28l%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20l%20%3D%20l-%3Eprox%3B%0A%20%20%20%20%20%20%20%20x%2B%2B%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%20x%3B%0A%7D%0A%0A%0A%0ALInt%20parte%20%28LInt%20l%29%20%7B%0A%0A%20%20%20%20if%20%28l%20%3D%3D%20NULL%29%20return%20l%3B%0A%0A%20%20%20%20LInt%20atual%20%3D%20l-%3Eprox%3B%0A%20%20%20%20LInt%20ant%20%3D%20l%3B%0A%20%20%20%20LInt%20new%20%3D%20newLInt%20%280,%20NULL%29%3B%0A%20%20%20%20LInt%20auxn%20%3D%20new%3B%0A%20%20%20%20int%20i%3B%0A%0A%20%20%20%20for%20%28i%20%3D%202%3B%20atual%20!%3D%20NULL%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28i%20%25%202%20%3D%3D%200%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20auxn-%3Eprox%20%3D%20atual%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20auxn%20%3D%20auxn-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant-%3Eprox%20%3D%20atual-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20atual%20%3D%20atual-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20auxn-%3Eprox%20%3D%20NULL%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20ant%20%3D%20ant-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20atual%20%3D%20atual-%3Eprox%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%0A%20%20%20%20auxn%20%3D%20new%3B%0A%20%20%20%20new%20%3D%20new-%3Eprox%3B%0A%20%20%20%20free%20%28auxn%29%3B%0A%0A%20%20%20%20return%20new%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%5B10%5D%20%3D%20%7B61,%2062,%2063,%2064,%2065,%2066,%209,%2010,%2011,%2012,%2013%7D%3B%0A%20%20%0A%20%20%20%20LInt%20lista%3B%0A%20%20lista%20%3D%20fromArray%20%28a,%206%29%3B%0A%20%20%0A%20%20parte%20%28lista%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D&textReferences=false


/*

VERSAO MAIS SIMPLES

LInt parte(LInt l) {
    if(!l || !l->prox) return NULL;  //É O MESMO QUE l == NULL || l->prox == NULL
    LInt newL = l->prox;            // inicia a lista os numeros pares
    l->prox = l->prox->prox;        // passa a lista inicial para o proximo impar
    newL->prox = parte(l->prox);    // l->prox é como se fossemos fazer de inicio
    return newL;
}

*/


//28

int altura (ABin a){
    int r = 0, alturaMax;
    if (a==NULL) return 0;
    
    else {
        if (altura (a->esq) > altura (a->dir)) {
            alturaMax = altura (a->esq);
        }
        else {
            alturaMax = altura(a->dir);
        }
        r = 1 + alturaMax;
    }
    return r;
}


//29

ABin cloneAB (ABin a) {
    if (a==NULL) return NULL;
    ABin copia = malloc (sizeof (struct nodo));
    copia->valor = a->valor;
    copia->esq = cloneAB(a->esq);
    copia->dir = cloneAB(a->dir);
    return copia;
}



//30

void mirror (ABin *a) {
    if ((*a) != NULL){
        ABin temp;
        temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror (&((*a)->esq));
        mirror (&((*a)->dir));
    }
}



//31



void inorder_aux (ABin a, LInt *l) {

	if (a == NULL) return;

	inorder_aux (a->esq, l);    //fazer para a subarvore esquerda (é possivel fazer confusao por nao ter nada antes, mas a subarvore esq tem tambem elementos na direita, logo ela corre o codigo todo da inorder_aux)

	LInt atual = *l;            //determinar a posicao para continuar a inserir os elementos

	while (atual->prox != NULL)
		atual = atual->prox;

	atual->prox = newLInt (a->valor, NULL);         //colocar o valor da raiz da arvore

	inorder_aux (a->dir, l);                    //colocar os valores da direita

	return;
	
}

void inorder (ABin a, LInt *l) {

	*l = newLInt (0, NULL);     //criar um nodo Random para iniciar a lligada
	inorder_aux (a, l);         //fazer a funcao auxiliar a partir daí

	LInt aux = *l;
	*l = aux->prox;             //*l vai apontar para o nodo que começa realmente o inorder (elimina-se o 0 que se colocou randomly)
	free (aux);

	return;
}



/* Algoritmo inorder
    	(Condição) Enquanto a raiz não é vazia:
    		1. Chama-se a função inorder ao ramo esquerdo.
    		2. Chama-se a função auxiliar à raiz.
    		3. Chama-se a função inorder ao ramo direito.
    		
    Para ajudar a memorizar a função : 
            1. Criar uma auxiliar que executa para a esquerda, procura o final da lligada e coloca lá a raiz, e depois faz para a direita.
            2. Cria-se um "nodo falso", executar a função auxiliar e depois eliminar o nodo falso.
*/


//32

void preorder_aux (ABin a, LInt *l) {

	if (a == NULL) return;

	LInt atual = *l;

	while (atual->prox != NULL)         //ver o sitio onde colocar o proximo valor
		atual = atual->prox;

	atual->prox = newLInt (a->valor, NULL);

	preorder_aux (a->esq, l);
	preorder_aux (a->dir, l);

	return;	
}

void preorder (ABin a, LInt *l) {

	*l = newLInt (0, NULL);
	preorder_aux (a, l);

	LInt aux = *l;
	*l = aux->prox;
	free (aux);

	return;
}


//33

void posorder_aux (ABin a, LInt *l) {

	if (a == NULL) return;
	
	posorder_aux (a->esq, l);
	posorder_aux (a->dir, l);

	LInt atual = *l;

	while (atual->prox != NULL) {    //usa-se para procurar o sitio para por a raiz, ja que nao se usa recursivamente a funcao para tal
		atual = atual->prox;
	}

	atual->prox = newLInt (a->valor, NULL);


	return;	
}

void posorder (ABin a, LInt *l) {

	*l = newLInt (0, NULL);
	posorder_aux (a, l);

	LInt aux = *l;
	*l = aux->prox;
	free (aux);

	return;
}


//34


int depth (ABin a, int x) {
    int r;
    int esq;
    int dir;
    
    if (a == NULL) return -1;           //caso a arvore seja nula
    
    if (a->valor == x) return 1;        //caso o valor da raiz seja o que se procura
    
    esq = depth(a->esq, x);             //calcular recursivamente a depth na esquerda
    dir = depth(a->dir, x);             //calcular recursivamente a depth na direita
    
    if (esq == -1 && dir == -1) return -1;      //caso AMBOS os lados sejam NULL
    if (esq == -1) return 1 + dir;              //caso algum dos lados seja NULL
    if (dir == -1) return 1 + esq;              //caso algum dos lados seja NULL
    
    if (esq < dir){         //caso nenhum dos lados seja NULL a resposta é o que aparece mais perto da raiz da arvore
      return 1 + esq;  
    } 
    else return 1 + dir;
    
}




//35

int freeAB (ABin a) {
    int r = 0;
    if (a == NULL) return 0;
    
    r = 1 + freeAB (a->esq) + freeAB (a->dir);          //primeiro andamos tudo para a direita/esquerda e depois damos free dos nodos de baixo para cima (da arvore).
    free (a);
    
    return r;
}




//36

 int pruneAB (ABin *a, int l) {
     int r;
     if ((*a) == NULL) return 0;
     
     if (l==0) {
         r = 1 + pruneAB(&((*a)->esq), 0) + pruneAB(&((*a)->dir), 0);
         free (*a);
         (*a) = NULL;
     }
     else {
         r =  pruneAB(&((*a)->esq), l-1) + pruneAB(&((*a)->dir), l-1);
     }
    
     return r;
 }

 
 // a execuçao nu pythotutor é dificil de entender por ser recursiva
// http://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%0Atypedef%20struct%20nodo%20%7B%0A%20%20int%20valor%3B%0A%20%20struct%20nodo%20*esq,%20*dir%3B%0A%7D%20*ABin%3B%0A%0A%0Atypedef%20struct%20lligada%20%7B%0A%20%20%20%20int%20valor%3B%0A%20%20%20%20struct%20lligada%20*prox%3B%0A%7D%20*LInt%3B%0A%0A//%20sizeof%20%28ABin%29%20%3D%208%0A//%20sizeof%20%28struct%20nodo%29%20%3D%204%20%2B%208%20%2B%208%20%3D%2020%0A%0AABin%20newABin%20%28int%20r,%20ABin%20e,%20ABin%20d%29%7B%0A%20%20%20%20ABin%20a%20%3D%20malloc%20%28sizeof%20%28struct%20nodo%29%29%3B%0A%20%20%20%20%0A%20%20%20%20a-%3Evalor%20%3D%20r%3B%0A%20%20%20%20a-%3Eesq%20%3D%20e%3B%20a-%3Edir%20%3D%20d%3B%0A%20%20%20%20%0A%20%20%20%20return%20a%3B%0A%7D%0A%0AABin%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20%20ABin%20r%20%3D%20NULL,%20e,%20d%3B%0A%20%20%20int%20m%20%3D%20N/2%3B%0A%20%20%20%0A%20%20%20if%20%28N%3E0%29%20%7B%0A%20%20%20%20%20e%20%3D%20fromArray%20%28v,%20m%29%3B%0A%20%20%20%20%20d%20%3D%20fromArray%20%28v%2Bm%2B1,%20N-m-1%29%3B%0A%20%20%20%20%20r%20%3D%20newABin%20%28v%5Bm%5D,%20e,%20d%29%3B%0A%20%20%20%7D%0A%20%20%20return%20r%3B%0A%7D%0A%0Aint%20toArray%20%28ABin%20a,%20int%20v%5B%5D,%20int%20N%29%20%7B%0A%20%20int%20r%3D0%3B%0A%20%20%0A%20%20if%20%28a%20!%3D%20NULL%20%26%26%20N%3E0%29%20%7B%0A%20%20%20%20%20r%20%2B%3D%20toArray%20%28a-%3Eesq,%20v%2Br,%20N-r%29%3B%0A%20%20%20%20%20if%20%28r%20%3C%20N%29%20v%5Br%2B%2B%5D%20%3D%20a-%3Evalor%3B%0A%20%20%20%20%20r%20%2B%3D%20toArray%20%28a-%3Edir,%20v%2Br,%20N-r%29%3B%0A%20%20%7D%0A%20%20return%20r%3B%0A%7D%0A%0A%0A%0A%20int%20pruneAB%20%28ABin%20*a,%20int%20l%29%20%7B%0A%20%20%20%20%20int%20r%3B%0A%20%20%20%20%20if%20%28%28*a%29%20%3D%3D%20NULL%29%20return%200%3B%0A%20%20%20%20%20%0A%20%20%20%20%20if%20%28l%3D%3D0%29%20%7B%0A%20%20%20%20%20%20%20%20%20r%20%3D%201%20%2B%20pruneAB%28%26%28%28*a%29-%3Eesq%29,%200%29%20%2B%20pruneAB%28%26%28%28*a%29-%3Edir%29,%200%29%3B%0A%20%20%20%20%20%20%20%20%20free%20%28*a%29%3B%0A%20%20%20%20%20%20%20%20%20%28*a%29%20%3D%20NULL%3B%0A%20%20%20%20%20%7D%0A%20%20%20%20%20else%20%7B%0A%20%20%20%20%20%20%20%20%20r%20%3D%20%20pruneAB%28%26%28%28*a%29-%3Eesq%29,%20l-1%29%20%2B%20pruneAB%28%26%28%28*a%29-%3Edir%29,%20l-1%29%3B%0A%20%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20%20return%20r%3B%0A%20%7D%0A%0Aint%20main%20%28%29%20%7B%0A%0A%20%20%20%20int%20a%5B10%5D%20%3D%20%7B5,%2010,%2015,%2020,%2025,%2030,%2035,%2040,%2045,%2050%7D%3B%0A%20%20%20%20%0A%20%20%20%20%0A%20%20%20%20ABin%20arv1%20%3D%20fromArray%20%28a,%205%29%3B%0A%20%20%20%20%0A%20%20%20%20pruneAB%20%28%26arv1,%202%29%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D





//37

int iguaisAB (ABin a, ABin b) {
    if (a == NULL && b==NULL) return 1;
    if (a==NULL && b!=NULL) return 0;
    if (a!=NULL && b==NULL) return 0;
    if ((a->valor) != (b->valor)) return 0;
    
    //iguaisAB (a->esq, b->esq);
    //iguaisAB (a->dir, b->dir);
    
    return iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);        //caso um deles desse zero o return dava zero (operação logica "e")
}



//38


/*
como tinha feito mas nao esta certo:

LInt nivelL (ABin a, int n) {
    if (n==0 || a==NULL) return NULL;
    LInt lista = malloc (sizeof(struct lligada));
    lista->valor = 0;
    lista->prox = NULL;
    
    if (n==1) {
        lista->prox = malloc (sizeof (struct lligada));
        lista->valor = a->valor;
        lista->prox = NULL;
    }
    nivelL (a->esq, n-1);
    nivelL (a->dir, n-1);
    
    //eliminar o primeiro elemento que foi posto para inicializar a lligada ( o zero)
    LInt aux = lista;
    lista = lista->prox;
    free(aux);
    return lista;
}

*/




void nivelL_aux (ABin a, int n, LInt *l) {

	if (a == NULL) return;

	if (n == 1) {
		LInt new = malloc (sizeof (struct lligada));
		new->valor = a->valor;
		new->prox = *l;         //a lligada l é inicializada a NULL
		(*l) = new;             // *l passa a apontar para "new" para saber qual o proximo sitio a colocar elementos
	}
	else {
		nivelL_aux (a->dir, n-1, l);
		nivelL_aux (a->esq, n-1, l);
	}
}



LInt nivelL (ABin a, int n) {

	LInt new = NULL;
	nivelL_aux (a, n, &new);

	return new;
}




//39

int nivelV (ABin a, int n, int v[]) {
    int i = 0;
    
    if (n == 0 || a == NULL) return 0;
    
    if (n==1) {
        v[i] = a->valor; 
        return 1;
    }
    i += nivelV (a->esq, n-1, v);
    i += nivelV (a->dir, n-1, v+i);     //ATENCAO QUE SE TEM QUE FAZER v+i PARA ANDAR NO ARRAY!!!
    
    return i;
}




//40

int dumpAbin (ABin a, int v[], int N) {
    int i=0;
    int raiz, e, d;
    
    if (a==NULL || N==0) return 0;
    if (a!=NULL && N > 0) {
        e = dumpAbin (a->esq, v, N);
        if (e < N){
            v[e] = a->valor;
            d = dumpAbin (a->dir, v+e+1, N-e-1);       //IMPORTANTE : v+e+1 -> escrever no array para a frente do valor da raiz  | N-e-1 -> vamos escrever menos "e" elementos e menos 1 (que é a raiz)
            return (1 + d + e);
        }
    }
    return N;
}





//41

ABin somasAcA (ABin a) {
    ABin new;
   // int esq, dir;
    if (a != NULL) {
        new = malloc(sizeof(struct nodo));
        new->esq = somasAcA (a->esq);
        new->dir = somasAcA (a->dir);
      /*  if (new->esq == NULL) esq = 0;
        else esq = new->esq->valor;
        if (new->dir == NULL) dir = 0;
        else dir = new->dir->valor; */
        new->valor = ((a->valor) + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0));
        
        return new;
    }
    else return NULL;
}



//42

int contaFolhas (ABin a) {
    int i = 0;
    if (a==NULL) return 0;
    if (a != NULL && a->esq == NULL && a->dir == NULL) i++;
    i += contaFolhas (a->esq);
    i += contaFolhas(a->dir);
    return i;
}


//43

//tem que se fazer com o malloc!
ABin cloneMirror (ABin a) {
    if (a==NULL) return NULL;
    ABin new = malloc (sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror (a->dir);        //o valor da raiz de cada nodo da esquerda vai passar a ser da direita
    new->dir = cloneMirror (a->esq);
    return new;
}



//44



int addOrd (ABin *a, int x) {
    if (*a == NULL) {                                       //caso em que a arvore é vazia
        ABin new = malloc (sizeof(struct nodo));
        new->valor = x;
        new->esq = NULL;
        new->dir = NULL;
        *a=new;
        return 0;
    }
    
    else {                                                  //caso de a arvore ter elementos
            ABin prev;
            ABin current = *a;
            while (current != NULL){
                if (current->valor == x) return 1;             //se em algum ponto (*a)->valor for igual a x retorna logo o valor 1 e nao faz mais nada
                prev = current;
                if (x > current->valor)                        //se x>a vamos para a direita procurar o sitio 
                     current = current->dir;
                else current = current->esq;                      // se x<a vamos para a esquerda procurar o sitio onde colocar (ou nao colocar, caso ja exista)
            }
                                                            //caso nao encontre nenhum valor igual a x é porque ja percorreu a arvore toda, logo adicionamos o valor e retornamos zero
                ABin new = malloc (sizeof(struct nodo));
                new->valor = x;
                new->esq = NULL;
                new->dir = NULL;
                
                if (prev->valor < x) 
                    prev->dir = new;
                else 
                    prev->esq = new;
                    
                return 0;
       }
    }




/*

OUTRO MODO:

int addOrd (ABin *a, int x) {
    ABin copy = *a;
    ABin ant = *a;
    
    if (copy == NULL) {
        copy = malloc (sizeof (struct nodo));
        copy->valor = x;
        copy->esq = copy->dir = NULL;
        *a = copy;
    }
    else {
        while (copy != NULL) {
            if (copy->valor > x) {
                ant = copy; 
                copy = copy->esq;
            }
            else if (copy->valor < x) {
                ant = copy; 
                copy=copy->dir;
            }
            else if (copy->valor == x) return 1;
        }                                           //ant vai ficar no nodo atras
        if (x > ant->valor) {                              //se x for maior que ant temos que o colocar a direita com malloc.
            ant->dir = malloc(sizeof(struct nodo));
            ant = ant->dir;
            ant->valor = x;
            ant->esq = ant->dir = NULL;
        }
        else if (x < ant->valor) {                         //se x for menor que ant temos que colocar a esquerda com malloc.
            ant->esq = malloc(sizeof(struct nodo));
            ant = ant->esq;
            ant->valor = x;
            ant->esq = ant->dir = NULL;
        }
    }
    return 0;
}
    
    
*/


//45

 
int lookupAB (ABin a, int x) {
    if (a==NULL) return 0;
    if (a->valor == x) return 1;
    lookupAB (a->esq, x);
    lookupAB (a->dir, x);

}


/*
outro modo (sem usar varios returns)

int lookupAB (ABin a, int x) {
    int r = 0;
    if (a==NULL) return 0;
    if (a->valor == x) r= 1;
    r += lookupAB (a->esq, x);
    r += lookupAB (a->dir, x);
    if (r>0) return 1;
    else return 0;

}

*/



//46

 
int depthOrd (ABin a, int x) {
    int n = 1;
    if (a == NULL) return -1;
    while (a != NULL) {
        if (a->valor == x) return n;
        if (a->valor < x) {
            a = a->dir; 
            n++;
        }
        else {
            a = a->esq;
            n++;
        }
    }
    return -1;
}

/*
// OUTRO MODO:

int depthOrd (ABin a, int x) {
    int i = 1;
    while (a != NULL) {
        if (a->valor == x) return i;
        else if (a->valor > x) a = a->esq;
        else if (a->valor < x) a = a->dir;
        i++;
    }
    return -1;
}
*/


//47

/*
int maiorAB (ABin a) {
    int maior;
    ABin prev = a;
    while (a != NULL) {
        prev = a;
        a = a->dir;
    }
    maior = prev->valor;
    return maior;
}
*/


int maiorAB (ABin a) {
    while (a->dir != NULL) {
        a = a->dir;
    }
    return a->valor;
}


//48

 
 void removeMaiorA (ABin *a) {
    /* Quando é encontrado o maior elemento da árvore binária de procura, o apontador *root representa o ramo direito do ramo anterior, assim atualizando *root para
    o apontador do seu ramo esquerdo a árvore binária ignora o maior nodo e o ramo fica ligado ao valor à esquerda do maior valor. */
    if ((*a)->dir == NULL){
        ABin temp = *a;
        *a = (*a)->esq;
        free(temp);
    /* Chama-se a função recursivamente até encontrar o último valor. */
    } else {
        removeMaiorA(&((*a)->dir));
    } 
}
 
/*
 OUTRO MODO:
 
 void removeMaiorA(ABin *a){
   if((*a)-> dir == NULL) *a= (*a)-> esq;
   else removeMaiorA (&((*a)-> dir));
}
 
 */
 

 // http://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0A%0Atypedef%20struct%20nodo%20%7B%0A%20%20int%20valor%3B%0A%20%20struct%20nodo%20*esq,%20*dir%3B%0A%7D%20*ABin%3B%0A%0A//%20sizeof%20%28ABin%29%20%3D%208%0A//%20sizeof%20%28struct%20nodo%29%20%3D%204%20%2B%208%20%2B%208%20%3D%2020%0A%0AABin%20newABin%20%28int%20r,%20ABin%20e,%20ABin%20d%29%7B%0A%20%20%20%20ABin%20a%20%3D%20malloc%20%28sizeof%20%28struct%20nodo%29%29%3B%0A%20%20%20%20%0A%20%20%20%20a-%3Evalor%20%3D%20r%3B%0A%20%20%20%20a-%3Eesq%20%3D%20e%3B%20a-%3Edir%20%3D%20d%3B%0A%20%20%20%20%0A%20%20%20%20return%20a%3B%0A%7D%0A%0AABin%20fromArray%20%28int%20v%5B%5D,%20int%20N%29%7B%0A%20%20%20ABin%20r%20%3D%20NULL,%20e,%20d%3B%0A%20%20%20int%20m%20%3D%20N/2%3B%0A%20%20%20%0A%20%20%20if%20%28N%3E0%29%20%7B%0A%20%20%20%20%20e%20%3D%20fromArray%20%28v,%20m%29%3B%0A%20%20%20%20%20d%20%3D%20fromArray%20%28v%2Bm%2B1,%20N-m-1%29%3B%0A%20%20%20%20%20r%20%3D%20newABin%20%28v%5Bm%5D,%20e,%20d%29%3B%0A%20%20%20%7D%0A%20%20%20return%20r%3B%0A%7D%0A%0Aint%20toArray%20%28ABin%20a,%20int%20v%5B%5D,%20int%20N%29%20%7B%0A%20%20int%20r%3D0%3B%0A%20%20%0A%20%20if%20%28a%20!%3D%20NULL%20%26%26%20N%3E0%29%20%7B%0A%20%20%20%20%20r%20%2B%3D%20toArray%20%28a-%3Eesq,%20v%2Br,%20N-r%29%3B%0A%20%20%20%20%20if%20%28r%20%3C%20N%29%20v%5Br%2B%2B%5D%20%3D%20a-%3Evalor%3B%0A%20%20%20%20%20r%20%2B%3D%20toArray%20%28a-%3Edir,%20v%2Br,%20N-r%29%3B%0A%20%20%7D%0A%20%20return%20r%3B%0A%7D%0A%0Aint%20procuraR%20%28int%20x,%20ABin%20a%29%20%7B%0A%20%20//%20a%20e%20uma%20%C3%A1rvore%20de%20procura%0A%20%20//%20retorna%20True%20se%20x%20existe%20na%20%C3%A1rvore%0A%20%20//%20%20%20%20%20%20%20%20%20Falso%20no%20outro%20caso%0A%20%20int%20r%20%3D%200%3B%20//%20ainda%20n%C3%A3o%20encontrei%0A%20%20%0A%20%20if%20%28a%20%3D%3D%20NULL%29%20%3B%0A%20%20else%20if%20%28a-%3Evalor%20%3D%3D%20x%29%20r%3D1%3B%0A%20%20%20%20%20%20%20else%20if%20%28a-%3Evalor%20%3E%20x%29%20%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%20%3D%20procuraR%20%28x,a-%3Eesq%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20else%20//%20a-%3Evalor%20%3C%20x%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20r%20%3D%20procuraR%20%28x,a-%3Edir%29%3B%0A%20%20return%20r%3B%0A%7D%0A%0Aint%20procura1%20%28int%20x,%20ABin%20a%29%20%7B%0A%20%20//%20a%20e%20uma%20%C3%A1rvore%20de%20procura%0A%20%20//%20retorna%20True%20se%20x%20existe%20na%20%C3%A1rvore%0A%20%20//%20%20%20%20%20%20%20%20%20Falso%20no%20outro%20caso%0A%20%20int%20r%20%3D%200%3B%20//%20ainda%20n%C3%A3o%20encontrei%0A%20%20%0A%20%20while%20%28a%20!%3D%20NULL%20%26%26%20r%20%3D%3D%200%29%20%7B%0A%20%20%20%20%20%20//%20p%C3%A1ra%20quando%20%281%29%20acaba%20a%20arvore%20%28a%3D%3DNULL%29%0A%20%20%20%20%20%20//%20%20%20%20%20%20%20%20%20%20%20%20%20%282%29%20encontramos%20x%20%20%28a-%3Evalor%20%3D%3D%20x%29%0A%20%20%20%20%20%20if%20%20%20%28a-%3Evalor%20%3D%3D%20x%29%20%20%20%20r%20%3D%201%3B%0A%20%20%20%20%20%20else%20if%20%28a-%3Evalor%20%3E%20x%29%20%20a%20%3D%20a-%3Eesq%3B%0A%20%20%20%20%20%20else%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20a%20%3D%20a-%3Edir%3B%0A%20%20%7D%0A%20%20return%20r%3B%0A%7D%0A%0A%0Avoid%20removeMaiorA%20%28ABin%20*a%29%20%7B%0A%20%20%20%20/*%20Quando%20%C3%A9%20encontrado%20o%20maior%20elemento%20da%20%C3%A1rvore%20bin%C3%A1ria%20de%20procura,%20o%20apontador%0A%20%20%20%20%20%20%20*root%20representa%20o%20ramo%20direito%20do%20ramo%20anterior,%20assim%20atualizando%20*root%20para%0A%20%20%20%20%20%20%20o%20apontador%20do%20seu%20ramo%20esquerdo%20a%20%C3%A1rvore%20bin%C3%A1ria%20ignora%20o%20maior%20nodo%20e%20o%20ramo%0A%20%20%20%20%20%20%20fica%20ligado%20ao%20valor%20%C3%A0%20esquerda%20do%20maior%20valor.%20*/%0A%20%20%20%20if%20%28%28*a%29-%3Edir%20%3D%3D%20NULL%29%7B%0A%20%20%20%20%20%20%20%20ABin%20temp%20%3D%20*a%3B%0A%20%20%20%20%20%20%20%20*a%20%3D%20%28*a%29-%3Eesq%3B%0A%20%20%20%20%20%20%20%20free%28temp%29%3B%0A%20%20%20%20/*%20Chama-se%20a%20fun%C3%A7%C3%A3o%20recursivamente%20at%C3%A9%20encontrar%20o%20%C3%BAltimo%20valor.%20*/%0A%20%20%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20%20%20removeMaiorA%28%26%28%28*a%29-%3Edir%29%29%3B%0A%20%20%20%20%7D%20%0A%7D%0A%0A%0A%0Aint%20main%20%28%29%20%7B%0A%0A%20%20%20%20int%20a%5B10%5D%20%3D%20%7B5,%2010,%2015,%2020,%2025,%2030,%2035,%2040,%2045,%2050%7D%3B%0A%20%20%20%20%0A%20%20%20%20int%20existe%3B%0A%0A%20%20%20%20ABin%20arv1%20%3D%20fromArray%20%28a,%204%29,%20arv2%3B%0A%20%20%20%20%0A%20%20%20%20removeMaiorA%20%28%26arv1%29%3B%0A%20%20%20%20%0A%0A%20%20%20%20return%200%3B%0A%7D&mode=edit&origin=opt-frontend.js&py=c&rawInputLstJSON=%5B%5D
 



//49

 /*
int quantosMaiores (ABin a, int x) {
    int n=0;
    if (a == NULL) return 0;
    if (a->valor <= x) n = quantosMaiores (a->dir, x);                      //caso x seja maior que a->valor, entao so pode ter maiores no lado direito, e no lado esquerdo nao se conta nada
    else n = 1 + quantosMaiores (a->esq, x) + quantosMaiores (a->dir,x);
    return n;
}

*/



int quantosMaiores (ABin a, int x) {
    int i = 0;
    if (a == NULL) return 0;
    if (a->valor > x) return 1 + quantosMaiores (a->esq, x) + quantosMaiores (a->dir,x);
    else return quantosMaiores (a->dir,x);
    
}


//50

 int length (LInt l) {
	int x = 0;
	while (l != NULL) {
		l = l->prox;
		x++;
	}
	return x;
}



LInt parteAMeio (LInt *l) {

	LInt atual = *l;
	LInt ant = newLInt (0, atual);
	*l = ant;

	int x = length (atual) / 2;

	while (x > 1) {
		atual = atual->prox;
		ant = ant->prox;
		x--;
	}

	ant->prox = NULL;

	ant = *l;
	*l = ant->prox;
	free (ant);

	return atual;
}



void listToBTree (LInt l, ABin *a) {
	if (l == NULL) {
		*a = NULL;
		return;
	}
	LInt dir = parteAMeio (&l);         //dir vai ficar com a raiz e os numeros do lado direitp

	*a = newABin (dir->valor, NULL, NULL);
	listToBTree (l, &(*a)->esq);
	listToBTree (dir->prox, &(*a)->dir);

	return;
}
 
 
 
 
 /*
 
// NAO ESTA CORRETO!

int calculaTamanho (LInt l){
    int size = 0;
    while (l != NULL) {
        l=l->prox;
        size++;
    }
    return size;
} 

LInt vaiAteMeio (LInt l, int x) {        // x é o tamanho total da lligada          //Funcao que deixa a lista com a sua primeira metade
    int cont = x-x/2-1;
    LInt head = l;
    while (cont > 0) {
        l=l->prox;
        cont--;
    }
    LInt seguintes = l;
    seguintes = seguintes->prox;
    free(seguintes);
    l->prox = NULL;
    
    return head;
}

LInt aPartirDoMeio (LInt l, int x){
    int cont = x-x/2 ;                       //alterei aqui ( antes tinha x/2 + 1 e eu pus x - x/2 pq temos que parar no meio, depois avancar uma casa para a frente para formar a nova lista)
    while (cont > 0) {
        l=l->prox;
        cont--;
    }
    LInt seguintes = l;                 //este passo para no numDoMeio, mas o passo seguinte faz a lista andar para a frente uma casa, logo nao aparece o numDoMeio na lista pq depois se da free
    seguintes = seguintes->prox;
    free(l);
    return seguintes;
}

int numDoMeio (LInt l, int x){
    int cont = x-x/2;
    while (x > 0){
        l=l->prox;
        x--;
    }
    return (l->valor);
}



void listToBTree (LInt l, ABin *a) {
    int size = calculaTamanho (l);
    LInt inicio = vaiAteMeio (l, size);
    LInt fim = aPartirDoMeio (l, size);
    int raiz = numDoMeio (l, size);
    
    ABin current = *a;
    current->valor = raiz;
    current->esq = listToBTree (inicio, &current);
    current->dir = listToBTree (fim, &current);
    
}

*/

//51
 
 
 int haMenores (ABin a, int x) {
     if (a == NULL) return 0;
     if (a->valor < x) return 1;
     return (haMenores (a->esq, x) || haMenores (a->dir, x));
 }
 
 
 int haMaiores (ABin a, int x) {       //retorna true (1) se forem todos maiores que x
     if (a == NULL) return 0;
     if (a->valor > x) return 1;
     return (haMaiores (a->esq, x) || haMaiores (a->dir, x));
 }
 
int deProcura (ABin a) {
    if (a == NULL) return 1;
    if (haMenores (a->dir, a->valor) == 1 || haMaiores (a->esq, a->valor) == 1) return 0;
    return (deProcura (a->esq) && deProcura (a->dir));
}






