#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void conversao(char *infixa, char *posfixa) {
    int i, j;
    char c;

    for (i = 0, j = 0; infixa[i] != '\0'; i++) { //percorre a string infixa
        c = infixa[i]; //a variavel c é utilizada para comparar cada elemento da string, individualmente

        if (isdigit(c) || isalpha(c)) { //vê se é numero ou letra
            posfixa[j++] = c;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int prioridade = prioridade_operador(c);

            if (prioridade == 1) {
                conversao(&infixa[i+1], &posfixa[j]); //analisa os proximos termos
                j += strlen(&posfixa[j]); //incrementa o j com o tamanho da posfixa naquela posição j
                posfixa[j++] = c; //depois adiciona o operador
            } else if (prioridade == 2) {
                posfixa[j++] = c; //salva primeiro o operador, depois analisa o proximo termo
                conversao(&infixa[i+1], &posfixa[j]);
                j += strlen(&posfixa[j]); 
            } else {
                printf("Operador invalido: %c\n", c);
                exit(EXIT_FAILURE);
            }

            while (isdigit(infixa[i+1]) || isalpha(infixa[i+1])) {
                posfixa[j++] = infixa[++i];
            }
        }
    }

    posfixa[j] = '\0'; //coloca um \0 no final da string posfixa, apos ela terminar de ser construida
}

int prioridade_operador(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*': 
        case '/':
            return 2; //prioridade maior
        default:
            return 0;
    }
}

int main() {
    char infixa[100], posfixa[100];

    printf("Digite a expressao infixaa: ");
    fgets(infixa, sizeof(infixa), stdin);
    infixa[strcspn(infixa, "\n")] = '\0'; //substitui na string infixa. Coloca-se \0 onde estiver com \n

    conversao(infixa, posfixa);

    printf("Expressao posfixa: %s\n", posfixa);

    return 0;
}


