import java.io.IOException;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.Scanner;

public class Sender {
	
	public static final int JANELA = 4;
	
	public static void main(String args[]) throws IOException, InterruptedException {
		ArrayList<String> listaEnvio = new ArrayList<String>(); // Lista dos pacotes que serão enviados
		Integer ackEspera = 0; // Pacotes esperando o ACK
		Integer ultimoPkt = 0; // Ultimo pacote enviado
		
		Scanner sc = new Scanner(System.in);
		Mensagem msg = new Mensagem(); // Intanciando classe para envio de mensagem
		
		InetAddress IPAddress = InetAddress.getByName("127.0.0.1"); //Endereço do servidor (no caso, simulamos com o endereço local)
		
		while(true) {
			while((ultimoPkt - ackEspera) < JANELA) {
				//Mensagem
				String info = sc.nextLine();
				
				//Opção de envio
				System.out.println("Digite uma opção de envio: lenta; perda; fora de ordem; duplicada; normal.");
				String status = sc.nextLine();
				
				// Implementando simulação de acordo com a opção escolhida pelo usuário
				if(status.equals("lenta")) {
					Thread.sleep(15000); // Envio com atraso de 15 segundos
				}else if(status.equals("perda")) {
					Thread.sleep(31000); // Perda do pacote
				}else if(status.equals("duplicada")) {
					msg.send(info, IPAddress, 4445); // Envio duplicado
				}
				
				listaEnvio.add(info);
				
				msg.send(info, IPAddress, 4445); // Enviando mensagem
				System.out.println("A mensagem foi enviada para o servidor");
				
				ultimoPkt++;
			}
			
			Integer ack = Integer.parseInt(msg.receive());
			
			// Caso o ack recebido for o mesmo que o ultimo que enviamos, paramos a execução do while
			if(ack == ultimoPkt) {
				break;
			}
			
			if(ack > ackEspera) {
				ackEspera = ack;
			}
		}
		
    }
}
