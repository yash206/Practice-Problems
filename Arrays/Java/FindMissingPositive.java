import java.util.Scanner;

public class FindMissingPositive {
    static int firstMissingPositive(int[] nums) {
        int max = 0;
        int one = 0;

        for (int i : nums) {
            if (i > max & i < 2147483645) {
                max = i;
            }
            one = i == 1 ? 1 : one;
        }
        if (one == 0) {
            return 1;
        }

        int[] number = new int[max + 2];
        for (int i : nums) {
            if (i >= 0 & i < 2147483645) {
                number[i]++;
            }

        }
        for (int i = 1; i < number.length; i++) {
            if (number[i] == 0) {
                return i;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.println("Enter length of an Array ");
            int n = in.nextInt();
            int[] nums = new int[n];
            System.out.println("Enter elements of array: ");
            for (int i = 0; i < n; i++) {
                nums[i] = in.nextInt();
            }
            System.out.println("Positive integer missing is: " + firstMissingPositive(nums));
        }

    }
}
