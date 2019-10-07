#include <stdio.h>
#include<stdlib.h>
int findMissingElement(int *a,int *b,int asize,int bsize)
{
   int mnum = 0; 
  
    for (int i = 0; i < asize; i++) 
        mnum = mnum ^ a[i]; 
  
    for (int i = 0; i < bsize; i++) 
        mnum = mnum ^ b[i]; 
  
    return mnum;
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int asize,bsize;
    scanf("%d%d",&asize,&bsize);
    int *a=(int *)calloc(asize,sizeof(int));
    int *b=(int *)calloc(bsize,sizeof(int));
    for(int i=0;i<asize;i++)
    {
      scanf("%d",&a[i]);
    }
    for(int i=0;i<bsize;i++)
    {
      scanf("%d",&b[i]);
    }
    printf("%d\n",findMissingElement(a,b,asize,bsize));
  }
  return 0;
}