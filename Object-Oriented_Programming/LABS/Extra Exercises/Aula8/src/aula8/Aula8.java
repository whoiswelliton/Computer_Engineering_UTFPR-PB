package aula8;

public class Aula8 {

    public static void main(String[] args) {
         Pessoa[] p = new Pessoa[2];
         Livro[] l = new Livro[3];

         p[0] = new Pessoa("Pedro", 22, "M");
         p[1] = new Pessoa("Maria", 45, "F");
          
         l[0] = new Livro ("Java", "Guanabara", 300, p[0]);
         l[1] = new Livro ("C++", "Gustavo", 250, p[1]);
         l[2] = new Livro ("POO", "Welliton", 520, p[0]);
         
         l[0].abrir();
         l[0].folhear(200);
         l[0].avancarPag();
         System.out.println(l[0].detalhes());
         
          System.out.println(l[1].detalhes());
    }

}
