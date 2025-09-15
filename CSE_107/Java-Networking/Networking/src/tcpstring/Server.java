package tcpstring;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import util.SocketWrapper;

public class Server {
    private ServerSocket serverSocket;

    Server() {
        try {
            serverSocket = new ServerSocket(33333);
            //Server choose the port number
            while (true)//Continiously accepts as many clients wants to connect.
            {
                Socket clientSocket = serverSocket.accept();
                serve(clientSocket);
            }
        } catch (Exception e) {
            System.out.println("Server starts:" + e);
        }
    }

    public void serve(Socket clientSocket) throws IOException {
        SocketWrapper socketWrapper = new SocketWrapper(clientSocket);
        //Creats a new socket wrapper object from client socket.Makes read write a ease.

        new ReadThread(socketWrapper);//New thread is created which will read data from the client socket and print it in the console.
        new WriteThread(socketWrapper, "Server");
        /*
         * For WriteThread a name is provided as who is writing the data.Here a new thread is created
         * that will scan a data from the console on the server side and send it to the client.Basically 
         * the data will be written on the client socket.And the client socket will read the data and print
         * it in console.
         */
    }

    public static void main(String args[]) {
        new Server();
    }
}
