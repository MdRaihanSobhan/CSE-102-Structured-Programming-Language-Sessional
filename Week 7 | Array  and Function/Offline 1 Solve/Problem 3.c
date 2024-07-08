#include<stdio.h>
#include<math.h>
int ara[100];
int main()
{
    int n;
    scanf("%d",&n);

    int max=-1;


    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]>max) max=ara[i];
    }
    for(int i=1; i<=max; i++)
    {

        for(int j=0; j<n; j++)
        {
            int a=max-ara[j];

            if(i<=a) printf("   ");
            else printf("** ");
        }
        printf("\n");
    }

    return 0;
}
