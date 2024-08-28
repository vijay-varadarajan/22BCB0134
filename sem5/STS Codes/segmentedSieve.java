import java.util.*;

public class segmentedSieve {

    static int N = 1000;
    static boolean[] primesArr = new boolean[N + 1];

    static void simpleSieve() {
        Arrays.fill(primesArr, true);
        primesArr[0] = primesArr[1] = false;

        for (int i = 2; i * i <= N ; i ++) {
            if (primesArr[i] == true) {
                for (int j = i * i; j <= N; j += i) {
                    primesArr[j] = false;
                }
            }
        }
    }

    static ArrayList<Integer> generatePrimes(int n) {
        ArrayList<Integer> al = new ArrayList<>();

        for (int i = 2; i <= n; i ++) {
            if (primesArr[i]) {
                al.add(i);
            }
        }
        return al;
    }

    public void sSieve(int leftNum, int rightNum) {
        
        simpleSieve();
        ArrayList<Integer> al = generatePrimes((int) Math.sqrt(rightNum));

        boolean[] dummy = new boolean[rightNum - leftNum + 1];

        Arrays.fill(dummy, true);

        for (int prime : al) {
            int firstMuliple = (leftNum / prime) * prime;

            if (firstMuliple < leftNum) {
                firstMuliple += prime;
            }

            int start = Math.max(firstMuliple, prime * prime);

            for (int j = start; j <= rightNum; j += prime) {
                dummy[j - leftNum] = false;
            }
        }
        
        for (int i = leftNum ; i <= rightNum ; i ++) {
            if (dummy[i - leftNum] == true) {
                System.out.print(i + " ");
            }
        }
    }
}
