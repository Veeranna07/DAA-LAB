#include<stdio.h>
int d;
void sum(int,int,int[]);
void main()
{
            int n,w[100],i;
            printf("Enter the no of objects\n");
            scanf("%d",&n);

            printf("Enter the elements in increasing order\n");
            for(i=1;i<=n;i++)
                        scanf("%d",&w[i]);
            printf("Enter the maximum capacity\n");
            scanf("%d",&d);
            sum(n,d,w);
}


void sum(int n,int d,int w[])
{
            int x[100],s,k,i,found=0;
            for(i=1;i<=n;i++)
                        x[i]=0;
            s=0;
            k=1;
            x[k]=1;
            while(1)
            {
                        if(k <= n && x[k]==1)
                        {
                                    if(s+w[k] == d)
                                    {
                                    found=1;
                                                printf("The solution is\n");
                                                for(i=1;i<=n;i++)
                                                {
                                                            if(x[i]==1)
                                                            printf("%d\t",w[i]);
                                                }
                                                printf("\n");
                                                x[k]=0;
                                    }

                                    else if(s+w[k] < d)
                                                            s+=w[k];
                                    else
                                    {
                                                x[k]=0;
                                    }
                        }
                        else
                        {
                                    k--;
                                    while(k>0 && x[k]==0)
                                                 k--;

                                    if(k<=0)
                                    {

                                                break;

                                    }
                                    x[k]=0;
                                    s=s-w[k];
                        }
                        k=k+1;
                        x[k]=1;
  }
  if(!found)
  printf("no solution\n");
}

/*

OUTPUT
========
Enter the no of objects
5
Enter the elements in increasing order
1 2 3 4 5
Enter the maximum capacity
12
The solution is
1       2       4       5
The solution is
3       4       5


*/
