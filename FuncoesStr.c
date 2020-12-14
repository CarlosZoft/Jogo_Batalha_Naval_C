int strTamanho(char str[1000])
{
        int tam = 0;

            while(str[tam] != '\0')
            {
                tam++;
            }

        return tam;
    }

void strCopia(char str1[1000], char str2[1000])
{
            int tam = strTamanho(str2);
            int pos = 0;

        while(pos != tam)
        {
            str1[pos] = str2[pos];

            pos++;
        }
        str1[tam] = '\0';
}

void strConcatena(char str1[1000], char str2[1000])
{
        int tam1 = strTamanho(str1);
        int tam2 = strTamanho(str2);
        int pos = 0;

            while(pos != tam2)
            {
                str1[tam1] = str2[pos];
                pos++;
                tam1++;
            }
}

void strAdicionaChar(char str1[1000], char c)
{
        int tam = strTamanho(str1);

            str1[tam] = c;
            str1[tam+1] = '\0';
}

