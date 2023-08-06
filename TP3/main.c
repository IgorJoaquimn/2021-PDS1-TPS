#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pessoa
{
    char nome[51];
    int idade;
    struct Pessoa **filhos;
    int numFilhos;

} Pessoa;


void imprimir_nivel(int nivel){ printf("%d\n", nivel);}

struct Pessoa* buscaPessoa (struct Pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel)
{
    if(!strcmp(pessoaAsc->nome,nomeProcurado)) return pessoaAsc;

    for (int i = 0; i < (pessoaAsc->numFilhos); i++)
    {
        if(!strcmp(pessoaAsc->filhos[i]->nome,nomeProcurado)){
            nivel++;
            if(imprimeNivel) imprimir_nivel(nivel);
            return pessoaAsc->filhos[i];
        }
    }
    for (int i = 0; i < (pessoaAsc->numFilhos); i++)
    {
        Pessoa *pointer = buscaPessoa(pessoaAsc->filhos[i], nomeProcurado, nivel+1, imprimeNivel);
        if(pointer) return pointer;
    }
    return NULL;

}


void popula_arvore(Pessoa *arvore,int n)
{
    char input[256];
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < n; i++)
    {
        // leitura de dados na estrutura FILHO IDADE ASCENDENTE
        fgets(input, sizeof(input), stdin);
        
        char ascendente_nome[51];
        sscanf(input, "%s %d %s", arvore[i].nome, &arvore[i].idade, ascendente_nome);

        // inicializaçao de variaveis
        arvore[i].filhos    = NULL;
        arvore[i].numFilhos = 0;

        // Condicional para se o nome do ascendente for DIFERENTE de NULL
        if (strcmp(ascendente_nome, "NULL"))
        {
            Pessoa *pointer = buscaPessoa(&arvore[0], ascendente_nome,0,0);
            pointer->filhos = (Pessoa **)realloc(pointer->filhos, sizeof(Pessoa *) * (pointer->numFilhos + 1));
            pointer->filhos[pointer->numFilhos] = &arvore[i];
            pointer->numFilhos++;
        }
    }
}

void libera_arvore(Pessoa *arvore,int n)
{
    for (int i = 0; i < n; i++)
        free(arvore[i].filhos);
}

int main()
{

    // leitura das N pessoas a serem cadastradas
    int n;
    scanf("%d", &n);
    Pessoa arvore[n];

    // povoamento da arvore
    popula_arvore(arvore,n);

    // leitura das consultas
    int m;
    scanf("%d",&m);
    char input[256];
    fgets(input, sizeof(input), stdin);

    for(int i = 0; i <m; i++)
    {
        fgets(input, sizeof(input), stdin);

        char ascendente_nome[51];
        char descendente_nome[51];
        sscanf(input, "%s %s", descendente_nome, ascendente_nome);
        Pessoa *pointer = buscaPessoa(&arvore[0], ascendente_nome,0,0);
        buscaPessoa(pointer, descendente_nome,0,1);
    }
    
    libera_arvore(arvore,n);
}
