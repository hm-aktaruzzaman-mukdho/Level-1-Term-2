package threads;

public class JoinAliveThreads {
    public static void main(String[] args) {
        NewThread ob1 = new NewThread("One",5);
        NewThread ob2 = new NewThread("Two",15);
        NewThread ob3 = new NewThread("Three",20);

        System.out.println("Thread One is alive: " + ob1.t.isAlive());
        System.out.println("Thread Two is alive: " + ob2.t.isAlive());
        System.out.println("Thread Three is alive: " + ob3.t.isAlive());
        // wait for threads to finish
        try 
        {
            System.out.println("Waiting for threads to finish.");
            ob1.t.join();
            System.out.println("    "+ob1.t.getName() + " join finished");
            ob2.t.join();
            System.out.println("    "+ob2.t.getName() + " join finished");
            ob3.t.join();
            System.out.println("    "+ob3.t.getName() + " join finished");
        } 
        catch (InterruptedException e) 
        {
            System.out.println("Main thread Interrupted");
        }

        System.out.println("Thread One is alive: " + ob1.t.isAlive());
        System.out.println("Thread Two is alive: " + ob2.t.isAlive());
        System.out.println("Thread Three is alive: " + ob3.t.isAlive());
        System.out.println("Main thread exiting.");
    }
}
