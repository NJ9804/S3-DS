#include<stdio.h>
int i,j,r,c,a[10][10],Triplet[10][3],nz,q,Transpose[10][10];
void main()
{
    printf("Enter the rows and col of sparse matrix:\n");
    scanf("%d%d",&r,&c);
    printf("Enter the elements into sparse matrix\n");
     for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
                {
                    scanf("%d",&a[i][j]);
                }
        }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
               
            if(a[i][j]!=0)
            {
                 nz++;
                Triplet[nz][0]=i;
                Triplet[nz][1]=j;
                Triplet[nz][2]=a[i][j];
            }
        }
    }
    Triplet[0][0]=r;
    Triplet[0][1]=c;
    Triplet[0][2]=nz;
    printf("The triplet representation of sparse matrix :\n");
    for(i=0;i<=nz;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Triplet[i][j]);
        }
        printf("\n");
    }
      Transpose[0][1]= Triplet[0][0];
      Transpose[0][0]= Triplet[0][1];
      Transpose[0][2]= Triplet[0][2];
    printf("The transpose of given matrix is :\n");
    for(i=0,q=0;i<c;i++)
    {
        for(j=1;j<=nz;j++)
        {
            if(Triplet[j][1]==i)
            {
                q++;
                Transpose[q][0]=Triplet[j][1];
                Transpose[q][1]=Triplet[j][0];
                Transpose[q][2]=Triplet[j][2];
            }
        }
    }
    for(i=0;i<=nz;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",Transpose[i][j]);
        }
        printf("\n");
    }
}
