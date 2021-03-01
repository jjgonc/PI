#include <stdio.h>


// 4


// define a function that computes how many 1's are used in 
// the (binary) representation of a given (unsigned) integer.

int bitsUm (unsigned int x){
    int res = 0;
    int bitsAUm = 0;
    while(x!=0){
        res = x%2;
        x = x/2;
        bitsAUm += res;
    }
    return bitsAUm;
}



            //      MELHOR METODO!!!!

// Por exemplo: bitsUm(10) = 2, uma vez que é necessario 2 bits a um para representar
// o numero 10 em binario (1010)

int bitsUm (unsigned int n){ 
    int r = 0;
    while(n) {
        r += (n % 2);
        n = n/2;    //  ou entao: n >>= 1; // Shifts the bits in `n` one bit to the right, i.e., n = n / 2
    }
    return r;
}

// 5

// recebe um numero int e diz quantos zeros seguidos tem no final da sua representaçao binaria
//  por exemplo : trailingZ (16) = 4, porque 16 em binario é 10000
// por exemplo : trailingZ (12) = 2, porque 12 em binario é 1100

int trailingZ (unsigned int n){ 
    int r = 0;
    if (n == 0){
        return 32;
    }
    while(n != 0){
        if(n % 2 == 0){
            n /= 2;
            r++;
        } else {
            break;
        }
    }
    return r;
}



// 6
 /* Defina uma função int qDig (unsigned int n) 
    que calcula o número de dígitos necessários 
    para escrever o inteiro n em base decimal. 
    Por exemplo, qDig (440) deve retornar 3.
*/

int qDig (int n) {
    int r = 0;
    
    while (n>=1){
        n = n/10;
        r += 1;     //ou entao r++;
    }
    return r;
}

// 7
/*
  Apresente uma definição da função pré-definida em C "char *strcat (char s1[], char s2[])"
  que concatena a string s2 a s1 (retornando o endereço da primeira).
*/

char *mystrcat(char s1[], char s2[]) {
    int i,j;
    for (i=0; s1[i] != '\0'; i++);
    for (j=0; s2[j] != '\0'; j++,i++){
        s1[i] = s2[j];
    }
    s1[i] = '\0';
    
    return s1;
}

// 8
/*
  Apresente uma definição da função pré-definida em C "char *strcpy (char *dest, char source[])"
  que copia a string source para dest retornando o valor desta última.
*/
char *mystrcpy(char s1[], const char s2[]) {
    int i;
    for (i=0; s2[i]!='\0'; i++){
        s1[i]=s2[i];
    }
    s1[i]='\0';
    return s1;
}

// 9
/*
  Apresente uma definição da função pré-definida em C "int strcmp (char s1[], char s2[])"
  que compara (lexicograficamente) duas strings. O resultado deverá ser:
   • 0, se as strings forem iguais;
   • <0, se s1<s2;
   • >0, se s1>s2.
*/
int mystrcmp(char s1[], char s2[]) {
    int i;
    for (i=0; s1[i] != '\0' || s2[i] != 0; i++){
        if (s1[i]<s2[i]) return -1;
        else if (s1[i]>s2[i]) return 1;
    }
    if(s1[i] == '\0' && s2[i] != '\0')  return -1;
    if(s1[i] != '\0' && s2[i] == '\0') return 1;
    return 0;
}


// 10
#include <string.h>


char *mystrstr (char s1[], char s2[]) {
    int i,j=0, tmp;
    char* ans = s1;
    
    if (s1[0] == '\0' || s2[0] == '\0') 
        return s1;                                    //programaçao defensiva para cobrir alguns casos
    for (i=0; s1[i] != '\0'; i++){
        if (s1[i] == s2[0]){                          //comparar o inicio e caso aconteca passar para a comparacao do resto das strings
           tmp=i;                                     //a partir do ponto onde sejam iguais guarda o i para dar no resultado
           for(j=0; s1[i]==s2[j] && s2[j] != '\0' && s1[i] != '\0'; j++,i++)
           ;
           
           if(s2[j]=='\0') return (ans+tmp);          // ou entao &s1[tmp]    ou entao    s1+tmp, sendo que ans = s1
        }
    }

    return NULL;
}




