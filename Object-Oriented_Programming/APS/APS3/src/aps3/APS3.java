package aps3;
/**
 *
 * @author WELLITON LEAL (W)
 */
public class APS3 
{
    public static void main(String[] args)
    {
	Complexo A = new Complexo(0, 4);
	Complexo B = new Complexo(1,3.56);
        Complexo C = new Complexo(2,4.43);
                
        System.out.println("\nNumeros");
	A.ImprimeNumero();
	B.ImprimeNumero();
        C.ImprimeNumero();
	
        //verifica igualdade
        System.out.println("\nIgualdade");
        System.out.println( A.eIgual(B));
	System.out.println( A.eIgual(C));
        
        //soma
        System.out.println("\nSomas:");
        A.Soma(B);
        A.ImprimeNumero();
        B.Soma(C);
        B.ImprimeNumero();
        
        //subtrai
        System.out.println("\nSubtrações:");
	A.Subtrai(B);
	A.ImprimeNumero();
        B.Subtrai(C);
	B.ImprimeNumero();
        
        //multiplicação
        System.out.println("\nMultiplicações:");
        A.Multiplica(B);
        A.ImprimeNumero();
        
        //divide
        System.out.println("\nDivisão:");
	C.Divide(B);
	C.ImprimeNumero();
    }
}
