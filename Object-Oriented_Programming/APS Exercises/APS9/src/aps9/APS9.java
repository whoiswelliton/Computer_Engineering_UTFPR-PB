package aps9;

public class APS9 {

    public static void main(String[] args) {

        Pessoa[] p1 = new Pessoa[10];

        Aluno[] a = new Aluno[4];
        Professor[] p = new Professor[4];

        a[0] = new Aluno(0.75f, true, 6, "Computacao", "Joao", 209122);
        a[0].status2();
        a[0].cargaHoraria(30);

        a[1] = new Aluno(0.70f, true, 8, "Civil", "Luana", 204234);
        a[1].status2();
        a[1].cargaHoraria(35);

        a[2] = new Aluno(0.58f, false, 4, "Mecânica", "Rafael", 234956);
        a[2].status2();
        a[2].cargaHoraria(21);

        a[3] = new Aluno(0.53f, true, 5, "Contábeis", "Joao Vitor", 129345);
        a[3].status2();
        a[3].cargaHoraria(32);

        a[4] = new Aluno(0.81f, true, 4, "Eletrica", "José", 983452);
        a[4].status2();
        a[4].cargaHoraria(17);

        a[0] = new Aluno(0.46f, true, 6, "Computacao", "Xico", 223424);
        a[0].status2();
        a[0].cargaHoraria(30);

        p[0] = new Professor(3500.75f, 3, "DAINF", "Bruno", 902423);
        p[0].status2();
        p[0].cargaHoraria(40);

        p[1] = new Professor(5800.00f, 3, "DAINF", "Pablo", 34523);
        p[1].status2();
        p[1].cargaHoraria(46);

        p[2] = new Professor(7300.55f, 3, "DAELE", "Joana", 40985);
        p[2].status2();
        p[2].cargaHoraria(19);

        p[3] = new Professor(3730.77f, 3, "DAMAT", "Fredy", 456457);
        p[3].status2();
        p[3].cargaHoraria(34);

        p[4] = new Professor(7450.50f, 3, "DAFIS", "Cesar", 23443);
        p[4].status2();
        p[4].cargaHoraria(23);

    }

}