// 11
/*
  Defina uma função "void strrev (char s[])" que inverte uma string.
*/
void strrev (char s[]) {
    int size, j, k;
    for (size=0; s[size] != '\0'; size++);  // aqui ficamos com o tamanho da string inicial 
    char tmp[size];  // criou-se uma string vazia para começar a armazenar as letras do fim da inicial no inicio desta
    for (k=0; k<size; k++) tmp[k] = s[size-k-1];
    for (j=0; j<size; j++) s[j] = tmp[j];
    return;
}    

// 12
#include <stdio.h>

/* Defina uma função void strnoV (char s[]) que 
   retira todas as vogais de uma string.
*/


void strnoV (char t[]){
    int read, write=0;
    
    for (read=0; t[read]!='\0'; read++){
        if (t[read] != 'a' && 
            t[read] != 'e' && 
            t[read] != 'i' && 
            t[read] != 'o' &&
            t[read] != 'u' &&
            t[read] != 'A' &&
            t[read] != 'E' &&
            t[read] != 'I' &&
            t[read] != 'O' &&
            t[read] != 'U') {
            
            t[write]=t[read];               //CRIAR UM ARRAY NOVO SO COM OS QUE SAO DIFERENTES DAS VOGAIS EM QUE O INDICE É DADO PELO j
            write++;
            }
    
    }
    t[write] = '\0';                            //ATENCAO A ESTE PONTO, SEM ISTO NAO FUNCIONA!!!!
}




// 13
#include <stdio.h>
#include <ctype.h>

/* Defina uma função 
   void truncW (char t[], int n) 
   que dado um texto t com várias palavras 
   (as palavras estão separadas por um ou 
   mais espaços) e um inteiro n, trunca 
   todas as palavras de forma a terem no 
   máximo n caracteres.
*/

void truncW (char t[], int n){
   
    int read, write, count;
    write = 0; 
    count = n;
    for ( read=0 ; t[read]!='\0' ; read++) {
        if ( (count > 0) && (t[read] != ' ')){
            t[write++]=t[read];
            count--;
        }
        else if (t[read] == ' '){
            t[write++]=t[read];
            count = n;
        }
    }
    t[write]='\0';
}

// 14
/*
  Defina uma função "char charMaisfreq (char s[])" que determina qual o
  caracter mais frequente numa string. A função deverá retornar 0 no caso
  de s ser a string vazia.
*/

char charMaisfreq (char s[]) {
    int i, j, counter = 0;
    char maisFreq = s[0];
    for (i=0; s[i] != '\0'; i++){
        int counterTMP = 0;            
        for (j=i; s[j] != '\0'; j++){
            if (s[i] == s[j]) 
                counterTMP++;
            
            if (counterTMP > counter){
               counter = counterTMP;
               maisFreq = s[i];
                }
    }
  }
  return maisFreq;
}



// 15
/*
  Defina uma função "int iguaisConsecutivos (char s[])" que, dada uma string s
  calcula o comprimento da maior sub-string com caracteres iguais. Por exemplo, 
  "iguaisConsecutivos ("aabcccaac")" deve dar como resultado 3, correspondendo
  à repetição "ccc".
*/
int iguaisConsecutivos (char s[]) {
    int i, max=0, letraVezes=1;
    for (i=0; s[i]!='\0'; i++){
        if (s[i] == s[i+1])
            letraVezes++;
        else letraVezes = 1;
        if (letraVezes > max) 
            max = letraVezes;
    }
        
    return max;
}


// 16
/*
  Defina uma função "int difConsecutivos (char s[])" que, dada uma string s
  calcula o comprimento da maior sub-string com caracteres diferentes. Por
  exemplo, "difConsecutivos ("aabcccaac")" deve dar como resultado 3,
  correspondendo à string "abc".
*/
int diff(char s[],int idx){     //dado um certo array e um indice (idx), verifica se alguma letra é igual à que está no indice idx
        int i;
        for(i=0; i < idx; i++) {
            if(s[i] == s[idx]) return 0;
        }
return 1; 
}



