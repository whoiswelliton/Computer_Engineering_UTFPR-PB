import java.util.*;

public abstract class Animal {

    public Animal() {
        private int peso;
        private int idade;
        private int membros;

        public Animal(int peso, int idade, int membros) {
        this.peso = peso;
        this.idade = idade;
        this.membros = membros;
        }
        
        public abstract void  locomover();
        public abstract void  alimentar();
        public abstract void  emitirSom();

        public int getPeso() {
            return peso;
        }

        public void setPeso(int peso) {
            this.peso = peso;
        }

        public int getIdade() {
            return idade;
        }

        public void setIdade(int idade) {
            this.idade = idade;
        }

        public int getMembros() {
            return membros;
        }

        public void setMembros(int membros) {
            this.membros = membros;
        }
    }


  
















    /**
     * 
     */
    public void locomover() {
        // TODO implement here
    }

    /**
     * 
     */
    public void alimentar() {
        // TODO implement here
    }

    /**
     * 
     */
    public void emitirSom() {
        // TODO implement here
    }

}