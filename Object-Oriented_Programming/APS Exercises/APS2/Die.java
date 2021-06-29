import java.util.Random;

public class Die
{
	private int sideUp;

	public Die (int s)
	{
		sideUP = s;
	}
	public Die ()
	{
		sideUP = 0;
	}

	public int getSideUp() 
	{
		return sideUp;
	}
	public void roll()
	{
		sideUp = rand()%6;
	}
	
}

