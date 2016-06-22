import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        BigInteger n, c, m;
        while (cin.hasNext()) {
            n = cin.nextBigInteger();
            c = cin.nextBigInteger();
            m = cin.nextBigInteger();
            System.out.println(c.modPow(n, m));
        }
    }
}
