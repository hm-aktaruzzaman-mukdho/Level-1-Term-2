package udp;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class DatagramServer implements Runnable {

    DatagramServer() {
        new Thread(this).start();
    }

    public void run() {
        int i=0;
        while (true) {
            try {
                send(i);
                i++;
            } catch (Exception e) {
                System.out.println(e);
            }
        }
    }

    public void send(int i) throws Exception {
        String data = "This is a datagram packet"+i;
        DatagramPacket packet = new DatagramPacket(data.getBytes(), data.length());
        InetAddress add = InetAddress.getByName("127.0.0.1");
        packet.setAddress(add);
        packet.setPort(8000);
        DatagramSocket socket = new DatagramSocket();
        socket.send(packet);
        socket.close();
    }

    public static void main(String[] args) {
        new DatagramServer();
    }
}
