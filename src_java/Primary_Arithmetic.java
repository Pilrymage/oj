import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Primary_Arithmetic {
    static final BigInteger ZERO = BigInteger.ZERO;
    static final BigInteger ONE = BigInteger.ONE;
    static final BigInteger TEN = BigInteger.TEN;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                // use BufferedReader
                new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(
                // and PrintWriter
                new BufferedWriter(new OutputStreamWriter(System.out))); // = fast IO
        // int caseNo = 0;
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            // N bills
            String b = st.nextToken();
            // F friends
            if (Integer.parseInt(a) == 0 && Integer.parseInt(b) == 0)
                break;
            boolean carry = false;
            int l1 = a.length();
            int l2 = b.length();
            int len = Math.max(l1, l2);
            a = new StringBuilder(a).reverse().toString();
            b = new StringBuilder(b).reverse().toString();

            int count = 0;
            for (int i = 0; i < len; i++) {
                int sum;
                if (i >= l1) {
                    sum = (b.charAt(i) - '0') + (carry ? 1 : 0);
                } else if (i >= l2) {
                    sum = (a.charAt(i) - '0') + (carry ? 1 : 0);
                } else {
                    sum = (a.charAt(i) - '0') + (b.charAt(i) - '0') + (carry ? 1 : 0);
                }
                
                count += sum / 10;
                carry = (sum / 10) != 0;
                System.err.print(carry);
                System.err.println(sum);
            }

            pw.print(count == 0 ? "No" : count);
            pw.print(" carry operation");
            pw.println(count >= 2 ? "s." : ".");
            // divide to F friends
        }
        pw.close();
    }
}