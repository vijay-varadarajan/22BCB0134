
public class simpleSieve {
    public void Sieve(int num) {
        
        boolean[] primes = new boolean[num + 1];

        for (int i = 2; i <= num; i ++) {
            primes[i] = true;
        }

        for (int i = 2; i * i <= num; i ++) {
            if (primes[i] == true) {
                for (int j = i * i; j <= num; j += i) {
                    primes[j] = false;
                }
            }
            
        }
        
        for (int i = 2; i <= num; i ++) {
            if (primes[i] == true){
                System.out.print(i + " ");
            }
        }
    }
}
