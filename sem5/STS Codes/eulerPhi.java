
public class eulerPhi {
    public void phi(int num) {
        int result = num;

        for (int i = 2; i *i <= num; i ++) {
            if (num % i == 0) {
                while (num % i == 0) {
                    num /= i;
                }

                result -= (result / i);
            }

        }

        if (num > 1) {
            result -= (result / num);
        } 

        System.out.print("Euler phi is " + result);
    }
}
