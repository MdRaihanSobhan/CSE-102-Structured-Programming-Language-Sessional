#include<stdio.h>
#include<math.h>

int number_of_factors(int n)
{
    int ans = 1;

    for (int i=2; i*i <= n; i++)
    {
        if (n%i != 0)
            continue;
        int cnt = 0;
        while (n%i == 0)
        {
            n /= i;
            cnt++;
        }
        ans *= (cnt+1);
    }
    if (n > 1)
    {
        ans *= 2;
    }
    return ans;
}

int ones(int n)
{
    int ones=0;

    while(n)
    {
        int a= n%2;
        if(a==1)
            ones++;
        n/=2;
    }
    return ones;
}

int compare(int a, int b)
{
    if(ones(a)> ones(b))
    {
        return 1;
    }
    else if(ones(a)==ones(b))
    {
        if(number_of_factors(a)<number_of_factors(b))
        {
            return 1;
        }
        if(number_of_factors(a)==number_of_factors(b))
        {
            if(a>b)
                return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int ara[1000];

int main()
{
    int n,i,j;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(compare(ara[i],ara[j]))
            {
                int t= ara[i];
                ara[i]=ara[j];
                ara[j]=t;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        printf("%d ",ara[i]);
    }
    printf("\n");

}


