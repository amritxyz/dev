import java.util.Scanner;

public class even {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter first number: ");
        int num_1 = scan.nextInt();
        System.out.print("Enter second number: ");
        int num_2 = scan.nextInt();
        System.out.print("Enter third number: ");
        int num_3 = scan.nextInt();

        if (num_1 > num_2 && num_1 > num_3) {
            System.out.println(num_1 + " is greater.");
        } else if (num_2 > num_1 && num_2 > num_3) {
            System.out.println(num_2 + " is greater.");
        } else {
            System.out.println(num_3 + " is greater.");
        }
        scan.close();
    }
}
