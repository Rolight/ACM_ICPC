import java.util.*; 
import java.math.*; 
import java.lang.reflect.Array;
import java.io.*; 

public class Main {
	public static void main(String args[]) {
		InputStream inputStream = System.in; 
		OutputStream outputStream = System.out;
		
		InputReader cin = new InputReader(inputStream); 
		PrintWriter cout = new PrintWriter(outputStream); 
		
		int t = cin.nextInt();
		int ti = 0; 
		while((t--) > 0) {
			if(ti != 0) cout.println("");
			ti ++; 
			// here is my code .
			String s = cin.next();
			BigInteger N = new BigInteger(s);
			BigInteger lala = N.divide(BigInteger.valueOf(2));
			while(lala.gcd(N).equals(BigInteger.ONE) == false) {
				lala = lala.subtract(BigInteger.ONE);
			}
			cout.println(lala.toString());
			
		}
		cout.close(); // close !!!
	}
}
class InputReader {  
    public BufferedReader reader;  
    public StringTokenizer tokenizer;  
    public InputReader(InputStream stream) {  
        reader = new BufferedReader(new InputStreamReader(stream));  
        tokenizer = null;  
    }  
    public String next() {  
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {  
            try {  
                tokenizer = new StringTokenizer(reader.readLine());  
            } catch (IOException e) {  
                throw new RuntimeException(e);  
            }  
        }  
        return tokenizer.nextToken();  
    }  
    public int nextInt() {  
        return Integer.parseInt(next());  
    }  
    public long nextLong() {  
        return Long.parseLong(next());  
    }  
    public double nextDouble() {  
        return Double.parseDouble(next());  
    }  
    public BigInteger nextBigInteger() {  
        return new BigInteger(next());  
    }  
}  