#include<stdio.h>
#include<math.h>
int main() {
    int  h,k,r,x,y,e;

    scanf("%d%d%d%d%d",&h,&k,&r,&x,&y);

    e=(x-h)*(x-h)+(y-k)*(y-k)-r*r;

    if(e==0)
        printf("On the circle");
    else if (e>0)
        printf("Outside the circle");
    else
        printf("Inside the circle");

    return 0;







}





