#include<stdio.h>
int main()
{	int n,m,i,j,t,max,number;
int sum[1000],numb[1000]={0};
while(scanf("%d %d",&m,&n)!=EOF)

{	for (i=0;i<m;i++)
{scanf("%d",&numb[i]);
}
for(i=0;i<1000;i++)
sum[i]=0;
for(i=0;i<m;i++)
{	for(j=i;j<(i+n);j++)
{	if(j<m)
t=j;
else t=j-m;
sum[i]=sum[i]+numb[t];
}
}
max=sum[0];
for(i=1;i<m;i++)
max=(max>sum[i])?max:sum[i];
printf("%d",max);
}
return 0;
