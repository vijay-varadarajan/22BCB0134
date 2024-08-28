import java.util.*;

public class main {
    public static void main(String[] args) {
        
        System.out.println("1. Simple Sieve");
        System.out.println("2. Segmented Sieve");
        System.out.println("3. Euler Phi");
        System.out.println("4. Strobogrammatic Number");
        System.out.println("5. Chinese Remainder Theorem");
        System.out.println("6. Toggle The Switch");
        System.out.println("7. Alice Apple Tree");
        System.out.println("Enter The Option : ");

        Scanner s = new Scanner(System.in);

        int ans = s.nextInt();

        switch (ans) {
            case 1:
                int sieveLimit;
                System.out.println("Enter The Limit For Simple Sieve : ");
                sieveLimit = s.nextInt();
                simpleSieve simpleSieveMain = new simpleSieve();
                simpleSieveMain.Sieve(sieveLimit);
                break;

            case 2:
                int sSieveLimit1, sSieveLimit2;
                System.out.println("Enter The Limit For Segemented Sieve : ");
                System.out.println("Enter The First Limit For Segemented Sieve : ");
                sSieveLimit1 = s.nextInt();
                System.out.println("Enter The Second Limit For Segemented Sieve : ");
                sSieveLimit2 = s.nextInt();
                segmentedSieve segmentedSieveMain = new segmentedSieve();
                segmentedSieveMain.sSieve(sSieveLimit1, sSieveLimit2);
                break;

            case 3:
                int phi;
                System.out.println("Enter The Limit For Euler Phi : ");
                phi = s.nextInt();
                eulerPhi eulerPhiMain = new eulerPhi();
                eulerPhiMain.phi(phi);
                break;

            case 4:
                String strobo;
                System.out.println("Enter The Limit For Strobogrammatic Number : ");
                s.nextLine();
                strobo = s.nextLine();
                stroboGrammatic stroboGrammaticMain = new stroboGrammatic();
                stroboGrammaticMain.stroboGramm(strobo);
                break;

            case 5:
                int remain, p = 1;
                System.out.println("Enter The No.of numbers In the List : ");
                s.nextLine();
                remain = s.nextInt();
                int[] num = new int[remain];
                int[] rem = new int[remain];

                System.out.print("Enter The Divisors List Numbers :");

                for (int j = 0; j < remain; j ++) {
                    System.out.print("Enter Number :");
                    s.nextLine();
                    num[j] = s.nextInt();
                    p *= num[j];
                } 

                System.out.print("Enter The Remainder List Numbers :");

                for (int j = 0; j < remain; j++) {
                    System.out.print("Enter Number :");
                    s.nextLine();
                    rem[j] = s.nextInt();
                }

                remainderTheorem remainderTheoremMain = new remainderTheorem();
                remainderTheoremMain.minRemain(remain, num, rem, p);
                break;

            case 6:
                int n;
                System.out.println("Enter No.of Doors : ");
                n = s.nextInt();
                toggleSwitch toggleSwitchMain = new toggleSwitch();
                toggleSwitchMain.toggleSwitchFunc(n);
                break;

            case 7:
                int i;
                System.out.println("ENter No.of apples required");
                i = s.nextInt();
                aliceApple aliceAppleMain = new aliceApple();
                aliceAppleMain.appleCount(i);
                break;
            default:
                break;
        }
    }
}
