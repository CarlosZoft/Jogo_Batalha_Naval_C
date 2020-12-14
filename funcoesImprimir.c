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
