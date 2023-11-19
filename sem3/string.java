import java.util.Scanner;

public class string {
    public static void main(String[] args){ 
        // program to check if string is a palindrome using StringBuffer and reverse method
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine();
        StringBuffer sb = new StringBuffer(str);
        sb.reverse();
        String rev = sb.toString();
        if(str.equals(rev)){
            System.out.println("String is a palindrome");
        }
        else{
            System.out.println("String is not a palindrome");
        }
        sc.close();
    }
}