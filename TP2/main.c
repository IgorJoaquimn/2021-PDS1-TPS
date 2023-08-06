#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct funcionario
{
    char nome[255];
    float salario;
    char data[12];
    char departamento[255];
} funcionario_t;

FILE *criaArquivo(char str[], char modo[])
{
    FILE *fp;
    fp = fopen(str, modo);
    if (fp == NULL)
    {
        puts("Deu erro ai rapaz");
        exit(1);
    }
    return fp;
}

void leitura(FILE *fp, funcionario_t lista[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        fscanf(fp, "%[^\n]s", lista[i].nome);
        fscanf(fp, "%f\n", &lista[i].salario);
        fscanf(fp, "%s\n", lista[i].data);
        fscanf(fp, "%s\n", lista[i].departamento);
    }
}

void printa(funcionario_t lista[], int qtd)
{
    for (int i = 0; i < qtd; i++)
        printf("%s\n%.2f\n%s\n%s\n", lista[i].nome, lista[i].salario, lista[i].data, lista[i].departamento);
}

int gera_lista_por_departamento(funcionario_t lista[], int qtd, char departamento[], funcionario_t departamento_lista[])
{
    int departamento_qtd = 0;
    int cont = 0;
    for (int i = 0; i < qtd; i++)
        if (!strcmp(lista[i].departamento, departamento))
        {
            departamento_qtd++;
            departamento_lista[cont] = lista[i];
            cont++;
        }
    return departamento_qtd;
}

void ordena_lista(funcionario_t lista[], int qtd)
{
    for (int i= 0; i < qtd; i++)
        for (int j = i + 1; j < qtd; j++)
        {
            if (strcmp(lista[i].nome, lista[j].nome) > 0)
            {
                funcionario_t temp;
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
}

void exportar(funcionario_t lista[], int qtd, char filename[]);
void listar(funcionario_t lista[], int qtd, char departamento[]);
void encontrar_mais_antigo(funcionario_t lista[], int qtd);
void encontrar_dpt_mais_antigo(funcionario_t lista[], int qtd, char departamento[]);
void media_salarial(funcionario_t lista[], int qtd);
void media_dpt_salarial(funcionario_t lista[], int qtd, char departamento[]);

int main(int argc, char *argv[])
{
    FILE *fp = criaArquivo(argv[1], "r");
    int qtd;

    fscanf(fp, "%d\n", &qtd);
    funcionario_t lista[qtd];
    leitura(fp, lista, qtd);
    fclose(fp);

    int function = atoi(argv[2]);

    switch (function)
    {
    case 1:
        exportar(lista, qtd, argv[3]);
        break;
    case 2:
        listar(lista, qtd, argv[3]);
        break;
    case 3:
        encontrar_mais_antigo(lista, qtd);
        break;
    case 4:
        encontrar_dpt_mais_antigo(lista, qtd, argv[3]);
        break;
    case 5:
        media_salarial(lista, qtd);
        break;
    case 6:
        media_dpt_salarial(lista, qtd, argv[3]);
        break;

    default:
        break;
    }
}

void exportar(funcionario_t lista[], int qtd, char filename[])
{
    ordena_lista(lista,qtd);
    FILE *fp = criaArquivo(filename, "w");
    for (int i = 0; i < qtd; i++)
        fprintf(fp,"%s\n%.2f\n%s\n%s\n",lista[i].nome, lista[i].salario, lista[i].data, lista[i].departamento);
    fclose(fp);
    
}

void listar(funcionario_t lista[], int qtd, char departamento[])
{
    funcionario_t departamento_lista[qtd];
    int departamento_qtd = gera_lista_por_departamento(lista, qtd, departamento, departamento_lista);
    ordena_lista(departamento_lista,departamento_qtd);
    printa(departamento_lista,departamento_qtd);
}

void encontrar_mais_antigo(funcionario_t lista[], int qtd)
{
    int dia_antigo, mes_antigo, ano_antigo;
    int mais_antigo = 0;

    int dia, mes, ano;
    for (int i = 0; i < qtd; i++)
    {
        sscanf(lista[mais_antigo].data, "%d/%d/%d", &dia_antigo, &mes_antigo, &ano_antigo);
        sscanf(lista[i].data, "%d/%d/%d", &dia, &mes, &ano);
        if (ano < ano_antigo)
        {
            mais_antigo = i;
            continue;
        }
        else if (ano == ano_antigo)
        {
            if (mes < mes_antigo)
            {
                mais_antigo = i;
                continue;
            }
            else if (mes == mes_antigo)
            {
                if (dia < dia_antigo)
                {
                    mais_antigo = i;
                    continue;
                }
            }
        }
    }

    printf("%s\n%.2f\n%s\n%s\n", lista[mais_antigo].nome, lista[mais_antigo].salario, lista[mais_antigo].data, lista[mais_antigo].departamento);
}

void encontrar_dpt_mais_antigo(funcionario_t lista[], int qtd, char departamento[])
{
    funcionario_t departamento_lista[qtd];
    int departamento_qtd = gera_lista_por_departamento(lista, qtd, departamento, departamento_lista);
    encontrar_mais_antigo(departamento_lista, departamento_qtd);
}

void media_salarial(funcionario_t lista[], int qtd)
{
    double media = 0;
    for (int i = 0; i < qtd; i++)
        media += lista[i].salario;
    media = media / qtd;
    printf("%.2lf\n", media);
}

void media_dpt_salarial(funcionario_t lista[], int qtd, char departamento[])
{
    funcionario_t departamento_lista[qtd];
    int departamento_qtd = gera_lista_por_departamento(lista, qtd, departamento, departamento_lista);
    media_salarial(departamento_lista, departamento_qtd);
}