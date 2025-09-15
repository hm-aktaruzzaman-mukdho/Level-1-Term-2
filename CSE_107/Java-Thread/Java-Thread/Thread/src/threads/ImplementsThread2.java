package threads;

class NewThread3 implements Runnable {
    @Override
    public void run() {
        try {
            for (int i = 100; i > 0; i--) {
                System.out.println("Child Thread: " + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println("Child interrupted.");
        }
        System.out.println("Exiting child thread.");
    }
}

public class ImplementsThread2 {
    public static void main(String[] args) throws InterruptedException {
        //Runnable r = new NewThread3();
        NewThread3 r = new NewThread3();
        //Both works
        Thread t = new Thread(r);
        t.start();
        //t.join();

        System.out.println("Exiting Main Thread");
    }
}