public class ArrayDeFloats 
{
    private float[] array; 

    public ArrayDeFloats(int num)
    { 
        array = new float[num];
    } 
    public int Tamanho()
    { 
        return array.length;
    }
    public void Modifica(int pos,float valor)
    { 
        if ((pos >= 0) && (pos < array.length))
        {
              array[pos] = valor;
        }
    }
    public float Valor(int pos)
    { 
        if ((pos >= 0) && (pos < array.length))
        {
            return array[pos];
        }
        else
        {
            return Float.NaN;
        }
    }
    public float[] paraArray()
    { 
        return array;
    }
    public float menorValor()
    {  
       float menor = array[0];

       for(int i=1; i < array.length;i++)
       {
         if (array[i] < menor)
         {
             menor = array[i];
         }
       }
       return menor; 
    }

    public float maiorValor()
    { 
       float maior = array[0];
       
       for(int i=1; i < array.length;i++)
       {
           if (array[i] > maior)
           {
               maior = array[i];
           }
       }
       return maior;
    }

    @Override
    public String toString()
    {
      String res = "O array tem "+array.length+" elementos:\n";
      for(int i=0; i < array.length;i++)
      {
          res += array[i] + " ";
      }    
      return res;
    }

} 
