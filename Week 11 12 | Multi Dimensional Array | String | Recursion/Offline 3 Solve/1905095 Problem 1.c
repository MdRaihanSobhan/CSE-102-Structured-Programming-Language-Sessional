#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>


double det(int n, double mat[5][5])
{

    if(n == 1)
        return mat[0][0];

    double ans=0.0, mat2[n-1][5];

    for(int i=0; i<n; i++)
    {
        for(int row=1; row<n; row++)
            for(int col=0, ct = 0; col<n; col++)
                if(col!= i)
                    mat2[row-1][ct++] = mat[row][col];

        if(i&1)
            ans-=mat[0][i] * det(n-1,mat2);
        else
            ans+=mat[0][i] * det(n-1,mat2);
    }
    return ans;
}

void transpose(double A[5][5], int row, int col)
{
    for(int j=0; j<col; j++)
    {
        for(int i=0; i<row; i++)
        {
            if(ceil(A[i][j])!= A[i][j])
                printf("%10.3lf",A[i][j]);
            else
                printf("%10.0lf",A[i][j]);
        }
        printf("\n");
    }


}


void add (double mat1[5][5], double mat2[5][5], int n,int m, bool mode)
{
    double sum= 0.0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mode)
            {
                sum=mat1[i][j]-mat2[i][j];
            }
            else
            {
                sum=mat1[i][j]+mat2[i][j];
            }

            if(ceil(sum)!=sum)
            {
                printf("%10.3lf",sum);
            }
            else
            {
                printf("%10.0lf",sum);
            }
        }
        printf("\n");
    }
}

void multiply(double mat1[5][5], double mat2[5][5], int row1, int col1, int col2)
{


    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col2; j++)
        {
            double mul=0.0;
            for(int k=0; k<col1; k++)
            {
                mul+= mat1[i][k]* mat2[k][j];
            }
            if(ceil(mul)==mul)
            {
                printf("%10.0lf",mul);
            }
            else
            {
                printf("%10.3lf",mul);
            }
        }
        printf("\n");
    }

}

void divide(double mat[5][5], int row, int col, char m)
{
    double div=0.0;
    if(m=='0')
    {
        printf("Can't divide by 0\n");
        return;
    }
    int n= m-'0';
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            div=mat[i][j]/n;
            if(ceil(div)==div)
            {
                printf("%10.0lf",div);
            }
            else
            {
                printf("%10.3lf",div);
            }
        }
        printf("\n");
    }

}

char order[50];

