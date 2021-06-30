public class Celular{
  private static int total = 0;
  private int serial;

  public Celular(int s){
    this.serial = s;
    Celular.total = Celular.total + 1;
  }
  public static int getTotal(){
    return Celular.total;
  }
  public int getSerial(){
    return this.serial;
  }
}
