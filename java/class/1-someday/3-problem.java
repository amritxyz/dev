
// Use random class to generate random numbers for a lottery program.
import java.util.Random;

class problem {
	public static void main(String[] args) {
		int lottery = 7;
		Random r = new Random();
		int num = (int) (10 * r.nextDouble());
		checkLottery(num, lottery);
	}

	public static int checkLottery(int num, int lottery) {
		if (num == lottery) {
			System.out.println("You have won the lottery. Congrats.");
		}
		return num;
	}
}
