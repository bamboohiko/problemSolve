#include<stdio.h> 
  int main() { 
       long long N,M,R,k; 
       while( scanf("%d%d", &N, &M) == 2 ) { 
        R = 0; 
          for(k = 0; k < N / 2; ++ k) 
                 R = (R + k) % (M + 1); 
           for( ; k < N; ++ k) 
               R = (R + k * k) % (M + 1); 
         printf("%d\n", R); 
      } 
      return 0; 
   } 
