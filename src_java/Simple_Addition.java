import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Simple_Addition {
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

        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger N = new BigInteger(st.nextToken());
        // N bills
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        BigInteger F = new BigInteger(st2.nextToken());
        // F friends

        BigInteger sum = N.add(F);
        // built-in constant
        pw.println(sum);

        pw.close();
    }
}