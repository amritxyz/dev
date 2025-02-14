import java.util.Scanner;

public class logical {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter your age: ");
		int age = scan.nextInt();

		System.out.print("Enter yout grade percentage: ");
		double grade = scan.nextDouble();

		if (age >= 18 && age <= 25 && grade > 75) {
			System.out.println("You are eligible for the scholarship.");
		} else if (age >= 18 && age <= 25 && grade <= 75) {
			System.out.println("You are not eligible for the scholarship due to low grade.");
		} else if (age < 18 || age > 25) {
			System.out.println("You are not eligible for the scholarship due to age.");
		}
		scan.close();
	}
}
