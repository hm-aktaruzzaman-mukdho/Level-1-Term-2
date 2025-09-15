package tcpstring;

import java.net.InetAddress;

import util.SocketWrapper;//My defined class

public class Client {

    public Client(String serverAddress, int serverPort) {
        try {
            SocketWrapper socketWrapper = new SocketWrapper(serverAddress, serverPort);
            /*
             * A new client socket is created each time the program is re run.
             * Socket wrapper is a user defined class.
             */
            new ReadThread(socketWrapper);
            new WriteThread(socketWrapper, "Client");

            //See Server.java as to how above two line works.
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String args[]) {
        try {
            String serverAddress = InetAddress.getLocalHost().getHostAddress();
            //LocalHost ip address is provided as the server address since
            // client and server running on the same machine.

            int serverPort = 33333;
            //The port number should be exactly the one that server opened.
            //In the server file used provided port 33333 to open a port on that.

            
            new Client(serverAddress, serverPort);
        } catch (Exception e) {
            System.out.println("Exception during getting server address.");
        }

    }
}
