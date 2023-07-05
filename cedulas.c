#include <stdio.h>

int main()
{
    double valor;
    int parte_notas, parte_moedas;
    printf("Insira uma quantia: ");
    scanf("%lf", &valor);

    parte_notas = (int)valor;
    parte_moedas = (int)((valor - parte_notas) * 100);

    printf("Valo total: %.2lf\n", valor);
    printf("Parte notas: %d\n", parte_notas);
    printf("Parte moedas: %d\n", parte_moedas);

    printf("Quantidade de notas e moedas:\n");
    printf("%d notas de 100\n", parte_notas / 100);
    parte_notas %= 100;
    printf("%d notas de 50\n", parte_notas / 50);
    parte_notas %= 50;
    printf("%d notas de 20\n", parte_notas / 20);
    parte_notas %= 20;
    printf("%d notas de 10\n", parte_notas / 10);
    parte_notas %= 10;
    printf("%d notas de 5\n", parte_notas / 5);
    parte_notas %= 5;
    printf("%d notas de 2\n", parte_notas / 2);
    parte_notas %= 2;
    printf("%d moedas de 1\n", parte_notas / 1);
    parte_notas %= 1;
    printf("%d moedas de 0,5\n", parte_moedas / 50);
    parte_moedas %= 50;
    printf("%d moedas de 0,25\n", parte_moedas / 25);
    parte_moedas %= 25;
    printf("%d moedas de 0,1\n", parte_moedas / 10);
    parte_moedas %= 10;
    printf("%d moedas de 0,05\n", parte_moedas / 5);
    parte_moedas %= 5;
    printf("%d moedas de 0,01\n", parte_moedas / 1);
}
