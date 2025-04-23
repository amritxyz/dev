
// Use random class to generate random numbers for a lottery program.
import java.util.Random;

class problem {
	public static void main(String[] args) {
		int lottery = 7;
		Random r = new Random();
		int num = (int) (10 * r.nextDouble());
		int what = checkLottery(num, lottery);
		System.out.println("The lottery number is " + lottery + " and you got " + what + ".");
	}

	public static int checkLottery(int num, int lottery) {
		if (num == lottery) {
			System.out.println("You have won the lottery. Congrats.");
			System.exit(1);
		}
		return num;
	}
}
