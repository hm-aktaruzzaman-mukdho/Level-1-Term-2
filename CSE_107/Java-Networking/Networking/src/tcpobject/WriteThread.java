package tcpobject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import util.SocketWrapper;

public class WriteThread implements Runnable {

    private Thread thr;
    private SocketWrapper socketWrapper;
    String name;


    ArrayList<Data> datas=new ArrayList<>();

    public WriteThread(SocketWrapper socketWrapper, String name) {
        this.socketWrapper = socketWrapper;
        this.name = name;

        for(int i=0;i<=6;i++)
        {
            Data data1=new Data(i,"Hello");
            datas.add(data1);
        }
        
        this.thr = new Thread(this);
        thr.start();
    }

    public void run() {
        try {
            int i = 1;
            Scanner input = new Scanner(System.in);
            while (true) {
                System.out.println("Enter a message to send: ");
                String s = input.nextLine();
                Data d = new Data();
                d.setId(i);
                d.setValue(s);
                //socketWrapper.write(d);
                socketWrapper.write(datas);
                i++;
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