int difConsecutivos(char s[]) {
    int i,j;
    int max=0;
    for(i=0; s[i] != '\0'; i++){                        // i marca o inicio da sub-string e j diz o seu tamanho 
        for(j=0; s[i+j] != '\0' && diff(s+i, j); j++)
            ;
            if (j > max) max=j;
    }
    return max;
}
 
 




// 17
/*
  Defina uma função "int maiorPrefixo (char s1 [], char s2 [])" que calcula
  o comprimento do maior prefixo comum entre as duas strings.
*/
int maiorPrefixo (char s1 [], char s2 []) {
    int i, tamanho=0;
    for (i=0; s1[i] == s2[i]; i++){
        if (s1[i]==s2[i]) 
            tamanho++;
    
    }
    return tamanho;
}

// 18
/*
  Defina uma função "int maiorSufixo (char s1 [], char s2 [])" que calcula
  o compri- mento do maior sufixo comum entre as duas strings.
*/
int maiorSufixo (char s1 [], char s2 []) {
    int i, j, k, l, contaLetras=0;
    for (i=0; s1[i] != '\0'; i++); // calcular o tamanho do primeiro array
    for (j=0; s2[j] != '\0'; j++); // calcular o tamanho do segundo array
    for (k=i-1, l=j-1; k>=0 && l>=0; k--, l--){
        if (s1[k]!=s2[l])
            break;
        else contaLetras++;
    }
    return contaLetras;
}

// 19
/*
  Defina a função "int sufPref (char s1[], char s2[])" que calcula o tamanho
  do maior sufixo de s1 que é um prefixo de s2. Por exemplo
  "sufPref("batota","totalidade")" deve dar como resultado 4, uma vez que a
  string "tota" é um sufixo de "batota" e um prefixo de "totalidade".
*/
int sufPref (char s1[], char s2[]) {
    int i, j=0, conta=0;
    for (i=0; s1[i] != '\0'; i++){
            if (s1[i] == s2[j]){
                conta++;
                j++;
            }
            else conta=j=0;
    }
    return conta;
}

// 20
/*
  Defina uma função "int contaPal (char s[])" que conta as palavras de uma
  string. Uma palavra é uma sequência de caracteres (diferentes de espaço)
  terminada por um ou mais espaços. Assim se a string p tiver o valor
  "a a bb a", o resultado de "contaPal(p)" deve ser 4.
*/
int contaPal (char s[]) {
    int i;
    int  count = 0;
    for(i=0; s[i] != '\0'; i++){
        if(s[i] != ' ' && s[i] != '\n' && (s[i+1] == ' ' || s[i+1] == '\0'))
            count++;
    }
    return count;
}

// 21
/*
  Defina uma função "int contaVogais (char s[])" que retorna o número
  de vogais da string s. Não se esqueça de considerar tanto maiúsculas
  como minúsculas.
*/
int contaVogais (char s[]) {
    int i, conta=0;
    for (i=0; s[i] != '\0'; i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            conta++;
    }
    return conta;
}

// 22
/*
  Defina uma função "int contida (char a[], char b[])" que testa se todos
  os caracteres da primeira string também aparecem na segunda. Por exemplo,
  contida "braga" "bracara augusta" deve retornar verdadeiro enquanto que
  contida "braga" "bracarense" deve retornar falso.
*/
int contida (char a[], char b[]) {
    int i, j;
    for (i=0; a[i] != '\0'; i++){
        for (j=0; b[j]!='\0' && b[j]!=a[i] ;j++)
            ;
            
            if (b[j]=='\0')
            return 0;
    }
    return 1;
}

