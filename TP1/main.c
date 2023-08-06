#include <stdio.h>

int  iniciaJogo();
void executaJogada(int x, int y,int tamanhoDoTabuleiro, char matriz[tamanhoDoTabuleiro][tamanhoDoTabuleiro]);
int  verificaEstadoJogo(int x, char matriz[x][x]);

int main(){
    // ENTRADA DE DADOS
    int qtdDeJogos; 
    scanf("%d",&qtdDeJogos);
    if(qtdDeJogos<=10){
        // Intera a funçao iniciaJogo a quantidade de vezes especificada pelo user
        for (int i1=1; i1<=qtdDeJogos; i1++){
            int resultado = iniciaJogo();
            if (resultado == 0)
                printf("PERDEU\n");
            if (resultado == 1)
                printf("GANHOU\n");
            if (resultado == 2)
                printf("FALTOU TERMINAR\n");
        }
    }
}

int iniciaJogo(){
    int tamanhoDoTabuleiro;
    scanf("%d",&tamanhoDoTabuleiro);
    // Getchar para pegar o \n excedente
    char matriz[tamanhoDoTabuleiro][tamanhoDoTabuleiro];

    char str[256];
    for (int i=0; i<tamanhoDoTabuleiro; i++)
        for (int j=0; j<tamanhoDoTabuleiro; j++)
            scanf(" %c",&matriz[i][j]);

    int qtdDeJogadas;
    scanf("%d",&qtdDeJogadas);

    for (int i2=0; i2<qtdDeJogadas; i2++){
        int x,y;
        scanf("%d %d",&x,&y);
        executaJogada(x,y,tamanhoDoTabuleiro,matriz);
        for (int i=0; i<tamanhoDoTabuleiro; i++){
            for (int j=0; j<tamanhoDoTabuleiro; j++){
                printf("%c ",matriz[i][j]);
            }
            printf("\n");
        }
    }

    return verificaEstadoJogo(tamanhoDoTabuleiro, matriz);
}

void executaJogada(int x, int y,int tamanhoDoTabuleiro, char matriz[tamanhoDoTabuleiro][tamanhoDoTabuleiro]){
    // b = bomba 
    // a = bomba clicada
    // x = espaço livre
    // o = espaço livre clicado 

    if (matriz[x][y] == 'b') {matriz[x][y] = 'a';}

    if (matriz[x][y] == 'x'){
        int bombaEmVolta = 0;
        matriz[x][y] = 'o';

        if (x < tamanhoDoTabuleiro - 1){
            if (matriz[x+1][y] == 'b' || matriz[x+1][y] == 'a') bombaEmVolta = 1;


            if (y < tamanhoDoTabuleiro - 1) 
                if (matriz[x+1][y+1] == 'b' || matriz[x+1][y+1] == 'a') bombaEmVolta = 1;

            if (y > 0)
                if (matriz[x+1][y-1] == 'b' || matriz[x+1][y-1] == 'a') bombaEmVolta = 1;
        }

        if (x > 0){
            if (matriz[x-1][y] == 'b' || matriz[x-1][y] == 'a') bombaEmVolta = 1;

            if (y < tamanhoDoTabuleiro - 1) 
                if (matriz[x-1][y+1] == 'b' || matriz[x-1][y+1] == 'a') bombaEmVolta = 1;

            if (y > 0)
                if (matriz[x-1][y-1] == 'b' || matriz[x-1][y-1] == 'a') bombaEmVolta = 1;
        }


        if (y < tamanhoDoTabuleiro - 1)
            if (matriz[x][y+1] == 'b' || matriz[x][y+1] == 'a') bombaEmVolta = 1;
        

        if (y > 0)
            if (matriz[x][y-1] == 'b' || matriz[x][y-1] == 'a') bombaEmVolta = 1;

        if (!bombaEmVolta){
            if (y < tamanhoDoTabuleiro - 1)
                matriz[x][y+1] = 'o';
            if (y > 0)
                matriz[x][y-1] = 'o';

            if (x < tamanhoDoTabuleiro - 1){
                matriz[x+1][y] = 'o';
                if (y < tamanhoDoTabuleiro - 1) 
                    matriz[x+1][y+1] = 'o';
                if (y > 0)
                    matriz[x+1][y-1] = 'o';
            }

            if (x > 0){
                matriz[x-1][y] = 'o';
                if (y < tamanhoDoTabuleiro - 1)
                    matriz[x-1][y+1] = 'o';
                if (y > 0)
                    matriz[x-1][y-1] = 'o';
            }

            
        }
        
    }

}

int  verificaEstadoJogo(int x, char matriz[x][x]){
    int jaPerdeu = 0;
    int naoTerminou = 0;

    for (int i=0; i<x; i++){
        for (int j=0; j<x; j++){
            
            if(matriz[i][j] == 'a'){
                jaPerdeu = 1;
            }
            if(matriz[i][j] == 'x'){
                naoTerminou = 1;         
            }
        }
        
    }

    if(jaPerdeu){
        return 0;
    }

    if(naoTerminou)
        return 2;

    return 1;
}