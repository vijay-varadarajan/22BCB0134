import java.util.*;

public class stroboGrammatic {
    public boolean stroboGramm(String strob) {
        Map<Character, Character> stringMap = new HashMap<Character, Character>();

        stringMap.put('0', '0');
        stringMap.put('1', '1');
        stringMap.put('6', '9');
        stringMap.put('8', '8');
        stringMap.put('9', '6');

        int left = 0, right = strob.length() - 1;
        
        while(left <= right) {
            if (!stringMap.containsKey(strob.charAt(left)))  {
                System.out.print("Number is not strobogrammatic number.");
                return false;
            }

            if (stringMap.get(strob.charAt(left)) != strob.charAt(right)) {
                System.out.print("Number is not strobogrammatic number.");
                return false;
            }
            left ++;
            right --;
        }
        System.out.print ("Number is a strobogrammatic number.");
        return true;
    }
}
