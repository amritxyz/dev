import java.util.Scanner;

public class check {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Enter a number: ");
		int number = scan.nextInt();

		if (number > 0) {
			System.out.println("The number " + number + " is positive.");
		} else if (number < 0) {
			System.out.println("The number " + number + " is negative.");
		} else {
			System.out.println("The number is zero.");
		}

		scan.close();
	}
}
