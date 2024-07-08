#include<stdio.h>
#include<math.h>

int main()
{
    double x,sum=0,fact=1 ;

    int i,j,k,m;
    m=100;
    scanf("%lf",&x);
    double pi=3.1416;
    x*=(pi/180);

    for(i=1,j=0; i<=m; i+=2,j++)
    {
        fact*=i;
        if((i-1)>0)
            fact*=(i-1);

        if(j%2==0)
            k=1;
        else
            k=-1;

        double mul= (k*(1/fact) * pow(x,i));

        sum+=mul;

    }
    printf("%lf\n",sum);

}

