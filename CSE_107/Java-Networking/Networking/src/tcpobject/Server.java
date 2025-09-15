package tcpobject;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import util.SocketWrapper;

public class Server {

    private ServerSocket serverSocket;

    Server() {
        try {
            System.out.println("Server is started.");
            serverSocket = new ServerSocket(33333);
            while (true) {
                Socket clientSocket = serverSocket.accept();
                serve(clientSocket);
            }
        } catch (Exception e) {
            System.out.println("Server starts:" + e);
        }
    }

    public void serve(Socket clientSocket) throws IOException {
        SocketWrapper socketWrapper = new SocketWrapper(clientSocket);
        new ReadThread(socketWrapper);
        new WriteThread(socketWrapper, "Server");
    }

    public static void main(String args[]) {
        new Server();
    }
}