// 23
/*
  Defina uma função "int palindroma (char s[])" que testa se uma palavra é
  palíndroma, i.e., lê-se de igual forma nos dois sentidos.
*/
int palindroma (char s[]) {
    int i, pal=1, size;
    for (size=0; s[size] != '\0'; size++);       //saber o tamanho da string
    for (i=0; s[i] != '\0'; i++){
    if (s[i] != s[size-1-i])                   //tamanho -1 vai dar o final da string (porque \0 é o ultimo) e o -i é para enquanto s[i] avança o s[size-1-i] recua.
        pal=0;         
    }
    return pal;
}

// 24
#include <stdio.h>

/* a função remRep deve remover da string argumento
   todos os caracteres que se repetem sucessivamente
   deixando lá apenas uma cópia
*/

int remRep (char texto []) {
    int i, r = 0;
    for (i=0; texto[i] != '\0'; i++){
        if (texto[i] != texto[i+1])
            texto[r++] = texto[i];   
    }
    texto[r]='\0';
    return r;
}



/*
int remRep (char texto []) {
    int i, r = 0;
    for (i=0; texto[i] != '\0'; i++){
        if (texto[i] != texto[i+1])
        {
            texto[r] = texto[i];
            r ++;
        }
    }
    texto[r]='\0';
    return r;
}
*/

// 25
#include <stdio.h>

/* A função 
       int limpaEspacos (char t[])
   elimina repetições sucessivas de espaços por um único espaço.
   A função deve retornar o comprimento da string resultante.
*/

int limpaEspacos (char texto[]) {
    int r=0, i;
    for(i=0;texto[i]!='\0';i++)
        if(texto[i]!=' ' || (texto[i]==' ' && texto [i+1]!=' ') )
            texto[r++]=texto[i];                                    // ATENCAO AO R++
    texto[r] = '\0';
    return r;
}

// 26
#include <stdio.h>

/* a função
   void insere (int v[], int N, int x) 
   que insere um elemento (x) num vector ordenado.
   Assuma que as N primeiras posições do 
   vector estão ordenadas e que por isso, após a 
   inserção o vector terá as primeiras N+1 posições 
   ordenadas.
*/



void insere (int s[], int N, int x){
   int i;
   for ( i=N-1 ; i>=0 && s[i]>=x ; i--){                         //Entender esta maneira porque N-1????
       s[i+1]=s[i];
    }
    s[i+1]=x;
}




// 27
#include <stdio.h>

/* a função 
   void merge (int r [], int a[], int b[], int na, int nb) 
   que, dados vectores ordenados a (com na elementos) e 
   b (com nb elementos), preenche o vector r (com na+nb 
   elementos) com os elementos de a e b ordenados.
*/
   void merge (int r [], int a[], int b[], int na, int nb){
    int i = 0, j = 0, indice = 0;
    while(indice < na + nb) {
        if((a[i] < b[j] && i < na) || j >= nb)
            r[indice++] = a[i++];                   //ERA O MESMO QUE TER NAS LINHAS DE BAIXO : indice++; (enter) i++;
        else
            r[indice++] = b[j++];
    }
}
   
   
/*

   OUTRO MODO
   
   

     void merge (int r [], int a[], int b[], int na, int nb){//27
       int i=0;
       int j=0;
       int indice=0;
       while(i<na || j<nb){
           if(i==na){                   //caso o na (tamanho de a) seja igual ao de i
               r[indice++]=b[j++];
               
           }
           else if(j==nb){
               r[indice++]=a[i++];
           }
           else if(a[i]<b[j]){
               r[indice++]=a[i++];
           }
           else r[indice++]=b[j++];
       }
   }
   
   */

// 28
#include <stdio.h>

/* a uma função 
   int crescente (int a[], int i, int j) 
   que testa se os elementos do vector a, entre as 
   posições i e j (inclusivé) estão ordenados por 
   ordem crescente. 
   A função deve retornar 1 ou 0 consoante o 
   vector esteja ou não ordenado.
*/
/*
METODO 1: 

   int crescente (int a[], int i, int j){
       int r=1;
       for (i; i != j; i++){            // ou i<j
           if (a[i] > a[i+1])
            r=0;
       }
    return r;
   }
   
   
   */
   
   
   int crescente (int a[], int i, int j){
       int r=1, ind;
       for (i; i != j; i++){            // ou i<j
           for (ind = i; ind != j; ind++) {
               if (a[ind] < a[i]) return 0; 
           }
       }
    return 1;
   }

