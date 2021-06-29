public class DieDemo
{

	public static void main()
	{
		int res;

		Die Num1 = new Die(5);
		Die Num2 = new Die(2);
	
		res = Num1.getSideUP() + Num2.getSideUP();
		System.out.println(res);
	}
		
}
