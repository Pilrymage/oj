import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Very_Easy {
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
        String line;
        while ((line = br.readLine()) != null && line.length() > 0) {
            StringTokenizer st = new StringTokenizer(line);
            int N = Integer.parseInt(st.nextToken());
            // N bills
            BigInteger A = new BigInteger(st.nextToken());

            BigInteger sum = ZERO;
            BigInteger pow = ONE;
            // built-in constant
            for (int i = 1; i <= N; ++i) {
                // sum the N large bills
                pow = pow.multiply(A);
                sum = sum.add(BigInteger.valueOf(i).multiply(pow));
                // BigInteger addition
            }
            // pw.printf("Bill #%d costs ", ++caseNo);
            pw.println(sum.toString());
            // divide to F friends
        }
        pw.close();
    }
}