// 29
#include <stdio.h>

/* aa função 
   int retiraNeg (int v[], int N) 
   que retira os números negativos de um vector 
   com N inteiros. 
   A função deve retornar o número de elementos 
   que não foram retirados.
*/ 

   int retiraNeg (int v[], int N){
        int read, write=0;
        for (read=0; read < N; read++){    //copiar o vetor para o vetor v ser o final e ficar apenas com os positivos
           if (v[read] >= 0) v[write++] = v[read];
        }
       return write;
   }



   int retiraNeg (int v[], int N){
        int i, idx=0;
        char copy[N];
        for (i=0; i < N; i++){    //copiar o vetor para o vetor v ser o final e ficar apenas com os positivos
           copy[i]=v[i];
        }
        for (i=0; i < N; i++){
            if (copy[i]>=0){
                v[idx] = copy[i];
                idx++;
            }
        }
       return idx;
   }




// 30
#include <stdio.h>

/* Defina uma função 
   int menosFreq (int v[], int N) 
   que recebe um vector v com N elementos 
   ordenado por ordem crescente e retorna 
   o menos frequente dos elementos do vector.
   Se houver mais do que um elemento nessas 
   condições deve retornar o que começa por 
   aparecer no índice mais baixo.
*/
   int menosFreq (int v[], int N){
       int i, j;
       int frequencia;
       int elemento = v[0];
       int minFreq=N;
       for (i=0; i<N; i++){
           frequencia = 0;
           for (j=0; j<N; j++)//{
               if (v[i]==v[j]){
                   frequencia++;                                    //qual a diferença destes parenstesis ??? 
               }
               if (frequencia < minFreq){
                   minFreq = frequencia;
                   elemento = v[i];
               }
           }
          //}
       return elemento;
   }
   
   
   /*
        CODIGO PYTHONTUTOR PARA VERIFICAR:
        
   int main (){
     int v[20] = {1 , 1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3};
       int N=20;
       int i, j;
       int frequencia;
       int elemento = v[0];
       int minFreq=N;
       for (i=0; i<N; i++){
           frequencia = 0;
           for (j=0; j<N; j++)
               if (v[i]==v[j])
                   frequencia++;
          
               if (frequencia < minFreq){
                   minFreq = frequencia;
                   elemento = v[i];
               }
           }
       return elemento;
   }
   
   
   
   */

// 31
#include <stdio.h>

/* a função 
   int maisFreq (int v[], int N)
   que recebe um vector v com N elementos 
   ordenado por ordem crescente e retorna 
   o mais frequente dos elementos do vector.
   Se houver mais do que um elemento nessas 
   condições deve retornar o que começa por 
   aparecer no índice mais baixo.
*/
int maisFreq (int v[], int N){
    int maxFreq=0;
    int elemento=v[0];
    int frequencia; 
    int i,j;
    for(i=0;i<N;i++){
        frequencia=0;           //Cada vez que repete este ciclo a frequencia passa a zero para poder contar de cada um. Nao importa repetir a contagem das letras pq a medida que avança é menor, e na interfere no resultado
        for(j=0;j<N ;j++)
            if (v[i]==v[j])
                frequencia++;
            if(frequencia>maxFreq){
                elemento=v[i];
                maxFreq=frequencia;
            }
        }
      return elemento;
   }



// 32
#include <stdio.h>

