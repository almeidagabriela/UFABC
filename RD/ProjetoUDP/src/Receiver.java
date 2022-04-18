
public class Receiver {
	
	public static void main(String[] args) throws Exception {
		boolean running = true;

		Mensagem msg = new Mensagem(4445); // Intanciando classe para recebimento de mensagem
		
		while(running) {
			System.out.println("Esperando alguma mensagem");
			String received = msg.receive(); // Blocking: Aguardando o recebimento de alguma mensagem
			
			System.out.println("Mensagem do cliente: "+ received);
			
			if(received.equals("end")) {
				running = false;
				continue;
			}
		}
		
		msg.close();
	}
}
