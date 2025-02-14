import java.util.Scanner;

public class prac {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.err.print("Enter a number: ");
        int num = scan.nextInt();

        if (prime(num)) {
            System.err.println("The number is prime.");
        } else {
            System.err.println("The number is not prime.");
        }
    }

    public static boolean prime(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
