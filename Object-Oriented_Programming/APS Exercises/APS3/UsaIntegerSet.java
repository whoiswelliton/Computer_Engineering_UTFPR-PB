public class UsaIntegerSet
{
	public static void main (String[] args)
	{
		IntegerSet A = new IntegerSet();
		IntegerSet B = new IntegerSet();
		//IntegerSet C = new IntegerSet();

		A.insertElement(10);
		A.insertElement(12);
		A.insertElement(55);
		
		IntegerSet C = A.union(B);
		IntegerSet D = A.intersection(B);

		System.out.println(C.toSetString());
		System.out.println(D.toSetString());
		
		System.out.println(A.toSetString());
		System.out.println(B.toSetString());
		

		System.out.println(A.isEqualTo(B));

		
	}
}
