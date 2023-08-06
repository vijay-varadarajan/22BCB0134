import java.util.*;

public class sort{
    public static void main(String[] args){
        int[] arr = {1, 8, 6, 4, 5};
        countingsort(arr, 5);
        System.out.println(Arrays.toString(arr));
    }

    public static void countingsort(int[] arr, int n){
        int max = arr[0];
        for(int i = 1; i < n; i++){
            max = Math.max(max, arr[i]);
        }
        System.out.println(max);
        int[] count = new int[max+1];
        for(int i = 0; i < n; i++){
            count[arr[i]]++;
        }
        for (int i = 0, j = 0; i < max+1; i++){
            int c = count[i];
            while(c-- != 0){
                arr[j++] = i;
            }
        }
    }

    public static void selectionsort(int[] arr){
        int n = arr.length; int min = 0;
        for(int i = 0; i < n; i++){
            min = arr[i];
            int k = i;
            for(int j = i; j < n; j++){
                if (arr[j] < min){
                    min = arr[j];
                    k = j;
                }
            }
            arr[k] = arr[i];
            arr[i] = min;
        }
    }

    public static void insertionsort(int[] arr){
        int n = arr.length;
        for(int i = 1; i < n; i++){
            int key = arr[i];
            int j = i - 1;
            while(arr[j] > key && j >= 0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    public static void bubblesort(int[] arr){
        int n = arr.length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                } 
            }
        }
    }
}