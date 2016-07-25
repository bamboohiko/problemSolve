#include<cstdio>
const int MAX=100010;
int a[MAX];
void sort(int l,int r)
{int i,j,mid,t;
 i=l;j=r;
 mid=a[(i+j)/2];
 while(i<j)
   {while(a[i]<mid) i++;
    while(a[j]>mid) j--;
    if (i<=j)
      {t=a[i];
      a[i]=a[j];
      a[j]=t;
      i++;j--;
      }
   }
    if (i<r) sort(i,r);
    if (j>l) sort(l,j);
}
int main()
{int n;
freopen("qsort.in","r",stdin);
freopen("qsort.out","w",stdout);
scanf("%d",&n);
for(int i=0;i<n;i++)
  scanf("%d",&a[i]);  
sort(0,n-1);
for(int i=0;i<n;i++)
  printf("%d ",a[i]);
return 0;
}
