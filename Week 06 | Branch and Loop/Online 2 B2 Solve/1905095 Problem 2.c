#include<stdio.h>
#include<math.h>

int main()
{
    int x,i,j,y=-1;
    while(1)
    {
        scanf("%d",&x);

        if(y==-1)
            y=x;

        int ans=x*y;

        int a=x, b=y;

        while(1)
        {
            if(b==0)
            {
                y=a;
                break;
            }
            else
            {
                int t=b;
                b=a%b;
                a=t;
            }
        }

        ans/=y;

        y=ans;

        printf("LCM of all numbers up to now is %d\n", ans);

        if(ans>10000)
            return 0;

    }



    return 0;
}
