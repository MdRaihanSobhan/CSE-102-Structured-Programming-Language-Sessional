#include<stdio.h>
#include<math.h>

int main()
{


    int i,j,k,l,m;

    int x;
    scanf("%d",&x);

    int n= 2*x-1;
    m=n/2;
    j=0;
    for(i=0; i<=m; i++)
    {
        for(k=0; k<m-j; k++)
            printf(" ");

        for(k=m-j; k<=m+j; k++)
        {
            if(k==m+j || k== m-j)
                printf("*");
            else
                printf("_");
        }

        for(k=m+j+1; k<n; k++)
        {
            printf(" ");
        }

        j++;


        printf("\n");


    }

    k=1;
    for(i=m+1; i<n; i++)
    {

        for(j=0; j<k; j++)
        {
            printf(" ");
        }
        for(j=k; j<n-k; j++)
        {
            if(j==k || j==n-k-1 )
                printf("*");
            else
                printf("_");
        }
        for(j=n-k; j<n; j++)
        {
            printf(" ");
        }
        printf("\n");
        k++;


    }





}

