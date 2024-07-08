#include<stdio.h>
#include<math.h>
#include<string.h>

char s1[501];
char s2[101];
char s3[11];

int main()
{

    gets(s1);
    gets(s2);
    gets(s3);
    int len2= strlen(s2);
    int len3= strlen(s3);

    int i,j,k;

    for(i=0;i<strlen(s1);i++)
    {
        // at first checking that is there any s2 in s1
        for(j=0,k=i; s1[k]==s2[j];)
        {
            j++, k++;
            if(j>=len2 || k>=strlen(s1)) break;
        }

        if(j==len2)  // if we get any s2 in s1
        {

            // at first I have to erase s2 from s1

            int a,len1= strlen(s1);
            for(a=0; a+i<len1; a++ )
            {
                s1[a+i]= s1[a+i+len2];
            }

            // then i have to make e blank space for s3

            for(int b=strlen(s1)+len3-1; b>=i+len3; b-- )
            {
                s1[b]=s1[b-len3];
            }

            // then i have to concatenate s3 into the erased space of s1

            for(int c = i; c<i+len3;c++)
            {
                s1[c]=s3[c-i];
            }


            i= i-len2+len3 ;
        }

    }
    printf("%s",s1);



    return 0;
}
