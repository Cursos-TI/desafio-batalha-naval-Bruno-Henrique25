#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

//Função que cria uma matriz para o tabuleiro e a atribui a sua variável correspondente.
int criarTabuleiro(int matriz[10][10]) 
    {
    for (int x=0; x < 10; x++) 
        {
            for(int y=0; y <10; y++)
            {
                matriz[x][y] = 0;
            }
        }
    }

//Função para exibir o tabuleiro mediante a sua variável como parâmetro.
int exibirTabuleiro(int matriz[10][10]) 
    {
        printf("   A B C D E F G H I J\n");
        for (int x=0; x < 10; x++)
            {
                if (x < 9) 
                    {   
                        printf("%d  ", x+1);
                    }
                else
                    {
                        printf("%d ", x+1);
                    }
                for (int y=0; y < 10; y++)
                    {
                        printf("%d ", matriz[x][y]);
                    };
                printf("\n");
            }
    }

//Função para posicionar os navios. coordenadas: eixos X e Y respectivamente
int posicionarNavios(int coordenadas[3], int mapa[10][10], int error[1]) 
    {
      
        
        
        /*Armazena o valor da direcao do navio (horizontal, vertical ou diagonal)
        1 = vertical
        2 = horizontal
        3 = diagonal
        */
        int direcao = coordenadas[2];
        int eixoX = coordenadas[0]-1;
        int eixoY = coordenadas[1]-1;
        
        for (int parte_navio = 0; parte_navio < 3; parte_navio++) 
            {
                if (mapa[eixoX][eixoY] == 3)
                    {
                        printf("Você não pode sobrepor navios!\n\n");
                        parte_navio = 3;
                        error[0] = 1;
                        //return error;
                        break;
                    }
                else if (eixoY < 0 || eixoX < 0 || eixoY > 9 || eixoX > 9)
                    {
                        printf("Seu navio está fora dos limites!\n\n");
                        parte_navio = 3;
                        error[0] = 1;
                        //return error;
                        break;
                    }
                else
                    {    
                        
                        mapa[eixoX][eixoY] = 3;

                        if (direcao == 1) 
                            {
                                eixoX++;
                            }
                        else if (direcao == 2) 
                            {
                                eixoY++;
                            }
                        else if (direcao == 3)
                            {
                                eixoX++;
                                eixoY++;
                            }
                        else 
                            {
                                return printf("A direção especificada não é válida!");
                            }
                    }

            }
        

    }
int main() {

//Declara a variável do tabuleiro com um tamanho de 10x10
int tabuleiro[10][10];
int erros[1];
//Função para criar a matriz do tabuleiro, passando sua variável como parâmetro.
criarTabuleiro(tabuleiro);

int navioUm[3] = {1, 2, 1};
int navioDois[3] = {4, 2, 2};

posicionarNavios(navioUm, tabuleiro, erros);
posicionarNavios(navioDois, tabuleiro, erros);
if (erros[0] == 1) 
    {
        printf("Erros detectados!\n\n\nEncerrando...\n\n");
        return 0;
    }
  
//Função que exibe o tabuleiro, novamente usando sua variável como parâmetro, após a modificação na função criarTabuleiro()
exibirTabuleiro(tabuleiro);
    

    return 0;
}
