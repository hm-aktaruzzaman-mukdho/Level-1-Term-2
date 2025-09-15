package tcpobject;

import util.SocketWrapper;

import java.io.IOException;
import java.util.ArrayList;

public class ReadThread implements Runnable {
    private Thread thr;
    private SocketWrapper socketWrapper;

    public ReadThread(SocketWrapper socketWrapper) {
        this.socketWrapper = socketWrapper;
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            while (true) {
                Object o = socketWrapper.read();//Reads the data as object.The code hangs here unless until there is data in the stream.
                if (o instanceof Data) {
                    Data obj = (Data) o;//Typecasted.
                    System.out.println("Received: " + obj.getId() + ", " + obj.getValue());
                }
                else
                {
                    for(Data d:(ArrayList<Data>)o)
                    {
                        System.out.println(d.getId()+" "+d.getValue());
                    }
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                socketWrapper.closeConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
