
int validaEntradaLinhaColuna(int linha, char coluna)
{
    if((linha >= 1 && linha <= 10) && (coluna >= 65 && coluna <= 74))
    {
        return 1;
    }

    else return 0;
}

int validaPosicao(int mat[10][10], int barco, int linha, int coluna, char orientacao)
{
    int cont = 0;
    int i, j;

    if(barco < 1 || barco > 3) return 0;
    if(orientacao != 'H' && orientacao != 'V') return 0;
    if((linha < 0 || linha > 9) || (coluna < 0 || coluna > 9)) return 0;

        if(orientacao == 'H')
        {
            if((10 - coluna) < barco) return 0;

            else
            {
                for(j = coluna; j < (coluna+barco); j++)
                {
                    if(mat[linha][j] == 0) cont++;
                }
            }
        }

        if(orientacao == 'V')
        {
            if((10 - linha) < barco) return 0;

            else
            {
                for(i = linha; i < (linha+barco); i++)
                {
                    if(mat[i][coluna] == 0) cont++;
                }
            }
        }

            if(cont == barco)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }


int podeAtirar(int mat[10][10], int linha, int coluna)
{
    if(mat[linha][coluna] == -2 || mat[linha][coluna] == 10 || mat[linha][coluna] == 20 || mat[linha][coluna] == 30 || mat[linha][coluna] == 50)
    {
        return 0;
    }

    else
    {
        return 1;
    }
}
