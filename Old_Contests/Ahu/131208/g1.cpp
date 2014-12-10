#include <stdio.h>
#include <string.h>

int r, c;
char cake[20][20];
int main()
{
    int i, j;
    memset(cake, 'S', sizeof(cake));
    scanf("%d%d", &r, &c);
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++)
            scanf(" %c", &cake[i][j]);
    int sum = 0;
    int tmp = 0;
    for (i = 1; i <= r; i ++)
    {
        for (j = 1; j <= c; j ++)
            if (cake[i][j] == 'S')
                break;
            if( j == c + 1)
            {
                sum += c;
                tmp++;
            }
    }
    for (i = 1; i <= c;i++)
    {
        for (j = 1; j <= r; j++)
            if (cake[j][i] == 'S')
                break;
            if (j == r + 1)
                sum += r - tmp;
    }
    printf("%d\n",sum);
    return 0;
}