int main()
{

    double A[5][5], B[5][5];
    int isA=0, isB=0;

    int rowA=0,rowB=0, colA=0, colB=0;
    int order_no=0;

    while(1)
    {
        char div='a';
        int a=0, b=0, mode=0;
        gets(order);
        strupr(order);
        printf("\n");
        int len= strlen(order);
        for(int i=0; i<len; i++)
        {
            if(order[i]=='E')
            {
                order_no=10;
                break;
            }
            else if(order[i]=='I')
            {
                for(int j=strlen(order)-1; j>=0; j--)
                {
                    if(order[j]=='A')
                    {
                        order_no=1;
                        a=1;
                        b=0;
                        break;
                    }
                    else if(order[j]=='B')
                    {
                        order_no=1;
                        b=1;
                        a=0;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                order_no=1;
                break;
            }
            else if(order[i]=='O')
            {
                for(int j=len-1; j>i; j--)
                {
                    if(order[j]=='A')
                    {
                        order_no=2;
                        a=1;
                        b=0;
                        break;
                    }
                    if(order[j]=='B')
                    {
                        order_no=2;
                        a=0;
                        b=1;
                        break;
                    }
                }
            }

            else if(order[i]=='A' || order[i]=='B')
            {
                if(order[i]=='A')
                    a=1, b=0;
                else if(order[i]=='B')
                    b=1,a=0;
                for(int j=i+1; j<len; j++)
                {
                    if(order[j]=='+')
                    {
                        order_no=3;
                        mode=0;
                        break;
                    }
                    if(order[j]=='-')
                    {
                        order_no=3;
                        mode=1;
                        break;
                    }
                    if(order[j]=='*')
                    {
                        order_no=4;
                        break;
                    }
                    if(order[j]=='/')
                    {
                        order_no=5;
                        div='a';
                        for(int k=j; k<len; k++)
                        {
                            if(order[k]>='0' && order[k]<='9')
                            {
                                div=order[k];
                                break;
                            }
                        }

                        if(div=='a')
                        {
                            printf("no value given for division\n");
                            order_no=0;
                            break;
                        }
                        else
                        {
                            order_no=5;
                            break;
                        }
                    }
                }
            }
            else if(order[i]=='D')
            {
                for(int j=len-1; j>i; j--)
                {
                    if(order[j]=='A')
                    {
                        a=1, b=0, order_no=6;
                        break;
                    }
                    else if(order[j]=='B')
                    {
                        b=1,a=0, order_no=6;
                        break;
                    }
                }
                break;

            }
            else if(order[i]=='T' && order_no!=6)
            {
                for(int j=len-1; j>i; j--)
                {
                    if(order[j]=='A')
                    {
                        a=1,b=0, order_no=7;
                        break;
                    }
                    else if(order[j]=='B')
                    {
                        a=0,b=1, order_no=7; break;
                    }
                }
                for(int j=len-1;j>i;j--)
                {
                    if(order[j]=='R')
                    {
                        order_no=8; break;
                    }
                }
                if(order_no!=8)
                {
                    order_no=2;
                }
            }
        }


        if(order_no==0)
            continue;
        else if(order_no==1)
        {
            if(a==1)
            {
                isA=1;
                scanf("%d%d",&rowA,&colA);
                for(int i=0; i<rowA; i++)
                {
                    for(int j=0; j<colA; j++)
                    {
                        scanf("%lf",&A[i][j]);
                    }
                }
            }
            else if(b==1)
            {
                isB=1;
                scanf("%d%d",&rowB,&colB);
                for(int i=0; i<rowB; i++)
                {
                    for(int j=0; j<colB; j++)
                    {
                        scanf("%lf",&B[i][j]);
                    }
                }
            }
        }
        else if(order_no==2)
        {
            if(a==1)
            {
                if(isA)
                {
                    for(int i=0; i<rowA; i++)
                    {
                        for(int j=0; j<colA; j++)
                        {
                            if(ceil(A[i][j])==A[i][j])
                            {
                                printf("%10.0lf",A[i][j]);
                            }
                            else
                            {
                                printf("%10.3lf",A[i][j]);
                            }
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("No Matrix A found\n");
                }
            }
            else if(b==1)
            {
                if(isB)
                {
                    for(int i=0; i<rowB; i++)
                    {
                        for(int j=0; j<colB; j++)
                        {
                            if(ceil(B[i][j])!=B[i][j])
                            {
                                printf("%10.0lf",B[i][j]);
                            }
                            else
                            {
                                printf("%10.3f",B[i][j]);
                            }
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("No Matrix B found\n");
                }
            }
        }

        else if(order_no==3)
        {
            if(isA==0 && isB==0)
            {
                printf("No Matrix A or B found\n");
            }
            else if(isA==0)
            {
                printf("No Matrix A found\n");
            }
            else if(isB==0)
            {
                printf("No Matrix B found\n");
            }
            else
            {
                if(rowA==rowB && colA==colB)
                {
                    if(a==1)
                    {
                        add(A,B,rowA,colA,mode);
                    }
                    else if(b==1)
                    {
                        add(B,A,rowB,colB, mode);
                    }
                }
                else
                {
                    if(mode==0)
                        printf("Addition not possible\n");
                    else
                        printf("Subtraction not possible\n");
                }
            }
        }
        else if(order_no==4)
        {
            if(isA==0 && isB==0)
            {
                printf("No Matrix A or B found\n");
            }
            else if(isA==0 && a==1)
            {
                printf("No Matrix A found\n");
            }
            else if(isB==0 && b==1)
            {
                printf("No Matrix B found\n");
            }
            else if(a==1)
            {
                if(colA==rowB)
                {
                    multiply(A,B,rowA,colA,colB);
                }
                else
                {
                    printf("Multiplication not possible\n");
                }
            }
            else if(b==1)
            {
                if(colB==rowA)
                {
                    multiply(B,A,rowB,colB,colA);
                }
                else
                {
                    printf("Multiplication not possible\n");
                }
            }
        }

        else if(order_no==5)
        {
            if(isA==0 && isB==0)
            {
                printf("No Matrix A or B found\n");
            }
            else if(isA==0  && a==1)
            {
                printf("No Matrix A found\n");
            }
            else if(isB==0 && b==1)
            {
                printf("No Matrix B found\n");
            }
            else if(a==1)
            {
                divide(A, rowA, colA, div);
            }
            else if(b==1)
            {
                divide(B, rowB, colB, div);
            }
        }

        else if(order_no==6 || order_no==9)
        {
            // printf("ekhane\n");
            if(a==1)
            {
                if(isA==1)
                {
                    if(rowA==colA)
                    {
                        double dd=det(rowA, A);
                        if(ceil(dd)==dd)
                        {
                            printf("%10.0lf\n",dd);
                        }
                        else
                        {
                            printf("%10.3lf\n",dd);
                        }
                    }
                    else
                    {
                        printf("A is Not a square matrix\n");
                    }
                }
                else
                {
                    printf("Matrix A not found\n");
                }
            }
            if(b==1)
            {
                if(isB==1)
                {
                    if(rowB==colB)
                    {
                        double dd=det(rowB, B);
                        if(ceil(dd)!=dd)
                        {
                            printf("%10lf\n",dd);
                        }
                        else
                        {
                            printf("%10.3lf\n",dd);
                        }
                    }
                    else
                    {
                        printf("B is Not a square matrix\n");
                    }
                }
                else
                    printf("Matrix B not found\n");
            }
        }
        else if(order_no==7)
        {
            if(a==1)
            {
                if(isA==0)
                {
                    printf("No Matrix A found\n");
                }
                else
                {
                    transpose(A,rowA,colA);
                }

            }
            else if(b==1)
            {
                if(isB==0)
                {
                    printf("No Matrix B found\n");
                }
                else
                {
                    transpose(B,rowB,colB);
                }
            }
        }
        else if(order_no==10)
        {
            int rr=0;
            for(int i=0;i<len;i++)
            {
                if(order[i]=='E')
                {
                    for(;i<len;i++)
                    {
                        if(order[i]=='X')
                        {
                           for(;i<len;i++)
                           {
                               if(order[i]=='I')
                               {
                                   for(;i<len;i++)
                                   {
                                       if(order[i]=='T')
                                       {
                                           rr=1;
                                       }
                                   }
                               }
                           }

                        }
                    }
                }
            }
            if(rr==1)
                break;
        }

    }

    return 0;
}


