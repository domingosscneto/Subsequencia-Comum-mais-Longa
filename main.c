//Domingos Soares do Carmo Neto - 32032889
//Thiago de Oliveira Aguirre - 32089589
//Eric Felipeli César Dias Pereira - 41911296

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>

// Função que analiza as strings e descobre a mais longa subsequência entre elas.
int LCS();

// É uma função que analiza a função LCS e printa a mais longa subsequência comum dentro das duas strings.
int Exebicao(int, int);

// Criação das variaves para o int LCS
int x, y, m, n;

// Criação das strings G e H com o maximo de 1000 caracteris. 
// O B e C são auxiliares para encontrar o LCS das strings.
char G[1000], H[1000], B[1000][1000], C[1000][1000];

int LCS()
{
    m = strlen(G);

    n = strlen(H);

    for (x = 0; x <= m; x++)
    {
        C[x][0] = 0;
    }

    for (x = 0; x <= n; x++)
    {
        C[0][x] = 0;
    }

    for (x = 1; x <= m; x++)
    {
        for (y = 1; y <= n; y++)
        {
            if (G[x - 1] == H[y - 1])
            {
                C[x][y] = C[x - 1][y - 1] + 1;

                B[x][y] = 'c';
            }

            else if (C[x - 1][y] >= C[x][y - 1])
            {
                C[x][y] = C[x - 1][y];

                B[x][y] = 'u';

            }

            else
            {
                C[x][y] = C[x][y - 1];

                B[x][y] = 'l';
            }
        }
    }

    return 0;
}


int Exebicao(int i, int j)

{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (B[i][j] == 'c')
    {
        Exebicao(i - 1, j - 1);

        printf("%c", G[i - 1]);

    }

    else if (B[i][j] == 'u')
    {
        Exebicao(i - 1, j);
    }

    else
    {
        Exebicao(i, j - 1);
    }

    return 0;
}

// Vai chamar as funções implementadas no codigo na tela do depurador.
void main()

{
    setlocale(LC_ALL, "Portuguese");
    printf("Digite a sequência de X:\n");

    scanf("%s", G);

    printf("Digite a sequência de Y:\n");

    scanf("%s", H);

    printf("LCS is : ");

    LCS();

    Exebicao(m, n);
}