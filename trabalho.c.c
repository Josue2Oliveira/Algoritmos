#include<stdio.h>
int sucesso()
{
    // Codigo que gera uma sequencia pseudo-aleat ́oria
    static unsigned long long int seed = 123456789;
    seed = (1103515245 * seed + 12345) % 2147483648;
    // Teste da probabilidade de a conoa chegar ao destino
    return seed >= 2147483648/2;
}
int main ()
{
    int N,M,NC,i,j,T=0,A=0,Y=0; //DECLARACAO DAS VARIAVEIS
    float P;//DECLARACAO DE VARIAVEL
    printf("Digite o numero de canoas, quantidade minima esperada de canoas e numero de repeticoes, respectivamente:\n");
    scanf("%d %d %d",&N,&M,&NC);

    if((N<0)||(M<0)||(NC<0)||(NC>1000000000)){//TESTA SE OS NUMEROS DIGITADOS ENTRAM NAS CONDICOES.
        printf("Os dados foram digitados de forma incorreta  ou nc e maior que 10^9\n");
        return 0;
    }

    if (N<M)//TESTE SE O VALOR DE CANOAS NAO FOR COERENTE COM A QUANTIDADE ESPERADA, FECHA O PROGRAMA.
    {
        printf("numero de canoas ou numero de canoas esperada invalidos.\n");
        return 0;
    }

    for (i=0; i<NC; i++)//ESTE FOR SERVEPARA CALCULAR O NUMERO DE REPETICOES
    {
        Y=0;//REINICIA O NUMERO DE CANOAS PARA NOVA CONTAGEM
        for (j=0; j<N; j++)
        {
            T= sucesso();//AGREGA A "T" O VALOR DE SUCESSO
            if (T==1)// SE O VALOR FOR 1, OU SEJA, OBTEVE SUCESSO, AGREGA 1 A "Y"
            {
                Y++;
            }
        }
        if (Y>=M)//TESTA SE O VALOR DE CANOAS QUE TIVERAM SUCESSO EH IGUAL OU MAIOR QUE O VALOR DE ESPERADAS, E SOMA 1 AO "A"
        {
            A++;
        }
    }
    P=(float)A/NC;/*TRANSFORMA O VALOR O "A" EM FLOAT PARA A DIVISAO ACONTECER,
    E DIVIDE O VALOR DE VIAGENS QUE O NUMERO MINIMO DE CANOAS CHEGARAM PELAS REPETICOES.*/
    P=P*100.0;//MULTIPLICA POR 100 PARA OBTER UM VALOR EM PORCENTAGEM.
    printf("P: %.2f%%.\n", P);//IMPRIME O VALOR,EM PORCENTAGEM, DAS VIAGENS EM QUE O NUMERO DE CANOAS FOI MAIOR OU IGUAL QUE O ESPERADO.
    return 0;
}

