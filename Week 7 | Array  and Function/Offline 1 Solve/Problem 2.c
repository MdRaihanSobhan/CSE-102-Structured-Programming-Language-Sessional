#include<stdio.h>
#include<math.h>
int isperfect(int n) // for checking the number if it is perfect
{
    int sum=1;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(n/i!=i)
                sum+=n/i;  // if equals then the same divisor would be counted twice
        }
    }
    if(sum==n) return 1;
    else return 0;
}
int main()
{
    int n, sum=0;
    scanf("%d",&n);

    for(int i=2;i<=n;i++)
    {
        if(isperfect(i)) sum+=i; // adding if the number is perfect
    }
    printf("%d\n",sum);

    return 0;
}

