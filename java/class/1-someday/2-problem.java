// Create a program that sees math class method and perform complex mathematical operations

import java.math.*;
import java.util.Scanner;

class problem {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.print("Enter a number: ");
		double num = scan.nextDouble();

		math(num);
	}

	public static void math(Double num) {
		double sqrt = Math.sqrt(num);
		System.out.println("The square of " + num + ": " + sqrt);

		double sin = Math.sin(num);
		System.out.println("The sin of " + num + ": " + sin);

		double cos = Math.cos(num);
		System.out.println("The cos of " + num + ": " + cos);

		double log = Math.log(num);
		System.out.println("The log of " + num + ": " + log);

		double cbrt = Math.cbrt(num);
		System.out.println("The cbrt of " + num + ": " + cbrt);

		double abs = Math.abs(num);
		System.out.println("The abs of " + num + ": " + abs);
	}
}
