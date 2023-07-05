#include <iostream>
#include <string>
using namespace std;

class Caracter
{
public:
    char elem;
    Caracter *prox;
    Caracter *ant;

    Caracter()
    {
        elem = ' ';
        prox = nullptr;
        ant = nullptr;
    }

    ~Caracter()
    {
        delete prox;
        delete ant;
    }
};

class Linha
{
public:
    Caracter *prim;
    Linha *prox;
    Linha *ant;

    Linha()
    {
        prim = new Caracter;
        prox = nullptr;
        ant = nullptr;
    }

    ~Linha()
    {
        Caracter *aux = prim;
        while (aux != nullptr)
        {
            Caracter *aux2 = aux->prox;
            delete aux;
            aux = aux2;
        }
    }

    void imprimirLinha()
    {
        Caracter *aux = prim;
        while (aux != NULL)
        {
            cout << aux->elem;
            aux = aux->prox;
        }
        cout << "\n";
    }
};

class Texto
{
private:
    Linha *prim;
    int tam;

public:
    Texto()
    {
        prim = new Linha;
        tam = 1;
    }

    void inserirLinha()
    {
        Linha *aux = prim;
        Linha *novo = new Linha;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        tam++;
    }

    void inserirCaracter(int linha, char c)
    {
        Linha *aux = prim;
        for (int i = 0; i < linha; i++)
        {
            aux = aux->prox;
        }
        if (aux->prim->elem == ' ')
        {
            aux->prim->elem = c;
        }
        else
        {
            Caracter *aux2 = aux->prim;
            Caracter *novo = new Caracter;
            novo->elem = c;
            while (aux2->prox != NULL)
            {
                aux2 = aux2->prox;
            }
            aux2->prox = novo;
        }
    }

    void imprimirTexto()
    {
        Linha *aux = prim;
        while (aux != NULL)
        {
            aux->imprimirLinha();
            aux = aux->prox;
        }
    }
};

int main()
{
    Texto t;
    t.inserirLinha();
    t.inserirCaracter(0, 'o');
    t.inserirCaracter(0, 'i');
    t.inserirCaracter(1, 'b');
    t.inserirCaracter(1, 'l');
    t.inserirCaracter(1, 'z');
    t.inserirCaracter(1, '?');
    t.imprimirTexto();
}
