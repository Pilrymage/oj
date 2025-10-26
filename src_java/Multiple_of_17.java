import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Multiple_of_17 {
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
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            BigInteger N = new BigInteger(st.nextToken());
            // N bills
            // int F = Integer.parseInt(st.nextToken());
            // F friends
            if (N.compareTo(ZERO) == 0)
                break;
            
            pw.println(N.mod(BigInteger.valueOf(17)).compareTo(ZERO) == 0 ? 1 : 0);

            // divide to F friends
        }
        pw.close();
    }
}