/* a função 
   int maxCresc (int v[], int N)
   que calcula o comprimento da maior sequência 
   crescente de elementos consecutivos num vector 
   v com N elementos.
   Por exemplo, se o vector contiver 10 elementos 
   pela seguinte ordem:
   {1, 2, 3, 2, 1, 4, 10, 12, 5, 4}, 
   a função deverá retornar 4, correspondendo ao 
   tamanho da sequência {1, 4, 10, 12}.
*/
   int maxCresc (int v[], int N) {
        int i, count=1, max=0;
        for (i=0; i<N; i++){
            if (v[i+1] >= v[i])
                count++;
            else count=1;
            
            if (count>max) max = count;
        }
        
       
       return max;
   }

// 33
#include <stdio.h>

/* a uma função 
   int elimRep (int v[], int n) 
   que recebe um vector v com n inteiros e elimina 
   as repetições. 
   A função deverá retornar o número de elementos 
   do vector resultante.
   Por exemplo, se o vector v contiver nas suas 
   primeiras 10 posições os números
   {1, 2, 3, 2, 1, 4, 2, 4, 5, 4}
   a invocação elimRep (v,10) deverá retornar 5 e 
   colocar nas primeiras 5 posições do vector os 
   elementos {1,2,3,4,5}.
*/
   int elimRep (int v[], int N) {
        int r = 0;
        int i, j;
        for (i=0; i<N; i++){
            if (aindaNaoApareceu (v, i))
                v[r++]=v[i];
                
           }
       return r;
   }
   
   
   
   int aindaNaoApareceu (int a[], int i) {   // Recebe o array e as posiçoes ate ao momento.... se ainda nao apareceu da 1, caso ja tenha aparecido no vetor da 0 e nao entra para o array final v.
    int j;
    for (j=0; j<i; j++){
        if (a[j]==a[i])
            return 0;
    }
    return 1;
    }
    

// 34
#include <stdio.h>

/* a uma função 
   int elimRepOrd (int v[], int n) que recebe 
   um vector v com n inteiros ordenado por ordem 
   crescente e elimina as repetições. 
   A função deverá retornar o número de elementos 
   do vector resultante.
*/ 
   int elimRepOrd (int v[], int N) {
       int i, r=0;
       for (i=0; i<N; i++){
           if (v[i] != v[i+1] || i+1==N)    //caso sejam todos iguais fica o ultimo elemento
            v[r++]=v[i];
       }
       return r;
   }

// 35
#include <stdio.h>
/* a uma função 
   int comunsOrd (int a[], int na, int b[], int nb)
   que calcula quantos elementos os vectores 
   a (com na elementos) e b (com nb elementos) 
   têm em comum.
   Assuma que os vectores a e b estão ordenados por 
   ordem crescente.
*/
   int comunsOrd (int a[], int na, int b[], int nb){
       int r = 0;
       int i=0, j=0;
       while (i<na && j<nb){
           if (a[i]>b[j])               //se o numero em a estiver maior, entao b vai a procura dele  
            j++;
            else if (a[i]<b[j])         //se o numero em b estiver maior, entao a vai a procura dele 
            i++;
       
            else{                       //quando for igual comum aumentam os dois e o contador tambem
                r++;
                i++;
                j++;
            }
       }
       return r;
   }

// 36
#include <stdio.h>

/* a função 
   int comuns (int a[], int na, int b[], int nb) 
   que calcula quantos elementos do vector a (com na elementos) 
   ocorrem no vector b (com nb elementos). 
   Assuma que os vectores a e b não estão ordenados 
   e defina a função sem alterar os vectores.
*/

int elem (int a, int s[], int n){
   int i;
   for(i=0; i<n; i++) 
      if (s[i]==a) return 1;                            //POR EXEMPLO, SE TIVER DOIS 1 NA STRING a, NAO IRIA CONTAR 2VEZES O NUMERO 1???
   return 0;
}

int comuns (int a[], int na, int b[], int nb){
   int i,counter=0;
   for(i=0 ; i<na ; i++)
      if( elem (a[i],b,nb) ) 
      counter++;
   return counter;
}



/*
int comuns (int a[], int na, int b[], int nb){//36 
      int i ,j;
      int r=0;
      for(i=0;i<na;i++)
        for(j=0;j<nb;j++)
            if(a[i]==b[j]){
                r++;
                break;// usa-se o break porque so querem os comuns. se num array tiver varios 1 e no outro tiver so um 1 conta como so 1 , logo encontrado pode ser ignorado a resto do array
            }
                return r;
   }
   */

