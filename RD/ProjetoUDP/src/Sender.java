import java.io.IOException;
import java.net.InetAddress;
import java.util.Scanner;

public class Sender {
	
	public static void main(String args[]) throws IOException, InterruptedException {
		InetAddress IPAddress = InetAddress.getByName("127.0.0.1"); //Endere�o do servidor (no caso, simulamos com o endere�o local)
		Scanner sc = new Scanner(System.in);
		
		//Mensagem
		String info = sc.nextLine();
		
		//Op��o de envio
		System.out.println("Digite uma op��o de envio: lenta; perda; fora de ordem; duplicada; normal.");
		String status = sc.nextLine();
		
		Mensagem msg = new Mensagem(); // Intanciando classe para envio de mensagem
		
		// Implementando simula��o de acordo com a op��o escolhida pelo usu�rio
		if(status.equals("lenta")) {
			Thread.sleep(15000); // Envio com atraso de 15 segundos
		}else if(status.equals("perda")) {
			Thread.sleep(31000); // Perda do pacote
		}else if(status.equals("duplicada")) {
			msg.send(info, IPAddress, 4445); // Envio duplicado
		}
		
		msg.send(info, IPAddress, 4445); // Enviando mensagem
		System.out.println("A mensagem foi enviada para o servidor");
		
		msg.close();
    }
}
