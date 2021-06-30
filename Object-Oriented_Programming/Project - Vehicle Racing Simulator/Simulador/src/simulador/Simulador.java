package simulador;

import java.lang.System;
import java.util.Scanner;

/**
 ** @authors WELLITON LEAL, RAFAEL DALMOLIN & WESLEY ALMEIDA 
 **/

public class Simulador {
    
    private Veiculo veiculos[] = new Veiculo[20];
    public int size;
    String ID;

    public Simulador() {
        this.size = 0;
    }
    
    public void incluirVeiculo(String Tipo)
    {
        if(this.size < 20){
            
            if(Tipo.equals("B"))
            {
                ID = "B"+(size+1);
                veiculos[this.size] = new Bicicleta(ID, 2);
		this.size++;
            }
              
            else if (Tipo.equals("M"))
            {
                ID = "M"+(size+1);
                veiculos[this.size] = new Motocicleta(ID, 2);
                this.size++;
            }
            else if (Tipo.equals("C"))
            {
                ID = "C"+(size+1);
                veiculos[this.size] = new CarroPopular(ID, 4);
                this.size++;    
            }
            else if(Tipo.equals("F"))
            {
                ID = "F"+(size+1);
                veiculos[this.size] = new Ferrari(ID, 4);
                this.size++;   
            }  
            System.out.println("O Veiculo " +ID+ " Foi Adicionado.");
        }
        else
        {
            System.out.println("** Falha ao Inserir Novo Veículo.");
            System.out.println("O Número Máximo de Veiculos Ja Foi Atingido");
        }		
    }
    
    public int buscaVeiculo(String ID)
    {
        for(int i = 0; i < this.size; i++)
        {
             if(this.veiculos[i].getId().equals(ID))
             {
                 return(i);
             }
        }
        return(-1);
    }
    
    public void removerVeiculo(String ID)
    {
        int x = buscaVeiculo(ID);
        
        if(x != -1)
        {
            this.veiculos[x] = null;
            for(int i= x; i<(this.size-1); i++)
            {
		this.veiculos[i] = this.veiculos[i+1];
            }
            this.size--;
            System.out.println("O Veículo "+ ID +" Foi Removido.");
        }
        else
        {
            System.out.println("** Esse Veículo Não Existe.");
        }  
    }
    
    public void abastecerVeiculo(int Pos, double L)
    {
        VeiculoMotorizado X = (VeiculoMotorizado)veiculos[Pos];
        X.abastecer(L);
        System.out.println("Foram Abastecidos "+ L +" Litros de Combustível no Veículo "+ veiculos[Pos].getId());
    }
    
    public void movimentar(int Pos)
    {
        veiculos[Pos].mover();  
    }
    
    public void movimentarPorTipo(String Tipo)
    {
        for(int i = 0; i < this.size; i++)
        {
            if(Tipo.charAt(0) == this.veiculos[i].getId().charAt(0))
            {
                veiculos[i].mover();
            }      
        }
        
    }
    
    public void imprimirPorTipo(String Tipo)
    {
        System.out.println("______________________[VEÍCULOS POR TIPO]__________________________");
        for(int i = 0; i < this.size; i++)
        {
            if(Tipo.charAt(0) == this.veiculos[i].getId().charAt(0))
            {
                System.out.println(veiculos[i].toString());
            }      
        }
        
    }
    public void imprimirPista()
    {
        System.out.println("_______________________[PISTA DE CORRIDA]__________________________");
        for(int i=0;i< this.size;i++)
        {
            veiculos[i].imprimirTrajetoria(); 
        }
       
    }
    
    public void imprimirLista(int n)
    {
        System.out.println("_______________________[LISTA DE VEÍCULOS]_________________________");
        if(n == 1)
        {
            for(int i = 0; i < this.size; i++)
            {
                System.out.println("-> " + veiculos[i].getId());
            }
        }
        else
        {
            for(int i = 0; i < this.size; i++)
            {
                if(this.veiculos[i] instanceof VeiculoMotorizado)
                {
                    System.out.println(veiculos[i].getId());
                }    
            }
        }
        
    }
    public void calibrar(int Pos)
    {
        veiculos[Pos].calibrar();
        System.out.println("Os Pneus do Veículo "+ veiculos[Pos].getId() +" Foram Calibrados.");
    }
    public void esvaziar(int Pos)
    {
        veiculos[Pos].esvaziar();
        System.out.println("Os Pneus do Veículo "+ veiculos[Pos].getId() +" Foram Esvaziados.");
    }
   
