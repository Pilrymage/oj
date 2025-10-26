import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Wizard_of_Odds {
    static final BigInteger ZERO = BigInteger.ZERO;
    static final BigInteger ONE = BigInteger.ONE;
    static final BigInteger TEN = BigInteger.TEN;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                // use BufferedReader
                new InputStreamReader(System.in));
        // PrintWriter pw = new PrintWriter(
                // and PrintWriter
                // new BufferedWriter(new OutputStreamWriter(System.out))); // = fast IO
        // int caseNo = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        BigInteger N = new BigInteger(st.nextToken()).subtract(ONE);
        // N bills
        BigInteger K = new BigInteger(st.nextToken());
        // F friends
        
        int B = N.bitLength();

        System.err.printf("%s %s %d", N.toString(), K.toString(), B);
        if(K.compareTo(BigInteger.valueOf(B)) >= 0) {
            System.out.println("Your wish is granted!");
        } else {
            System.out.println("You will become a flying monkey!");
        }

    }
}