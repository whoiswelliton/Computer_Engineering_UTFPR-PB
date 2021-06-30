public class UsaCelular{

	public static void main(String[] args){
		Celular a = new Celular();
		Celular b = new Celular();
		a.incrementar(); 
		b.incrementar();

		System.out.println(a.getTotal()); // o que sera' impresso?
		System.out.println(b.getTotal()); // o que sera' impresso?
	}

}