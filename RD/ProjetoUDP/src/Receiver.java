
public class Receiver {
	
	public static void main(String[] args) throws Exception {

		Mensagem msg = new Mensagem(4445); // Intanciando classe para recebimento de mensagem
		
		while(true) {
			System.out.println("Esperando alguma mensagem");
			String received = msg.receive(); // Blocking: Aguardando o recebimento de alguma mensagem
			
			System.out.println("Mensagem do cliente: "+ received);
			
			Mensagem thread = new Mensagem();
			thread.start(); // Libera para a execução de demais recebimentos de mensagens, desbloqueando o processo.
		}
	}
}
