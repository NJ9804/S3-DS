#include <stdio.h>								
void main()						
{							
    int a[10][10], b[10][10], r1, r2, c1, c2, i, j, Triplet1[10][3], Triplet2[10][3], nz1 = 0, nz2 = 0, k, c[10][10];
    printf("Enter the rows and column of 1st sparse matrix\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter the array elements\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the rows and column of 2nd sparse matrix\n");
    scanf("%d%d", &r2, &c2);
    printf("Enter the array elements\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("The 1st sparse matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("The 2nd sparse matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", b[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (a[i][j] != 0)
            {
                nz1++;
                Triplet1[nz1][0] = i;
                Triplet1[nz1][1] = j;
                Triplet1[nz1][2] = a[i][j];
            }
        }
    }
    Triplet1[0][0] = r1;
    Triplet1[0][1] = c1;
    Triplet1[0][2] = nz1;

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            if (b[i][j] != 0)
            {
                nz2++;
                Triplet2[nz2][0] = i;
                Triplet2[nz2][1] = j;
                Triplet2[nz2][2] = b[i][j];
            }
        }
    }
    Triplet2[0][0] = r2;
    Triplet2[0][1] = c2;
    Triplet2[0][2] = nz2;
    printf("The triplet representation of 1st sparse matrix\n");
    for (i = 0; i <= nz1; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", Triplet1[i][j]);
        }
        printf("\n");
    }
    printf("The triplet representation of 2nd sparse matrix\n");
    for (i = 0; i <= nz2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", Triplet2[i][j]);
        }
        printf("\n");
    }

    if (Triplet1[0][0] != Triplet2[0][0] && Triplet1[0][1] != Triplet2[0][1])
    {
        printf("Addition not possible\n");
    }
    else
    {
        i = 1, j = 1, k = 0;
        while (i <= Triplet1[0][2] && j <= Triplet2[0][2])
        {

            if (Triplet1[i][0] < Triplet2[j][0])
            {
                k++;
                c[k][0] = Triplet1[i][0];
                c[k][1] = Triplet1[i][1];
                c[k][2] = Triplet1[i][2];
                i++;
            }
            else if (Triplet1[i][0] > Triplet2[j][0])
            {

                k++;
                c[k][0] = Triplet2[j][0];
                c[k][1] = Triplet2[j][1];
                c[k][2] = Triplet2[j][2];
                j++;
            }
            else if (Triplet1[i][0] == Triplet2[j][0])
            {
                if (Triplet1[i][1] < Triplet2[j][1])
                {
                    k++;
                    c[k][0] = Triplet1[i][0];
                    c[k][1] = Triplet1[i][1];
                    c[k][2] = Triplet1[i][2];
                    i++;
                }
                else if (Triplet1[i][1] > Triplet2[j][1])
                {
                    k++;
                    c[k][0] = Triplet2[j][0];
                    c[k][1] = Triplet2[j][1];
                    c[k][2] = Triplet2[j][2];
                    j++;
                }
                else if (Triplet1[i][1] == Triplet2[j][1])
                {
                    k++;
                    c[k][0] = Triplet1[i][0];
                    c[k][1] = Triplet1[i][1];
                    c[k][2] = Triplet1[i][2] + Triplet2[j][2];
                    i++, j++;
                }
            }
        }
        while (i <= Triplet1[0][2])
        {
            k++;
            c[k][0] = Triplet1[i][0];
            c[k][1] = Triplet1[i][1];
            c[k][2] = Triplet1[i][2];
            i++;
        }
        while (j <= Triplet2[0][2])
        {
            k++;
            c[k][0] = Triplet2[j][0];
            c[k][1] = Triplet2[j][1];
            c[k][2] = Triplet2[j][2];
            j++;
        }
        c[0][0] = Triplet1[0][0];
        c[0][1] = Triplet1[0][1];
        c[0][2] = k;
        printf("The sum of two matrix is: \n");
        for (i = 0; i <= k; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }