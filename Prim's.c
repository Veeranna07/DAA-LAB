/*
Write the following program to implement algorithm to find the minimum cost spanning tree using Prim’s algorithm

--> Given a graph which consists of several edges connecting its nodes, find a subgraph of the given graph with the -->following properties:
    The subgraph contains all the nodes present in the original graph.
    The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
    It is also required that there is exactly one, exclusive path between any two nodes of the subgraph.
    One specific node  is fixed as the starting point of finding the subgraph using Prim's Algorithm.
    Find the total weight or the sum of all edges in the subgraph.

==> Input Format
====================
--> The first line has two space-separated integers  and , the number of nodes and edges in the graph.
--> Each of the next  lines contains three space-separated integers ,  and , the end nodes of , and the edge's weight
--> The last line has an integer , the starting node.

==>Sample Input 
======================

5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7
1

==> Sample Output 
=========================
15

=======================================================================================================================================================================
*/

// code:

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct edge{
int x, y, l;
};

int main(){
int n,e,i,j;
  scanf("%d%d",&n,&e);
  struct edge a[e],t;
  
  for(i=0;i<e;i++)
  {
    scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
    }
for(i=0;i<e-1;i++)
{
  for(j=i+1;j<e;j++)
  {
    if(a[i].l > a[j].l)
    {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      }
    }
  }

int sum=0,s,vn[3002]={0},vf,vi[n],vil,xz,yz;
scanf("%d",&s);
vi[0] = s;
vil = 1;
while(vil<n)
{
  for(i=0;i<e;i++)
  {
    xz = 0;
    yz = 0;
    if(vn[a[i].x] == 0 || vn[a[i].y] == 0)
    {
      for(j=0;j<vil;j++)
      {
        if(a[i].x == vi[j])
        {
          xz++;
          }

        if(a[i].y == vi[j])
        {
          yz++;
          }
        }

      if((xz==0 && yz!=0) || (yz==0 && xz!=0))
      {
        sum = sum + a[i].l;
        if(xz==0)
        {
          vi[vil] = a[i].x;
          vil++;
          vn[a[i].x]++;
          }
        else
        {
          vi[vil] = a[i].y;
          vil++;
          vn[a[i].y]++;
          }
        i = -1;
        }
      }
    }
  }

  printf("%d\n",sum);
  return 0;
}


//OUTPUT
//15

