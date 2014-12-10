import java.io.*;
import java.util.Scanner;
import java.math.*;

public class main
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()) {
			int m;
			String sn;
			sn = cin.next();
			m = cin.nextInt();
			BigDecimal n = new BigDecimal(sn);
			String ans = n.pow(m).toPlainString();
			if(ans.charAt(0) != '0') System.out.print(ans.charAt(0)); 
			int len = ans.length();
			while(ans.charAt(len - 1) == '0') len--;
			if(ans.charAt(len - 1) == '.') len--;
			for(int i = 1;i < len;i++) System.out.print(ans.charAt(i));
			if(len == 1 && ans.charAt(0) == '0') System.out.print('0');
			System.out.print('\n');
		}
	}
}
