import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		BigDecimal zero = new BigDecimal("0");
		BigDecimal div = new BigDecimal("26");
		NumberFormat ff = NumberFormat.getInstance();
		while(cin.hasNext()) {
			String str = cin.nextLine();
			if(str.charAt(0) == '*') break;
			if(str.charAt(0) <= '9' && str.charAt(0) >= '0') {
				BigDecimal bign = new BigDecimal(str);
				int out[] = new int[1000],i = 0;
				while(bign.compareTo(zero) != 0) {
					out[i] = bign.remainder(div).intValue();
					if(out[i] == 0) bign = bign.add(new BigDecimal(-1));
					bign = bign.divideToIntegralValue(div);
					i++;
				}
				int len = 22 - i;
				for(i = i - 1;i >= 0;i--) {
					char ch = (char) (out[i] + 'a' - 1);
					if(out[i] == 0) ch = 'z';
					System.out.print(ch);
				}
				for(int j = 1;j <= len;j++) System.out.print(" ");
				System.out.println(ff.format(new BigDecimal(str)));
			} else {
				int len = str.length();
				System.out.print(str);
				for(int j = 1;j <= 22 - len;j++) System.out.print(" ");
				BigDecimal ans = new BigDecimal("0");
				for(int i = len - 1;i >= 0;i--) {
					int now = str.charAt(i) - 'a' + 1;
					BigDecimal tmp =div.pow(len - i - 1);
					tmp = tmp.multiply(new BigDecimal(now));
					ans = ans.add(tmp); 
				}
				System.out.println(ff.format(ans));
			}
		}
	}

}
