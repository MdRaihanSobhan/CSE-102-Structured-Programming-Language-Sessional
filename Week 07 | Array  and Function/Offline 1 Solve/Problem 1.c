#include<stdio.h>
#include<math.h>
int cnt[20001]; // inputs can be 20001 different numbers
int main()
{
    int n, a;
    scanf("%d",&n); // reading the number of inputs from user

    for(int i=0;i<n;i++)  // reading numbers one by one
    {
        scanf("%d",&a);
        a+=10000;  // adding 10000 to the numbers for easily indexing the negative numbers

        cnt[a]++;

        int maxi=-1; // for finding out the maximum index value

        for(int j=0;j<=20000;j++) // finding maximum index value of numbers
        {
            if(cnt[j]>maxi) maxi=cnt[j];
        }

        printf("Most frequent number = ");

        for(int j=0;j<=20000;j++)
        {
            if(cnt[j]==maxi)
            {
                int ans=j-10000;  // going back to the initial inputs

                printf("%d, ",ans); // printing the resulting numbers

            }
        }
        printf("\b \b\b \b"); // I won't print a comma or space at the end of each line

        printf("\n");

    }


}

