#include<stdio.h>
#include<math.h>
#include<string.h>

int solve(char s1[], char s2[], int len1, int len2)
{

    if ((len1==0 && len2==0) || len2==0)
        return 1;   // base case , if you reach the beginning return 1
    if (len1==0)
        return 0;   // if you reach the beginning of the first string but not the second then second one doesn't occur

    if (s1[len1-1]==s2[len2- 1])  // checking if the last character matches
        return solve(s1, s2, len1 - 1, len2-1) + solve(s1, s2, len1-1, len2);  // if last character of both string matches
                            // then check again last char of first string for permutation
    else
        return solve(s1, s2, len1- 1,len2); // if last character of both string don't match then try without
                                        // the last char of first string
}

int main()
{
    char s1[30], s2[30];

    scanf("%s", s1);
    scanf("%s",s2);
    int len1, len2;
    len1= strlen(s1);
    len2= strlen(s2);

    int ans= solve(s1,s2,len1,len2);

    printf("%d\n",ans);


}
