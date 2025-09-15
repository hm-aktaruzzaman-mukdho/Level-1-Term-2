package threads;

class NewThread1 implements Runnable {
    Thread t;
    int n;
    String name;

    NewThread1(int n,String name) {
        this.n=n;
        this.name=name;
        t = new Thread(this);
        t.start();
    }

    // This is the entry point for the thread.
    @Override
    public void run() {
        try {
            for (int i = n; i > 0; i--) {
                System.out.println("Child Thread "+name+": " + i);
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread. "+name);
    }
}

public class ImplementsThread {
    public static void main(String[] args) throws Exception {
        var t1=new NewThread1(100,"Child 1");
        var t2=new NewThread1(150,"Chile 2");
        t1.t.join();
        t2.t.join();
        
        for (int i = 500; i > 0; i--) {
            System.out.println("Main Thread: " + i);
            Thread.sleep(10);
        }
    }
}
