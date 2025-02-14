import java.util.Scanner;

public class idontknow {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int[] marks = new int[5];
		int total = 0;
		float avg;

		System.out.println("Enter marks for 5 subject: ");
		for (int i = 0; i < 5; i++) {
			System.out.print("Subject: " + (i + 1) + ": ");
			marks[i] = scan.nextInt();
			total += marks[i];
		}

		avg = (float) total / 5.0F;
		System.out.println("Total marks: " + total);
		System.out.println("Average marks: " + avg);

		if (avg >= 80) {
			System.out.println("Topper.");
		} else if (avg >= 60) {
			System.out.println("First Division.");
		} else if (avg >= 50) {
			System.out.println("Second division.");
		} else {
			System.out.println("Failed.");
		}

		scan.close();
	}
}
