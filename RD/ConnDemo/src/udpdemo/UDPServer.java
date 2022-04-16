package udpdemo;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPServer {

	public static void main(String[] args) {
		try {
			DatagramSocket serverSocket = new DatagramSocket(9876);
			
			while(true) {
				byte[] recBuffer = new byte[1024];
				DatagramPacket recPkt = new DatagramPacket(recBuffer, recBuffer.length);
				
				System.out.println("Esperando alguma mensagem");
				serverSocket.receive(recPkt); // BLOCKING
				
				byte[] sendBuf = new byte[1024];
				sendBuf = "sou o servidor".getBytes();
				
				InetAddress IPAdress = recPkt.getAddress();
				int port = recPkt.getPort();
				
				DatagramPacket sendPacket = 
						new DatagramPacket(sendBuf, sendBuf.length, IPAdress, port);
				
				serverSocket.send(sendPacket);
				System.out.println("mensagem enviada pelo server");
			}
		} catch (Exception e) {
			
		}

	}

}
