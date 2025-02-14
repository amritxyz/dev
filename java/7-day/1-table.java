import java.util.Scanner;

public class idontknow {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.println("Enter a number: ");
		int num = scan.nextInt();
		int mul = 0;

		for (int i = 1; i <= num; i++) {
			mul = num * i;
			System.out.println(num + " * " + i + " = " + mul);
		}

		scan.close();
	}
}
