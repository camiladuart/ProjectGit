/* Pandemia:
    Escrever um programa para simular a contaminação de uma população aglomerada em um espaço retangular, 
    quando uma pessoa desta população é exposta ao vírus da Covid-19.
    O grau de resistência de cada pessoa é um valor de 0 a 5, onde 0 significa nenhuma resistência e 5 a maior 
    resistência possível. O poder de contágio do vírus é um valor entre 2 e 5. Se uma pessoa for exposta a um vírus da 
    Covid-19 com poder de contágio maior que a sua resistência ao vírus, ela é infectada, e também infectará todos os 
    seus vizinhos à esquerda, à direita, acima e abaixo que também tiverem resistência menor que o poder de contágio.
    Entrada:
    A primeira linha da entrada contém dois inteiros, M e N (4 ≤ M, N ≤ 100), representando a largura e o comprimento do 
    espaço em que as pessoas estão aglomeradas. Nas M linhas seguintes aparecem N números inteiros Ri (0 ≤ Ri ≤ 5, 
    para 1 ≤ i ≤ N), onde Ri é a resistência da i-ésima pessoa de cada linha. A última linha da entrada é composta por 
    3 inteiros, X (1 ≤ X ≤ M), Y (1 ≤ Y ≤ N) e C (2 ≤ C ≤ 5), representando, respectivamente, a linha e a coluna da
    posição da pessoa que foi exposta ao vírus da Covid-19 e o poder de contágio do vírus.
    Saída:
    Seu programa deve produzir uma única linha na saída indicando o número de pessoas que foram contaminadas por Covid-19.
*/
#include <stdio.h>

void covid(int, int, int [][*], int, int, int);

int main()
{
    int m, n, x, y, c, cont = 0;
    scanf("%d %d", &m, &n);
    int espaco[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &espaco[i][j]);
        }
    }
    scanf("%d %d %d", &x, &y, &c);
    covid(m, n, espaco, x - 1, y - 1, c);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (espaco[i][j] == -1) {
                cont++;
            }            
        }
    }
    printf("%d\n", cont);
    return 0;
}

void covid(int l, int c, int p[][c], int i, int j, int v)
{
    if (i >= 0 && i < l && j >= 0 && j < c && p[i][j] != -1 && p[i][j] < v) {
        p[i][j] = -1;
        covid(l, c, p, i + 1, j, v);
        covid(l, c, p, i - 1, j, v);            
        covid(l, c, p, i, j + 1, v);            
        covid(l, c, p, i, j - 1, v);            
    }
}