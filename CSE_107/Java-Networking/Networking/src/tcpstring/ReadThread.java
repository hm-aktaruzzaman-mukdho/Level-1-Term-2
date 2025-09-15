package tcpstring;

import util.SocketWrapper;

import java.io.IOException;

public class ReadThread implements Runnable {
    private Thread thr;
    private SocketWrapper socketWrapper;

    public ReadThread(SocketWrapper socketWrapper) {
        this.socketWrapper = socketWrapper;
        //Because of the below two line the thread is started automatically when created.
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            while (true)
            /*
             * Infinite Loop Continiously read datafrom the provided socket and prints it in the console.
             */
            {
                String s = (String) socketWrapper.read();
                System.out.println("Received: " + s);
            }
        } catch (Exception e) {
            System.out.println(e);
        } 
        finally 
        // If a exception happens during reading from the socketwrapper then the socket is closed.
        {
            try {
                socketWrapper.closeConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
