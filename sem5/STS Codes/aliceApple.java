public class aliceApple {
    public void appleCount(int M) {
        int ct = 0, sum = 0;

        while(sum < M) {
            ct += 1;
            sum += (12 * ct * ct);
        }

        System.out.printf("Perimeter : %d\n", (8 * ct));
    }
}
