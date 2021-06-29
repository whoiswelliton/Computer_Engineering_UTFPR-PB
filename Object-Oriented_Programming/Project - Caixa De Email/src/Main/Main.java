package Main;

import java.util.Scanner;

/**
 * 
 * @author Erivelto S. Muller
 * @author Welliton Leal
 *
 */

public class Main {

	public static void main(String[] args) {
		// Esse programa devera possuir um vetor de e-mails que armazenara todos os
		// e-mails
		// criados. O tamanho deste vetor e 10.

		Email[] email = new Email[10];// vetor de emails, no tamanho maximo de 10

		int contadorEmails = 0;

		// Nao e necessario validar os usuarios. Qualquer usuario que fizer login podera
		// usar o
		// sistema, porem este usuario so podera visualizar os e-mails que forem
		// destinados a ele.

		// Criar um programa Java com menu em modo texto que permita ao usu´ario:

		Scanner teclado = new Scanner(System.in);
		int opcao = 0;
		String texto;

		do {
			System.out.println("1 - fazer Login--\n2 - Sair do Programa--");
			opcao = teclado.nextInt();
			if (opcao == 2) {
				opcao = 3;
			} else if (opcao == 1) {

				// 1 - Fazer login

				System.out.println("Digite seu Nome:");
				texto = teclado.next();
				Usuario usuario = new Usuario(texto); // Objeto de usuario

				// 1 - Escrever um e-mail
				// 2 - Listar os e-mails destinados a ele
				// 3 - Ler um e-mail
				// 4 - Gravar e-mails em arquivo
				// 5 - Ler e-mails do arquivo
				// 6 - Fazer logout
				// 2 - Sair do programa
				do {

					System.out.println(
							"4 - Escrever Email \n5 - Listar Emails \n6 - Gravar Emails em arquivo \n7 - Ler Email do arquivo \n8 - Fazer Logout \n9 - Sair do Programa");
					opcao = teclado.nextInt();
					if (opcao == 9) {
						opcao = 3;
					} else if (opcao == 8) {
						opcao = 1;
					} else if (opcao == 4) {
						if (contadorEmails < 10) {
							String[] emailconf = new String[4];

							System.out.println("Digite o Destinatário:");
							emailconf[1] = teclado.next();
							System.out.println("Digite o Assunto:");
							emailconf[2] = teclado.next();
							System.out.println("Digite o Mensagem:");
							emailconf[3] = teclado.next();
							emailconf[0] = usuario.getNome();

							email[contadorEmails] = new Email(emailconf[0], emailconf[1], emailconf[2], emailconf[3]);

							System.out.println(email[contadorEmails]);

							contadorEmails++;
							opcao = -1;
						} else {
							System.out.println("Numero maximo de emails alcançado.");
							opcao = 1;
						}
					} else if (opcao == 5) {
						System.out.println("Seus Emails:");
						int i;
						for (i = 0; i < contadorEmails; i++) {
							if (usuario.getNome().equals(email[i].getPara())) {
								System.out.println(email[i]);
							}
						}
						opcao = -1;
					} else if (opcao == 6) {
						System.out.println("Gravar emails em Arquivo");
						GravarArquivo gravar = new GravarArquivo();
						Email[] arquivar = new Email[10];
						int i;

						for (i = 0; i < contadorEmails; i++) {
							if (usuario.getNome().equals(email[i].getPara())) {
								arquivar[i] = email[i];
							}
						}
						gravar.gravarArquivo(usuario.getNome(), arquivar);
						opcao = -1;
					}

					else if (opcao == 7) {
						System.out.println("Seus Arquivos Gravados no disco serão listados abaixo: ");

						GravarArquivo ler = new GravarArquivo();

						ler.LerArquivo(usuario.getNome());
						opcao = -1;

					}
					else {
						System.out.println("Opcao Inválida!");
						opcao = -1;
					}
				} while (opcao == -1);

			} else {
				System.out.println("Opção inválida, escolha entre 1 ou 2.");
				opcao = -1;
			}

		} while (opcao != 3);

	}
}
