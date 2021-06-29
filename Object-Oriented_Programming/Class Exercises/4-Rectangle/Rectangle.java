public class Rectangle {
    private int x, y;
    private int width, height;

    public Rectangle() {
        //this(0, 0, 1, 1);  //ok
		//this();  //erro   chamada recursiva
		//this(0,0); // ok   esta chamando o construtor de 2 parametros
		this(0);
    }
	public Rectangle(int width) {
        width=100;
    }
    public Rectangle(int width, int height) {
        this(0, 0, width, height);
    }
    public Rectangle(int x, int y, int width, int height) {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
    }
    //...
}
