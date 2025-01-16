public class args
{
	public static void main(String[] args)
	{
		if (args.length == 1)
			System.out.println("Hello, " + args[0]);
		else {
			System.err.println("Usage: <FILE_NAME> <Your_Name>");
			System.exit(1);
		}
		System.exit(0);
	}
}
