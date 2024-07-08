#include<stdio.h>
#include<math.h>
int main()
{
    int H,W;
    int i,j,k,l,a,b,c;

    scanf("%d%d",&H,&W);

    int X=W;
    for(i=1; i<=2*H; i++)
    {
        for(j=1; j<=X; j++)
        {
            printf("* ");

        }
        printf("\n");
        if(i<H+1 && i%2==0)
        {
            X+=W;
        }
        else if(i>=H+1 && i%2==0)
        {
            X-=W;
        }
    }

    return 0;
}

