#include <stdio.h>
#define TAM 101
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void imprimir(){
     printf("*** Bem vindo ao Simpletron! ***\n"
            "*** Por favor digite uma instrucao (ou palavra ***\n"
            "*** de dados) de seu programa por vez. Digitarei o ***\n"
            "*** numero da posicao e um ponto de interrogação ***\n"
            "*** (?). Digite então a palavra para aquela posição ***\n"
            "*** Digite o valor sentinela -9999 para encerrar a ***\n"
            "*** digitacao de seu programa. ***\n");
}

void inicializarMemoria(int memoria[TAM]){
    for(int x = 0; x < TAM; x++){
        memoria[x] = 0000;
    }
}

void despejo(int acumulador, int contadorInstrucao, int codigoOperacao, int operando, int registroInstrucao, int memoria[TAM]){
    printf("REGISTROS: \n");
    printf("acumulador: %d\n", acumulador);
    printf("contadorInstrucao: %d\n", contadorInstrucao);
    printf("registroInstrucao: %d\n", registroInstrucao);
    printf("codigoOperacao: %d\n", codigoOperacao);
    printf("operando: %d\n", operando);
    printf("        0      1      2      3      4      5      6      7      8      9\n");
    printf("0");
    for(int j = 0; j < 10; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n10");
    for(int j = 10; j < 20; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n20");
    for(int j = 20; j < 30; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n30");
    for(int j = 30; j < 40; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n40");
    for(int j = 40; j < 50; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n50");
    for(int j = 50; j < 60; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n60");
    for(int j = 60; j < 70; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n70");
    for(int j = 70; j < 80; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n80");
    for(int j = 80; j < 90; j++){
        printf("   %d", memoria[j]);
    }
    printf("\n90");
    for(int j = 90; j < 100; j++){
        printf("   %d", memoria[j]);
    }
}

int main (){
    int memoria[TAM], acumulador = 0,   contadorInstrucao = 0, codigoOperacao = 0, operando = 0, registroInstrucao = 0;
    int i = 0, aux = 0;

    inicializarMemoria(memoria);
    imprimir();

    while(1){
        printf("%d ? ", i);
        scanf("%d", &aux); // intermédio utilizado para verificar a instrução antes de salvar na memória
        if(aux == -9999){
            break;
        }else if(aux < -9999 || aux > 9999){ // verifica se a instrução está no intervalo correto
            printf("*** Instrucao incorreta ***\n");
        }else{
            memoria[i] = aux;
            i++;
        }
    }
    printf("*** Carregamento do programa concluido ***\n*** Inicio da execucao do programa ***\n\n");

    while(contadorInstrucao < i){
        registroInstrucao = memoria[contadorInstrucao];
        codigoOperacao = registroInstrucao / 100;
        operando = registroInstrucao % 100;

        switch(codigoOperacao){
        case 0:
            contadorInstrucao++;
            break;
        case 10:
            printf("? ");
            scanf("%d", &memoria[operando]);
            contadorInstrucao++;
            break;
        case 11:
            printf("%d:  %d\n", operando, memoria[operando]);
            contadorInstrucao++;
            break;
        case 20:
            acumulador = memoria[operando];
            contadorInstrucao++;
            break;
        case 21:
            memoria[operando] = acumulador;
            contadorInstrucao++;
            break;
        case 30:
            acumulador += memoria[operando];
            contadorInstrucao++;
            break;
        case 31:
            acumulador -= memoria[operando];
            contadorInstrucao++;
            break;
        case 32:
            if(acumulador == 0){
                printf("*** Tentativa de dividir por zero ***\n");
                printf("*** Interrupcao anormal da execucao do Simpletron ***\n");
                contadorInstrucao = i;
            }else{
                acumulador = memoria[operando] / acumulador;
                contadorInstrucao++;
            }
            break;
        case 33:
            acumulador = memoria[operando] * acumulador;
            contadorInstrucao++;
            break;
        case 40:
            contadorInstrucao = operando;
            break;
        case 41:
            if(acumulador < 0){
                contadorInstrucao = operando;
            }else{
                contadorInstrucao++;
            }
            break;
        case 42:
            if(acumulador == 0){
                contadorInstrucao = operando;
            }else{
                contadorInstrucao++;
            }
            break;
        case 43:
            printf("*** Execucao do Simpletron concluida ***\n\n");
            contadorInstrucao = i;
            break;
        default:
            printf("*** Codigo de instruçao invalida! ***");
            contadorInstrucao++;
            break;
        }
        if(acumulador > 9999 || acumulador < -9999){
            printf("*** Overflow do acumulador ***\n");
            printf("*** Interrupcao anormal da execucao do Simpletron ***\n");
            break;
        }
    }
    despejo(acumulador, contadorInstrucao, codigoOperacao, operando, registroInstrucao, memoria);

    return 0;
}
