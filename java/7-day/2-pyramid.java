import java.util.Scanner;

public class py {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter Row: ");
		int row = scan.nextInt();

		for (int i = 0; i <= row; i++) {
			for (int k = row; k > i; k--) {
				System.out.print(" ");
			}
			for (int j = 1; j <= (2*i-1); j++) {
				System.out.print("*");
			}
			System.out.println("");
		}
	}
}
