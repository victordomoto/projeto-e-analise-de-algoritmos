/*Nome: Victor Akio Domoto      */
/*RA: 150546 - PAA - UNIFESP    */

#include <stdio.h>
#include <stdlib.h>

//Funcao que calcula a posicao do vetor para atribuir a nova media (similar ao espalhamento de uma tabela hash)
int calculaPosicao(int contador){
    return contador % 30;
}

//Funcao que calcula a mediaAtual dos ultimos 30 dias
int calcularMediaAtual (int soma){
    if ((soma%30)==0)
        return soma/30;
    else
        return (soma/30)+1;
}

//Funcao que ira estimar a quantidade de dias para uma quantidade M de pessoas
int estima (int quantInicial, int quantFinal, int *quantNovosUsuarios, int soma){
    int quantAtual = 0, cont = 0, med = 0, pos = 0;
    int quantNecessaria = quantFinal - quantInicial;
    
    while (quantAtual < quantNecessaria){
        pos = calculaPosicao(cont);
        //Calculando a media a partir da soma da quantidade de pessoas dos ultimos 30 dias
        med = calcularMediaAtual(soma);
        //Reajustando o valor da soma total dos vetores (atuais) para o calculo da media
        soma -= quantNovosUsuarios[pos];
        soma += med;
        //Atribuindo a nova media no vetor
        quantNovosUsuarios[pos] = med;
        quantAtual += med;
        cont++;
    }
return cont;
}


int main(){
    int quantInicial, quantFinal, i = 0, dias = 0, soma=0;
    int quantNovosUsuarios[30];

    scanf("%d %d", &quantInicial, &quantFinal);

    for (i=0; i<30; i++){
        scanf("%d", &quantNovosUsuarios[i]);
        soma += quantNovosUsuarios[i];
    }

    dias = estima(quantInicial, quantFinal, quantNovosUsuarios, soma);
    printf("%d\n", dias);
return 0;
}