import java.util.*;

public class toggleSwitch {
    public void toggleSwitchFunc(int n) {
        boolean[] doors = new boolean[n + 1];

        Arrays.fill(doors, false);

        int close = 0, open = 0;

        for (int i = 1; i <= n; i ++) {
            for (int j = i; j * i < n; j ++) {

                if (doors[j]) {
                    doors[j] = false;
                }

                else {
                    doors[j] = true;
                }
            }
        }

        for (int i = 1; i <= n; i ++) {

            if (doors[i]) {
                open += 1;
            }

            else {
                close += 1;
            }
        }

        System.out.printf("No.of closed doors: %d\nNo.of open doors: %d", close, open);
    }

}
