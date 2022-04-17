import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class Mensagem {
	private DatagramSocket socket;
	
	private byte[] buf = new byte[256];
	
	//Construtor sem especificar uma porta (casos em que o Sender instancia a classe mensagem)
	public Mensagem() throws SocketException {
		socket = new DatagramSocket();
	}
	
	//Construtor que recebe a porta como parametro (para casos em que o Receiver instancia a classe mensagem)
	public Mensagem(int port) throws SocketException {
		socket = new DatagramSocket(port);
	}
	
	//A mensagem precisa ser um JSON
	//Enviar mensagem
	public void send(String msg, InetAddress address, int port) throws IOException {
		buf = msg.getBytes(); // Conversão da mensagem (string ----- CORRIGIR PARA JSON) em um array de bytes
		
		// DatagramPacket utilizado para o envio de mensagens
		DatagramPacket packet = new DatagramPacket(buf, buf.length, address, port);
		socket.send(packet);
	}
	
	//Receber mensagem
	public String receive() throws IOException {
		// DatagramPacket convertido e utilizado para o recebimento de mensagens
		DatagramPacket packet = new DatagramPacket(buf, buf.length);
		socket.receive(packet);
		
		// Conversão do array de bytes em string ----- CORRIGIR PARA JSON
		String received = new String(
				packet.getData(),
				packet.getOffset(),
				packet.getLength());
		
		return received;
	}
	
	// Encerrando socket
	public void close() {
		socket.close();
	}
}