// 37
/* Defina uma função 
   int minInd (int v[], int n) 
   que, dado um vector v com n inteiros, retorna o 
   índice do menor elemento do vector.
*/
int minInd (int v[], int n) {
   int i;
   int indice=0; 
   int min=v[0];
   for (i=0; i<n; i++){
       if (v[i] < min){
        min = v[i];
        indice = i;
       }
   }
   return indice;
}



// 38
/* a função 
   void somasAc (int v[], int Ac [], int N)
   que preenche o vector Ac com as somas acumuladas 
   do vector v. 
   Por exemplo, o elemento na posição Ac[3] deve 
   ser calculado como v[0]+v[1]+v[2]+v[3].
*/
void somasAc (int v[], int Ac [], int N){
    int i, soma=0;
    for (i=0; i<N; i++){
       soma = soma+v[i];   // ou soma += v[i]
       Ac[i]=soma;
   }
   
}
   

// 39
/*
  Defina uma função "int triSup (int N, int m [N][N])" que testa se uma
  matriz quadrada é triangular superior, i.e., que todos os elementos abaixo
  da diagonal são zeros.
*/

int triSup (int N, int m [N][N]) {
    int i, j;
    for (i=1; i<N; i++){            //ir a cada linha (nao se começa na linha 1 (que tem indice 0) porque nao interessa para ser triangular superior)
        for (j=0; j<i; j++){        //analisar se as i primeiras posiçoes sao todas zero
            if (m[i][j] != 0) return 0;
        }
    }
    return 1;
}


// 40
/*
  Defina uma função "void transposta (int N, float m[N][N])" que transforma
  uma matriz na sua transposta.
*/

void transposta (int N, float m [N][N]) {
    int c, l, tmp;
    for (l=0; l<N; l++){
        for (c=0; c<l; c++){        // ATENCAO AO CASO WHILE DAQUI
            tmp=m[l][c];            //A RESOLUÇAO CONSISTE EM TROCAR A COLUNA COM A LINHA 
            m[l][c]=m[c][l];
            m[c][l]=tmp;
        }
    }
}


// 41
/*
  Defina uma função "void addTo (int N, int M, int a [N][M], int b[N][M])"
  que adiciona a segunda matriz à primeira.
*/
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int l, c;
    for (l=0; l<N; l++){
        for (c=0; c<M; c++){
            a[l][c] += b[l][c];
        }
    }
    return;
}

// 42
#include <stdio.h>
 /* a função 
   int unionSet (int N, int v1[N], int v2[N], int r[N])
   que coloca no array \texttt{r} o resultado da união 
   dos conjuntos v1 e v2.
*/
   int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int i;
       for (i=0; i<N; i++){
           if (v1[i]>0) r[i]=v1[i];     //se v1 for 1 (>0) entao fica e passa para o i seguinte, caso contrario fica o que estiver no outro, quer seja 0 ou 1 (uma vez que e smpr maior ou igual ao do v1)
           else r[i]=v2[i];
       }
       return 0;
   }


// 43
#include <stdio.h>
/* a função 
   int intersectSet (int N, int v1[N], int v2[N], int r[N]) 
   que coloca no array r o resultado da intersecção 
   dos conjuntos v1 e v2.
*/

   int intersectSet (int N, int v1[N], int v2[N], int r[N]){
       int i;
       for (i=0; i<N; i++){
           if (v1[i]==v2[i]) r[i]=v1[i];          //ou r[i]==v2[i]
           else r[i]=0;
       }
       return 0;
   }


