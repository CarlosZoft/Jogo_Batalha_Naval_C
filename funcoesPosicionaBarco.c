#include <stdio.h>
int validaEntradaLinhaColuna(int linha, char coluna)
{
    if(linha < 1 || linha > 10)
    {
        return 0;
    }

    if(coluna < 65 || coluna > 74)
    {
        return 0;
    }

    return 1;
}

int validaPosicao(int mat[10][10], int barco, int linha, int coluna, char orientacao)
{
    if(barco == 1)
    {
        if(mat[linha][coluna] == 0)
        {
            return 1;
        }

        return 0;
    }

    if(barco == 2)
    {
        if(orientacao == 'H')
        {
            if(coluna >= 9) return 0;

            if((mat[linha][coluna] == 0 && mat[linha][coluna + 1] == 0))
            {
                return 1;
            }

            return 0;
        }

        if(orientacao == 'V')
        {
            if(linha >= 9) return 0;

            if(linha + 1 <= 10 && (mat[linha][coluna] == 0 && mat[linha + 1][coluna] == 0))
            {
                return 1;
            }

            return 0;
        }
    }

    if(barco == 3)
    {
        if(orientacao == 'H')
        {
            if(coluna > 7) return 0;

            if(mat[linha][coluna] == 0 && mat[linha][coluna + 1] == 0 && mat[linha][coluna + 2] == 0)
            {
                return 1;
            }

            return 0;
        }

        if(orientacao == 'V')
        {
            if(linha > 7) return 0;

            if(mat[linha][coluna] == 0 && mat[linha + 1][coluna] == 0 && mat[linha + 2][coluna] == 0)
            {
                return 1;
            }

            return 0;
        }
    }
}

int podeAtirar(int mat[10][10], int linha, int coluna)
{
    if(mat[linha][coluna] == -2)
    {
        return 0;
    }

    else
    {
        mat[linha][coluna] = -2;
        return 1;
    }
}

void imprimeMensagem(char msg[1000])
{
        printf("************************\n");
        printf("*\n");
        printf("* %s\n", msg);
        printf("*\n");
        printf("************************\n");
}


char imprimeCelula(int celula, int etapa)
{
    if(etapa == 0)
    {
        if(celula == 0) return '.';

        if(celula == -1) return '*';

        if(celula == 1) return '1';

        if(celula == 2) return '2';

        if(celula == 3) return '3';
    }

    if(etapa == 1)
    {
        if(celula == 0 || celula == -1 || celula == 1 || celula == 2 || celula == 3) return '.';

        if(celula == -2) return 'x';

        if(celula == 10 || celula == 20 || celula == 30) return 'N';

        if(celula == 50) return 'A';
    }
}


void imprimeTabuleiro(int mat[10][10], int etapa)
{
    int celula;
    char imp;

    printf("     ");
    for(int i = 65; i < 75; i++)
    {
        printf("%c", i);
        if(i < 74) printf(" ");
    }
    printf("\n");

    for(int i = 0; i < 12; i++)
    {
        if(i > 0 && i < 11) printf("%02d ", i);
        else printf("   ");
        for(int j = 0; j < 12; j++)
        {
            if((i > 0 && i < 11) && (j > 0 && j < 11))
            {
                celula = mat[i-1][j-1];
                imp = imprimeCelula(celula, etapa);
                printf("%c", imp);
            }
            else printf("#");
            if(j < 11) printf(" ");
        }
        printf("\n");
    }
}

void posicionaBarco(int mat[10][10], int barco)
{
    int linha;
    char coluna;
    char orientacao;

        if(barco == 1) scanf("%d  %c", &linha, &coluna);
        else scanf("%d  %c  %c", &linha, &coluna, &orientacao);

    int col = (coluna - 65);

        int a = validaEntradaLinhaColuna(linha, coluna);
        int b = validaPosicao(mat, barco, linha - 1, col, orientacao);

        while(a != 1 || b != 1)
        {
            printf("Posicao indisponivel!\n");

            if(barco == 1) scanf("%d  %c", &linha, &coluna);
            else scanf("%d  %c  %c", &linha, &coluna, &orientacao);
            col = (coluna - 65);

            a = validaEntradaLinhaColuna(linha, coluna);
            b = validaPosicao(mat, barco, linha - 1, col, orientacao);
        }

        linha = linha - 1;
        col = (coluna - 65);

    if(barco == 1)
    {
        mat[linha][col] = 1;
    }

    if(barco == 2)
    {
        if(orientacao == 'H')
        {
            mat[linha][col] = 2;
            mat[linha][col + 1] = 2;
        }
        if(orientacao == 'V')
        {
            mat[linha][col] = 2;
            mat[linha + 1][col] = 2;
        }
    }

    if(barco == 3)
    {
        if(orientacao == 'H')
        {
            mat[linha][col] = 3;
            mat[linha][col + 1] = 3;
            mat[linha][col + 2] = 3;
        }
        if(orientacao == 'V')
        {
            mat[linha][col] = 3;
            mat[linha + 1][col] = 3;
            mat[linha + 2][col] = 3;
        }
    }

    imprimeTabuleiro(mat, 0);
}

int main() {
    int tabuleiro1[10][10] =      {0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                   0,0,0,0,0,0,0,0,0,0,
                                  };
    for(int i = 0; i < 6; i++)
    {
        posicionaBarco(tabuleiro1, 1);
    }
    for(int i = 0; i < 3; i++)
    {
        posicionaBarco(tabuleiro1, 2);
    }
    for(int i = 0; i < 2; i++)
    {
        posicionaBarco(tabuleiro1, 3);
    }

return 0;
}
