import java.util.*;
import java.math.*;

class Matrix {
	public int n, m;
	public int[][] a;
	Matrix(int nn, int mm) {
		n = nn; m = mm;
		a = new int[n + 1][m + 1];
	}
	public void show() {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				System.out.print(a[i][j]);
				System.out.print(" ");
			}
			System.out.println("");
		}
	}
};

public class Main {

	static Matrix Mul(Matrix a, Matrix b, int mod) {
		Matrix ret = new Matrix(a.n, b.m);
		for(int i = 1; i <= a.n; i++) {
			for(int j = 1; j <= b.m; j++) {
				for(int k = 1; k <= a.m; k++) {
					ret.a[i][j] = ret.a[i][j] + (a.a[i][k] * b.a[k][j]) % mod;
					ret.a[i][j] %= mod;
				}
			}
		}
		return ret;
	}

	static Matrix pow(Matrix mat, BigInteger N, int mod) {
		Matrix ret = new Matrix(mat.n, mat.m);
		for(int i = 1; i <= ret.n; i++) ret.a[i][i] = 1;
		while(N.equals(BigInteger.ZERO) == false) {
			if(N.remainder(BigInteger.valueOf(2)).equals(BigInteger.ONE)) {
				ret = Mul(ret, mat, mod);
			}
			mat = Mul(mat, mat, mod);
			N = N.divide(BigInteger.valueOf(2));
		}
		return ret;
	}
	
	static boolean test(int pa, int pb, int m) {
		for(int i = 1; i < m; i++) {
			int pa1 = (pa & (1 << i)), pa2 = (pa & (1 << (i - 1)));
			int pb1 = ((pb & (1 << i))), pb2 = (pb & (1 << (i - 1)));
			if(pa1 + pa2 + pb1 + pb2 == 0) return false;
			if(pa1 != 0 && pa2 != 0 && pb1 != 0 && pb2 != 0) {
				return false;
			}
		}
		return true;
	}
	
	static void Gao(String n, int m, int p) {
		int msize = (1 << m);
		Matrix mat = new Matrix(msize, msize);
		for(int i = 0; i < msize; i++) {
			for(int j = 0; j < msize; j++) {
				if(test(i, j, m) == true) {
					mat.a[i + 1][j + 1] = 1;
				}
				else mat.a[i + 1][j + 1] = 0;
			}
		}
		BigInteger bn = new BigInteger(n);
		mat = pow(mat, bn.subtract(BigInteger.ONE), p);
		int ans = 0;
		//mat.show();
		for(int i = 1; i <= mat.n; i++) {
			for(int j = 1; j <= mat.n; j++) {
				ans = (ans + mat.a[i][j]) % p;
			}
		}
		System.out.println(ans);
	}
	
	public static void main(String[] args) {
		int m, p, T;
		String n;
		Scanner cin = new Scanner(System.in);
		T = cin.nextInt();
		for(int kase = 1; kase <= T; kase++) {
			if(kase > 1) System.out.println("");
			n = cin.next(); m = cin.nextInt(); p = cin.nextInt();
			Gao(n, m, p);
		}
	}

}
