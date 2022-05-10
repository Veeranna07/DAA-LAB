
//Implement 0/1 Knapsack problem using Dynamic Programming.


#include<stdio.h>

void kpsk(int ,int ,int[],int[],int[][100]);

void opt(int,int,int[],int[][100]);

int max(int,int);


void main()

{

            int w[20],p[20],n,m,i,v[10][100];

            printf("Enter the no of elements\n");

            scanf("%d",&n);

            printf("Enter the capacity of knapsack\n");

            scanf("%d",&m);


            printf("Enter the weight of elements\n");

            for(i=1;i<=n;i++)

                        scanf("%d",&w[i]);


            printf("Enter the profit of elements\n");

            for(i=1;i<=n;i++)

            {

                        scanf("%d",&p[i]);

            }


            kpsk(n,m,w,p,v);

            opt(n,m,w,v);

}


void kpsk(int n,int m,int w[],int p[],int v[][100])

{

            int i,j;

            for(i=0;i<=n;i++)

            for(j=0;j<=m;j++)

            {

                        if(i==0 || j==0)

                        v[i][j]=0;

                        else if(j<w[i])

                                    v[i][j]=v[i-1][j];

                        else

                        v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);

            }

            for(i=0;i<=n;i++)

            {

                        for(j=0;j<=m;j++)

                        {

                                    printf("%d\t",v[i][j]);

                        }

                        printf("\n");

            }

}


void opt(int n,int m,int w[],int v[][100])

{

            int i,j,x[10];

            printf("The optimal solution is %d\n",v[n][m]);

            for(i=0;i<n;i++)

            x[i]=0;

            i=n;

            j=m;

            while((i!=0)&& (j!=0))

            {

                        if(v[i][j]!=v[i-1][j])

                        {

                                    x[i]=1;

                                    j=j-w[i];

                        }

                        i=i-1;

            }

            printf("The objects selected are \n");

            for(i=1;i<=n;i++)

            {

                        if(x[i]==1)

                                    printf("%d ",i);

            }

 }


 int max(int a, int b)

 {

            return(a>b? a:b);

 }


/*
OUTPUT :

enter the no of elements

4

enter the capacity of knapsack

5

enter the wt of elements

2 1 3 2

enter the profit of elements

12 10 20 15

0       0       0       0       0       0

0       0       12      12      12      12

0       10      12      22      22      22

0       10      12      22      30      32

0       10      15      25      30      37

The optimal solution is 37


The objects selected are 1 2 4


*/

//http://cs-in-engineering.blogspot.com/2016/03/lab-program-4-implement-01-knapsack.html?m=1
