#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - Nível Mestre


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
                        break;
                    }
                else if (eixoY < 0 || eixoX < 0 || eixoY > 9 || eixoX > 9)
                    {
                        printf("Seu navio está fora dos limites!\n\n");
                        parte_navio = 3;
                        error[0] = 1;
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
                                //retorna uma mensagem de erro caso a direção seja inválida, ou seja, se for diferente de 1, 2, 3 ou 4.
                                return printf("A direção especificada não é válida!");
                            }
                    }

            }
        

    }

//Função que cria o cone/trigângulo 5x5
int criarCone(int cone[5][5])
    {
        
    int centro = 2; 
    for (int a = 0; a < 5; a++) 
        {
            for (int b = 0; b < 5; b++) 
                {
                    if (b >= centro - a && b <= centro + a && a < 3) 
                        {
                            cone[a][b] = 1; 
                        } 
                    else 
                        {
                            cone[a][b] = 0;
                        }
                    
                }
            
        }
        
    }

//Função que cria a cruz
int criarCruz(int cruz[5][5]) 
    {
        int centro = 2; 
        for (int a = 0; a < 5; a++) 
            {
                for (int b = 0; b < 5; b++) 
                    {
                        if (a == centro || b == centro) 
                            {
                                cruz[a][b] = 1; 
                            } 
                        else
                            {
                                cruz[a][b] = 0; 
                            }
                        
                    }
            
            }
    }

//Função que cria o losango (Octaedro)
int criarLosango(int losango[5][5]) 
    {
        int centro = 2; 
        int raio = 2;   
        for (int a = 0; a < 5; a++) 
            {
                for (int b = 0; b < 5; b++) 
                    {
                        if (abs(a - centro) + abs(b - centro) <= raio) 
                            {
                                losango[a][b] = 1; 
                            } 
                        else 
                            {
                                losango[a][b] = 0; 
                            }
                    
                    }
                
            }
    }

//Função para aplicar a habilidade (matriz de habilidade, matriz do tabuleiro atual, posição x e posição y)
int aplicarHabilidade(int habilidade[5][5], int tabuleiro[10][10], int origemX, int origemY) 
    {
        int centro = 2;

        for (int i = 0; i < 5; i++) 
            {
                for (int j = 0; j < 5; j++) 
                    {
                        if (habilidade[i][j] == 1) 
                            {
                                int tabLinha = origemX + (i - centro);
                                int tabColuna = origemY + (j - centro);

                                // Condicional para impedir que a habilidade ultrapasse os limites do tabuleiro
                                if (tabLinha >= 0 && tabLinha < 10 && tabColuna >= 0 && tabColuna < 10) 
                                    {   
                                        tabuleiro[tabLinha][tabColuna] = 5; 
                                    }
                            }
                    }
            }
    }


//Função principal
int main() 
    {

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
        Para mais informações, consultar a função "posicionarNavios()"
        */
        int navioUm[3] = {1, 2, 1};
        int navioDois[3] = {4, 6, 2};
        int navioTres[3] = {5, 1, 3};
        int navioQuatro[3] = {4, 10, 4};

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
        //Matrix para criar um cone 5x5
        int matrizCone[5][5];
        criarCone(matrizCone);
        aplicarHabilidade(matrizCone, tabuleiro, 5, 5);

        //Matriz para criar uma cruz 5x5
        int matrizCruz[5][5];
        criarCruz(matrizCruz);
        aplicarHabilidade(matrizCruz, tabuleiro, 2, 7);

        //Matriz para criar um losango 5x5
        int matrizLosango[5][5];
        criarLosango(matrizLosango);
        aplicarHabilidade(matrizLosango, tabuleiro, 8, 3); 

        exibirTabuleiro(tabuleiro);
            

        return 0;
    }
