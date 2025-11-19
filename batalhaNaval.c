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
        1 = vertical (paralelo às colunas de A a J)
        2 = horizontal (paralelo às linhas de 1 a 10)
        3 = diagonal 1 (de cima para baixo e da esquerda para a direita)
        4 = diagonal 2 (de cima para baixo e da direita para a esquerda)

        a partir da posição e direção definidas pelas coordenas, o navio será "montado" iniciando com numero 3 na 
        coordenada inicial e, após isso serão incrementados ou decrementados os eixos X, Y ou ambos, de modo que
        as 2 peças restantes da embarcação sejam posicionadas no mapa.

        Exemplo: 

        Matriz: 

        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0
        0 0 0 0 0

        navio = {2, 3, 2}
        resultado: 

        0 0 0 0 0
        0 0 3 3 3
        0 0 0 0 0
        0 0 0 0 0
        */

        //Variável da direção
        int direcao = coordenadas[2];
        //Eixo X (linha)
        int eixoX = coordenadas[0]-1;
        //eixo Y (colunas)
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
                        else if(direcao == 4)
                            {
                                eixoX++;
                                eixoY--;
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

/*Variáveis dos navios
as primeiras duas posições representam x e y, linha e coluna, respectivamente!

exemplo: 

matriz: 
0 0 0 0 
0 0 0 0
0 0 0 0

navio = {1, 1, 1} 
resultado: 

3 0 0 0
0 3 0 0
0 0 3 0

NOTA: navio[2] (elemento 3) refere-se à direção desejada para posicionamento da embarcação
Para mais informações, conslutar a função "posicionarNavios()"
*/
int navioUm[3] = {1, 2, 1};
int navioDois[3] = {4, 6, 2};
int navioTres[3] = {5, 1, 3};
int navioQuatro[3] = {6, 10, 4};

//Posicionando cada navio por meio da função "posicionarNavios()" que os posiciona nas coordenadas e direção adequadas, bem como tratamento de erros.
posicionarNavios(navioUm, tabuleiro, erros);
posicionarNavios(navioDois, tabuleiro, erros);
posicionarNavios(navioTres, tabuleiro, erros);
posicionarNavios(navioQuatro, tabuleiro, erros);
if (erros[0] == 1) 
    {
        printf("Erros detectados!\n\n\nEncerrando...\n\n");
        return 0;
    }
  
//Função que exibe o tabuleiro, novamente usando sua variável como parâmetro, após a modificação na função criarTabuleiro()
exibirTabuleiro(tabuleiro);
    

    return 0;
}
