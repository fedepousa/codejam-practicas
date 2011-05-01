import java.math.BigInteger;
import java.util.Vector;
import java.io.*;
import java.util.*;


class C{
	
	
	public static void main(String[] args) throws Exception{
		BigInteger combi[][] = new BigInteger[500][500];
		BigInteger uno = new BigInteger("1");
		BigInteger cero = new BigInteger("0");
		for(int i=0;i<500;++i){
			combi[i][0] = uno;
			combi[i][i] = uno;
		}
		
		for(int i=2;i<500;++i){
			for(int j=1;j<i;++j){
				BigInteger aux = cero;
				aux = aux.add(combi[i-1][j]);
				aux = aux.add(combi[i-1][j-1]);
				combi[i][j] = aux;
			}
		}
		
		/*
		for(int i=0;i<20;++i){
			for(int j=0;j<20;++j){
				System.out.print(combi[i][j]);
			}
			System.out.println();
		}*/
		
		
		
		
		FileInputStream fin = new FileInputStream("C-large2.in");
		FileOutputStream fout = new FileOutputStream("C-large2.out");
		PrintWriter out2 = new PrintWriter(fout);
		Scanner sc = new Scanner(fin);
		
		int t = sc.nextInt();
		for(int i=1;i<=t;++i){
			int n = sc.nextInt();
			BigInteger mat[][] = new BigInteger[n+1][n];
			for(int j=0;j<n;++j){
				mat[0][j] = cero;
				mat[1][j] = cero;
			}
			for(int j=0;j<n+1;++j){
				mat[j][0] = cero;
			}
			
			for(int j=2;j<n+1;++j){
				mat[j][1] = uno;
			}
			for(int j=2;j<n+1;++j){
				for(int h=j;h<n;++h){
					mat[j][h] = cero;
				}
			}
			
			for(int j=3;j<n+1;++j){
				for(int h=2;h<j;++h){
					BigInteger aux = cero;
					BigInteger aux2 = cero;
					int bla=0;
					for(int b=h-1;b >= 1 && bla<=(j-h-1);--b){
						aux2 = cero;
						aux2 = ((aux2.add(mat[h][b])).multiply(combi[j-h-1][bla]));
						aux = aux.add(aux2);
						bla++;
					}
					mat[j][h] = aux;			
				}
			}
			
			
			BigInteger res = cero;
			for(int j=0;j<n;++j){
				res = res.add(mat[n][j]);
			}
			BigInteger modu = new BigInteger("100003");
			res = res.mod(modu);
			out2.println("Case #" + i + ": " + res);
			
			System.in.read();	
		}
		out2.close();
		
	}
}
