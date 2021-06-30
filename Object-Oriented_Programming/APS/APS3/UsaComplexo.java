public class UsaComplexo
{
	public static void main(String[] args)
	{
		Complexo A = new Complexo();
		Complexo B = new Complexo(10,15);

		A.imprimeNumero();
		B.imprimeNumero();
	
		System.out.println(A.eIgual(B));
		
		A.inicializaNumero(10,15);
		System.out.println(A.eIgual(B));

		A.Soma(B);
		B.Subtrai(A);
	}
}
