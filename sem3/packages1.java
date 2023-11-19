import pkg1.int_array;
import pkg2.int_sort;

import java.util.Arrays;
import java.util.Scanner;

public class packages1 implements int_array, int_sort {


    public int[] readArray() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the array: ");
        int size = scanner.nextInt();

        int[] arr = new int[size];

        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            arr[i] = scanner.nextInt();
        }

        scanner.close(); // Close the scanner

        return arr;
    }

    public void displayArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }

    public int[] mergeArrays(int[] arr1, int[] arr2) {
        int[] mergedArray = new int[arr1.length + arr2.length];
        int i = 0, j = 0, k = 0;

        while (i < arr1.length && j < arr2.length) {
            if (arr1[i] < arr2[j]) {
                mergedArray[k] = arr1[i];
                i++;
            } else {
                mergedArray[k] = arr2[j];
                j++;
            }
            k++;
        }

        while (i < arr1.length) {
            mergedArray[k] = arr1[i];
            i++;
            k++;
        }

        while (j < arr2.length) {
            mergedArray[k] = arr2[j];
            j++;
            k++;
        }

        Arrays.sort(mergedArray);

        return mergedArray;
    }

    public static void main(String[] args) {
        packages1 merger = new packages1();

        System.out.println("Enter elements for the first array:");
        int[] arr1 = merger.readArray(); // Input array 1

        System.out.println("Enter elements for the second array:");
        int[] arr2 = merger.readArray(); // Input array 2


        System.out.println("Array 1:");
        merger.displayArray(arr1); // Displaying array 1

        System.out.println("\nArray 2:");
        merger.displayArray(arr2); // Displaying array 2

        int[] merged = merger.mergeArrays(arr1, arr2);
        System.out.println("Merged Array:");
        merger.displayArray(merged); // Displaying the merged array
    }
}
