void atirar(int mat[10][10], int linha, int coluna)
{
    if(mat[linha][coluna] == 0 || mat[linha][coluna] == -1) mat[linha][coluna] = -2;

    if(mat[linha][coluna] == 1) mat[linha][coluna] = 10;

    if(mat[linha][coluna] == 2) mat[linha][coluna] = 20;

    if(mat[linha][coluna] == 3) mat[linha][coluna] = 30;
}

int calculaPontuacao(int mat[10][10], int linha, int coluna)
{
    int i, j, cont = 1;
    int c = 0,b = 0,e = 0,d = 0;

        if(mat[linha][coluna] == 10)
        {
            mat[linha][coluna] = 50;
            return 2;
        }

        else if(mat[linha][coluna] == 20)
        {
            if(mat[linha + 1][coluna] == 20) b = 1;
            if(mat[linha - 1][coluna] == 20) c = 1;
            if(mat[linha][coluna + 1] == 20) d = 1;
            if(mat[linha][coluna - 1] == 20) e = 1;

                if(b == 1)
                {
                    if(mat[linha + 1][coluna] == 20)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha + 1][coluna] = 50;
                        return 4;
                    }
                    else return 0;
                }

                if(c == 1)
                {
                    if(mat[linha - 1][coluna] == 20)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha - 1][coluna] = 50;
                        return 4;
                    }
                    else return 0;
                }

                if(d == 1)
                {
                    if(mat[linha][coluna + 1] == 20)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha][coluna + 1] = 50;
                        return 4;
                    }
                    else return 0;
                }

                if(e == 1)
                {
                    if(mat[linha][coluna - 1] == 20)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha][coluna - 1] = 50;
                        return 4;
                    }
                    else return 0;
                }
        }

        else if(mat[linha][coluna] == 30)
        {
            if(mat[linha + 1][coluna] == 30) b = 1;
            if(mat[linha - 1][coluna] == 30) c = 1;
            if(mat[linha][coluna + 1] == 30) d = 1;
            if(mat[linha][coluna - 1] == 30) e = 1;

                //meio V
                if(b == 1 && c == 1)
                {
                    if(mat[linha + 1][coluna] == 30 && mat[linha - 1][coluna] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha + 1][coluna] = 50;
                        mat[linha - 1][coluna] = 50;
                        return 7;
                    }
                    else return 0;
                }
                //meio H
                else if(d == 1 && e == 1)
                {
                    if(mat[linha][coluna + 1] == 30 && mat[linha][coluna - 1] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha][coluna - 1] = 50;
                        mat[linha][coluna + 1] = 50;
                        return 7;
                    }
                    else return 0;
                }
                //direita H
                else if(d == 1)
                {
                    if(mat[linha][coluna + 1] == 30 && mat[linha][coluna + 2] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha][coluna + 1] = 50;
                        mat[linha][coluna + 2] = 50;
                        return 7;
                    }
                    else return 0;
                }
                //esquerda H
                else if(e == 1)
                {
                    if(mat[linha][coluna - 1] == 30 && mat[linha][coluna - 2] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha][coluna - 1] = 50;
                        mat[linha][coluna - 2] = 50;
                        return 7;
                    }
                    else return 0;
                }
                //cima V
                else if(c == 1)
                {
                    if(mat[linha - 1][coluna] == 30 && mat[linha - 2][coluna] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha - 1][coluna] = 50;
                        mat[linha - 2][coluna] = 50;
                        return 7;
                    }
                    else return 0;
                }
                //baixo V
                else if(b == 1)
                {
                    if(mat[linha + 1][coluna] == 30 && mat[linha + 2][coluna] == 30)
                    {
                        mat[linha][coluna] = 50;
                        mat[linha + 1][coluna] = 50;
                        mat[linha + 2][coluna] = 50;
                        return 7;
                    }
                    else return 0;
                }
        }
        return 0;
    }
