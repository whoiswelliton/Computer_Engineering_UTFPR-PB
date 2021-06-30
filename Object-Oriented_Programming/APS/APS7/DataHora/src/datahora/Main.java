package datahora;

public class Main 
{
    public static void main(String[] args) 
    {
        DataHora D1 = new DataHora ((byte)23, (byte)59, (byte)30, (byte)31, (byte)12, (short)2018);
        DataHora D2 = new DataHora ((byte)31, (byte)12, (byte)2018);
        
        System.out.println(D1.equals(D2)); 
        System.out.println(D2.equals(D2));
        
        D1.toString();
        D2.toString();
    }
  
}