/*

//OUTRO MODO:

   int intersectSet (int N, int v1[N], int v2[N], int r[N]) {
       int i;
       for (i=0; i!=N; i++) {
           if (v1[i] == 0) r[i] = 0;    //se um deles for zero, a interseçao vai dar logo zero, caso nao seja dará o valor que estiver no outro array (no mesmo indice, como é obvio)
           else                         // uma vez que :  0 /\ x = 0, caso o primeiro seja zero, da logo zero.
                r[i] = v2[i];           // caso o primeiro seja != :   1 /\ x = x 
       }
       return 0;
   }
   
   */



// 44
#include <stdio.h>

/* a função 
   int intersectMSet (int N, int v1[N], int v2[N], int r[N])
   que coloca no array r o resultado da intersecção 
   dos multi-conjuntos v1 e v2.
*/

   int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i=0;i<N;i++){
        if (v1[i]>v2[i]) r[i]=v2[i];                                            //ENTENDER COMO FUNCIONA ESTE
        else r[i]=v1[i];
    }
    return 0;
   }




/*     OUTRO MODO:

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int i; 
      for(i=0;i<N;i++){
        if(v1[i]==v2[i])
            r[i]=v1[i];
            else if (v1[i]<v2[i])
             r[i]=v1[i];
             else r[i]=v2[i];
   }
   return 0;
}
*/

// 45
#include <stdio.h>

/* a função 
   int unionMSet (int N, int v1[N], int v2[N], int r[N]) 
   que coloca no array r o resultado da união dos 
   multi-conjuntos v1 e v2.
*/

   int unionMSet (int N, int v1[N], int v2[N], int r[N]){
     int i;
     for (i=0; i<N; i++){
         if (v1[i]==v2[i])                //fica qqr um
            r[i]=v1[i];
            else if (v1[i]<v2[i])         //fica sempre o maior 
                    r[i]=v2[i];
                    else r[i]=v1[i];      //como os outros nao se verificaram entao fica como se tivesse um: (if v1[i]>v2[i])
     }
     return 0;
   }
   
   

// 46
#include <stdio.h>
/* a função 
   int cardinalMSet (int N, int v[N]) que calcula o 
   número de elementos do multi-conjunto v.
*/

   int cardinalMSet (int N, int v[N]){
   	  int sum=0, i;
   	  for (i=0; i<N; i++){
   	      sum = sum + v[i];
   	  }
   	  return sum;
   }

// 47
#include "posicao.h"
#include <stdio.h>


Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for (i=0; i<N; i++){
        if (mov[i]==Norte)
            inicial.y +=1;
        else if (mov[i]==Sul)
                inicial.y -=1;
        else if (mov[i]==Oeste)
                inicial.x -=1;
        else inicial.x +=1;
    }
    return inicial;
}

// 48
#include <stdio.h>
#include "posicao.h"

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    
    for (i=0;  (inicial.x != final.x || inicial.y != final.y); i++){
        if (inicial.x > final.x){
            inicial.x -= 1;
            mov[i] = Oeste;
        }
            else if (inicial.x < final.x){
                    inicial.x += 1;
                    mov[i] = Este;                      //FAZER CHEGAR AO PONTO E DEPOIS AVALIAR SE O NUMERO DE COORDENADAS NECESSARIAS É MAIOR QUE N.
            }
                else if (inicial.y > final.y){
                        inicial.y -= 1;
                        mov[i] = Sul;
                }
                    else  {inicial.y +=1;
                          mov[i] = Norte;
                    }
    }
    if (i>N) return -1;
    else return i;
}

// 49
#include "maiscentral.h"
#include "math.h"

int maiscentral (Posicao pos[], int N) {
    int i;
    int indMin = 0;
    int distMin = (abs(pos[0].x) + abs(pos[0].y));
    for (i=0; i!=N; i++){
        if ((abs(pos[i].x) + abs(pos[i].y)) < distMin){
            distMin = (abs(pos[i].x) + abs(pos[i].y));
            indMin = i;
    }
    }
    return indMin;
}



// 50
#include "vizinhos.h"

int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, conta=0;
    for (i=0; i<N; i++){
        if ( abs(pos[i].x - p.x) + abs(pos[i].y - p.y) == 1){
            conta++;
        }
    }
    return conta;
}

