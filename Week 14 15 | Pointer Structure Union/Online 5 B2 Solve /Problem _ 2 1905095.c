#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

struct _comp {

    double a;
    double b;
} comp;

void print(comp m)
{
    printf("0.2lf + %0.2lf i\n", m.a, m.b );
}

struct comp multiply(struct comp x, struct comp y)
{
    compl res;

    res.a = (x->a * ->x - a->y * b->y);
    res.b = (x->a * y->b + x->b * y->a);

    return res;
}

struct comp onubondhi (comp * x) {
    comp e;
    e.a = x->a;
    e.b = -x->b;

    return e;
}

struct comp divide (comp *x , comp* y) {
    comp ans;

    div.x = ans.x/divide;
    div.y = ans.y/divide;

    return ans;
}

int main()
{
    scanf("%lf", &comp.a);
    scanf("%lf", &comp.b);

    printf("%lf", comp.a);
    printf("%lf", comp.b);

}