    public static void main(String[] args)
    {
        Simulador S = new Simulador();
        
        Scanner teclado =new Scanner(System.in);
	Scanner entrada =new Scanner(System.in);
        
	int i=0,x=0;
        char Opcao;
	String Tipo;
           
        do{  
                System.out.println("___________________________________________________________________");
                System.out.println("(a) Incluir Veiculo");
                System.out.println("(b) Remover Veiculo");
                System.out.println("(c) Abastecer Veiculo");
                System.out.println("(d) Movimentar Veiculo");
                System.out.println("(e) Movimentar Veiculos por Tipo");
                System.out.println("(f) Imprimir Dados de Veiculos por Tipo");
                System.out.println("(g) Imprimir Pista de Corrida");
                System.out.println("(h) Esvaziar Pneus de um Veiculo");
                System.out.println("(i) Calibrar Pneus de um Veiculo");
                System.out.println("(j) Sair da Aplicação");
                Opcao=teclado.nextLine().charAt(0);

                if(Opcao == 'a' || Opcao == 'A')
                {
                    System.out.println("Insira o Tipo do Veiculo (B/M/C/F): ");
                    Tipo = teclado.nextLine();
                    
                    if(Tipo.equals("B") || Tipo.equals("M") || Tipo.equals("C") || Tipo.equals("F"))
                    {
                        S.incluirVeiculo(Tipo);
                    }
                    else
                    {
                        System.out.println("** Veículo Informado Inválido.");
                    }
                    
                }	
                else if(Opcao == 'b' || Opcao == 'B')
                {
                    S.imprimirLista(1);
                    System.out.println("Insira o ID do Veículo a ser Removido: ");
                    Tipo = teclado.nextLine();
                    S.removerVeiculo(Tipo);
                }
                else if(Opcao == 'c' || Opcao == 'C')
                {
                    S.imprimirLista(0);
                    System.out.println("Insira o ID do Veículo a ser Abastecido: ");
                    Tipo = teclado.nextLine();
                    x = S.buscaVeiculo(Tipo);
                    if(x != -1)
                    {
                        System.out.println("Quantos litros deseja Abstecer: ");
                        S.abastecerVeiculo(x, entrada.nextDouble());
                    }
                    else
                    {
                        System.out.println("** Esse Veículo Não Existe.");
                    } 
                }
                else if(Opcao =='d' || Opcao == 'D')
                {
                    S.imprimirLista(1);
                    System.out.println("Insira o ID do Veículo a ser Movimentado: ");
                    Tipo = teclado.nextLine();
                    x = S.buscaVeiculo(Tipo);
                    if(x != -1)
                    {
                        S.movimentar(x);
                    }
                    else
                    {
                        System.out.println("** Esse Veículo Não Existe.");
                    }
                }
                else if(Opcao == 'e' || Opcao == 'E')
                {
                    System.out.println("Qual Tipo de Veículos deseja Movimentar (B/M/C/F): ");
                    Tipo = teclado.nextLine();
                    if(Tipo.equals("B") || Tipo.equals("M") || Tipo.equals("C") || Tipo.equals("F"))
                    {
                        S.movimentarPorTipo(Tipo);
                    }
                    else
                    {
                        System.out.println("** Veículo Informado Inválido.");
                    }
                }
                else if(Opcao == 'f' || Opcao == 'F')
                {
                    System.out.println("Qual Tipo de Veículos Deseja Imprimir os Dados(B/M/C/F): ");
                    Tipo = teclado.nextLine();
                    
                    if(Tipo.equals("B") || Tipo.equals("M") || Tipo.equals("C") || Tipo.equals("F"))
                    {
                         S.imprimirPorTipo(Tipo);
                    }
                    else{
                        System.out.println("** Veículo Informado Inválido.");
                    }
                }
                else if(Opcao == 'g' || Opcao == 'G')
                {
                    S.imprimirPista();		
                }
                else if(Opcao == 'h' || Opcao == 'H')
                {
                    S.imprimirLista(1);
                    System.out.println("Insira o ID do Veículo Que Deseja Esvaziar os Pneus: ");
                    Tipo = teclado.nextLine();
                    x = S.buscaVeiculo(Tipo);
                    if(x != -1)
                    {
                        S.esvaziar(x);
                    }
                    else
                    {
                        System.out.println("** Esse Veículo Não Existe.");
                    }
                }
                else if(Opcao == 'i' || Opcao == 'I')
                {
                    S.imprimirLista(1);
                    System.out.println("Insira o ID do Veículo Que Deseja Calibrar os Pneus: ");
                    Tipo = teclado.nextLine();
                    x = S.buscaVeiculo(Tipo);
                    if(x != -1)
                    {
                        S.calibrar(x);
                    }
                    else
                    {
                        System.out.println("** Esse Veículo Não Existe.");
                    }
                }		
                else
                {
                    if(Opcao != 'j' && Opcao != 'J')
                    {
                        System.out.println("** Opção Inválida, Tente novamente...");
                    }
                }
                
	}while(Opcao != 'j' && Opcao != 'J');
    }
}
