#include<stdio.h>
#include<math.h>
int main()

{
    int a1,b1,c1,a2,b2,c2;

    float d,x,y;

    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);

    d=a1*b2-b1*a2;

    if(d==0)
        printf("Does not intersect");
    else
        printf("Intersection point : %.3f %.3f",(b1*c2-b2*c1)/d*1.0,(a2*c1-a1*c2)/d*1.0);

    return 0;




}
