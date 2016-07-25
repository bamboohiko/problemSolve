import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int a[] = new int[110]; 
		BigInteger f[][] = new BigInteger[110][110];
		int n,len;
		while (cin.hasNext()) {
				n = cin.nextInt();len = cin.nextInt();
		        for (int i = 1;i <= n; i++)
		            a[i] = cin.nextInt();
		        a[0] = -1;a[n+1] = (int) (1e9 + 7);
		        for (int i = 0;i <= n+1; i++)
		        	for (int j = 0;j <= n+1; j++)
		        		f[i][j] = BigInteger.valueOf(0);
		        f[0][0] = BigInteger.valueOf(1);
		        for (int i = 1;i <= n+1; i++)
		            for (int j = 1;j <= i && j <= len+1; j++) {
		                for (int k = 0;k < i; k++)
		                    if (a[k] < a[i]) f[i][j] = f[i][j].add(f[k][j-1]);
		            }
		        System.out.println(f[n+1][len+1]);
		    
		}
	}

}
