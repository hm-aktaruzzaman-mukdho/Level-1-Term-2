package threads;

class NewThread implements Runnable {
    String name; // name of thread
    Thread t;
    int x;

    NewThread(String threadName,int x) {
        name = threadName;
        this.x=x;
        t = new Thread(this, name);
        t.start(); // Start the thread
    }

    public void run() {
        System.out.println(name + " starting.");
        try {
            for (int i = x; i > 0; i--) {
                System.out.println(name + ": " + i);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(name + "Interrupted");
        }
        System.out.println(name + " exiting.");
    }
}

public class MultipleThreads {
    public static void main(String[] args) {
        System.out.println("Main thread starting.");

        new NewThread("One",10);
        new NewThread("Two",10);
        new NewThread("Three",10);

        try {
            // wait for other threads to end
            Thread.sleep(10000);
            //Sleep is a very poor way to wait the main thread till other threads finishs their execution.
            //A better way is join method.
        } catch (InterruptedException e) {
            System.out.println("Main thread Interrupted");
        }

        System.out.println("Main thread exiting.");
    }
}
