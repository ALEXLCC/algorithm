   #include <stdio.h>           
   #include <limits.h>         
   #include <stdlib.h>          
   #define   MAXSIZE   20      
   void  floyd(int [][MAXSIZE], int [][MAXSIZE], int);
   void  display_path(int [][MAXSIZE], int [][MAXSIZE], int);
   void  reverse(int [], int);
   void  readin(int [][MAXSIZE], int *);
   #define   MAXSUM(a, b)   (((a) != INT_MAX && (b) != INT_MAX) ? \
                          ((a) + (b)) : INT_MAX)
   void floyd(int dist[][MAXSIZE], int path[][MAXSIZE], int n)
   {
       int  i, j, k;
       for (i = 0; i < n; i++)
           for (j = 0; j < n; j++)
               path[i][j] = i;
       for (k = 0; k < n; k++)
           for (i = 0; i < n; i++)
               for (j = 0; j < n; j++)
                    if (dist[i][j] > MAXSUM(dist[i][k], dist[k][j]))
                    {
                         path[i][j] = path[k][j];
                         dist[i][j] = MAXSUM(dist[i][k], dist[k][j]);
                    }
   }
   void display_path(int dist[][MAXSIZE], int path[][MAXSIZE], int n)
   {
       int  *chain;
       int  count;
       int  i, j, k;
       printf("\n\nOrigin->Dest   Dist   Path");
       printf(  "\n-----------------------------");
       chain = (int *) malloc(sizeof(int)*n);
       for (i = 0; i < n; i++)
           for (j = 0; j < n; j++)
           {
               if (i != j)
               {
                    printf("\n%6d->%d    ", i+1, j+1);
                    if (dist[i][j] == INT_MAX)
                         printf("  NA    ");
                    else
                    {
                         printf("%4d    ", dist[i][j]);
                         count = 0; 
                         k = j;
                         do
                         {
                             k = chain[count++] = path[i][k];
                         } while (i != k);
                         reverse(chain, count);
                         printf("%d", chain[0]+1);
                         for (k = 1; k < count; k++)
                              printf("->%d", chain[k]+1);
                         printf("->%d", j+1);
                    }
               }
           }
       free(chain);           
   }
   #define SWAP(a, b)  { temp = a; a = b; b = temp; }
   void reverse(int x[], int n)
   {
       int  i, j, temp;
       for (i = 0, j = n-1; i < j; i++, j--)
            SWAP(x[i], x[j]);
   }
   void readin(int dist[][MAXSIZE], int *number)
   {
       int  origin, dest, length, n;
       int  i, j;
       char line[100];
       gets(line);            
       sscanf(line, "%d", &n);
       *number = n;
       for (i = 0; i < n; i++)
       {
           for (j = 0; j < n; j++)
                dist[i][j] = INT_MAX;
           dist[i][i] = 0;   
       }
       gets(line);            
       sscanf(line, "%d%d%d", &origin, &dest, &length);
       while (origin != 0 && dest != 0 && length != 0)
       {
          dist[origin-1][dest-1] = length;
          gets(line);       
          sscanf(line, "%d%d%d", &origin, &dest, &length);
       }
   }
    /// 测试程序如下所示：
   int main(void)
   {
       int dist[MAXSIZE][MAXSIZE];
       int path[MAXSIZE][MAXSIZE];
       int n;
       printf("\nInput the path information:");
       printf("\n----------------------------\n");
       readin(dist, &n);
       floyd(dist, path, n);
       display_path(dist, path, n);
       getchar();
   }
