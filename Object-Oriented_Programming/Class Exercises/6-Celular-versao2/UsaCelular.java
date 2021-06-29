public class UsaCelular{

	public static void main(String[] arg){
		System.out.println(Celular.getTotal()); // o que sera' impresso?
		Celular c = new Celular(123);
		Celular d = new Celular(456);
		System.out.println(Celular.getTotal()); // o que sera' impresso?
		System.out.println(d.getSerial()); // o que sera' impresso?
	}
}