public class IntegerSet
{
	private boolean[] vetor = new boolean[101];

	public IntegerSet()
	{
		for(int i=0; i<101;i++)
			vetor[i] = false;
	}
	public IntegerSet union(IntegerSet x)
	{
		IntegerSet result = new IntegerSet();

		for(int i=0; i<101;i++)
		{
			if(vetor[i]==true || x.vetor[i]==true)
			{
				result.insertElement(i);
			}
		}
		return result;
	}
	
	public IntegerSet intersection(IntegerSet x)
	{
		IntegerSet result = new IntegerSet();

		for(int i=0; i<101;i++)
		{
			if(vetor[i]==true && x.vetor[i]==true)
			{
				result.insertElement(i);
			}
		}
		return result;
	}
	
	public boolean isEqualTo(IntegerSet x)
	{
		boolean result = true;
		for(int i=0; i<101;i++)
		{
			if(vetor[i] != x.vetor[i])
			{
				result = false;
				return result;
			}
		}
		return result;
	}
		 
	public String toSetString()
	{
		String result ="";
		for(int i=0; i<101; i++)
		{
			result = result + i;
		}
		if(result.equals(""))
			return "- -";
		else		
			return result;
	}

	public void insertElement (int k) 
	{
		vetor[k] = true;
	}
	public void deleteElement (int k) 
	{
		vetor[k] = true;
	}
	
	
}
