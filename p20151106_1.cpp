#include<stdio.h>
float A[1000],s[1000];
int main()
{
    printf("sdafsd");
    int n,m,i,j,a;
    float S;
    while((scanf("%d%d",&n,&m))==2)
    {
        for(i=0;i<n;i++)
            scanf("%f",&A[i]);
        for(i=0;i<n;i++)
        {
            j=i;
            s[i]=0;
            for(a=1;a<=m;a++)
            {
                if(j>=n)
                    j=j-n;
                s[i]=s[i]+A[j];
                j++;
            }
        }
        for(i=1,S=s[0];i<=n-1;i++)
            if(S<s[i])
                S=s[i];
        printf("%f",S);
    }
    printf("\n");
    return 0;
}

