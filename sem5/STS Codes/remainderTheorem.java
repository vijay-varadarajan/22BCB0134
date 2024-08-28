import java.util.*;

public class remainderTheorem {
    public void minRemain(int size, int num[], int rem[], int p) {
        int x = 0;

        for (int i = 0; i < size; i ++) {
            int M = p / num[i];
            int y = 0;
            for (int j = 0; j < num[i]; j ++) {
                if ((M * j) % num[i] == 1) {
                    y = j;
                    break;
                }
            }
            x += rem[i] * M * y;
        }

        System.out.printf("The minimum Number is : %d", (x % p));
    }
}
