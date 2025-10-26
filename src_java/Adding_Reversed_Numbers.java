import java.io.*;
import java.util.*;
import java.math.BigInteger;

class Adding_Reversed_Numbers {
    public static String rev(String s) {
        
        return new StringBuilder(s).reverse().toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
                // use BufferedReader
                new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(
                // and PrintWriter
                new BufferedWriter(new OutputStreamWriter(System.out))); // = fast IO
        // int caseNo = 0;
        int TC = Integer.parseInt(br.readLine());
        for(int tc = 0; tc < TC; tc++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            BigInteger a = new BigInteger(rev(st.nextToken()));
            // N bills
            BigInteger b = new BigInteger(rev(st.nextToken()));
            
            BigInteger sum = a.add(b);
            
            pw.println(new BigInteger(rev(sum.toString())));
        }
        pw.close();
    }
}