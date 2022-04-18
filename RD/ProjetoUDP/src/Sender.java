import java.io.IOException;
import java.net.InetAddress;
import java.util.Scanner;

public class Sender {
	
	public static void main(String args[]) throws IOException {
		InetAddress IPAddress = InetAddress.getByName("localhost"); //Endereço do servidor (no caso, simulamos com o endereço local)
		Scanner sc = new Scanner(System.in);
		
		//Mensagem
		String info = sc.nextLine();
		
		Mensagem msg = new Mensagem(); // Intanciando classe para envio de mensagem
		msg.send(info, IPAddress, 4445); // Enviando mensagem
		System.out.println("A mensagem foi enviada para o servidor");
		
		msg.close();
    }
}
