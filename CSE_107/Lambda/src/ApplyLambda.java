import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class MyComparator implements Comparator<MyClass> {
    @Override
    public int compare(MyClass o1, MyClass o2) {
        return o1.getName().compareTo(o2.getName());
    }
};

public class ApplyLambda {
    public static void main(String[] args) {

        // Runnable is a functional interface
        Runnable r1 = new Runnable() {
            public void run() {
                System.out.println("Runnable Interface 1");
            }
        };//This is not lambda.It is anonymous sub class.

        Thread t1 = new Thread(r1);
        t1.start();

        Runnable r2 = () -> System.out.println("Runnable Interface 2");
        //Why didn't we use new keyword here??????????????

        Thread t2 = new Thread(r2);
        t2.start();

        Runnable r3 = () -> {
            for (int i = 0; i < 10; i++) {
                System.out.println("Runnable Interface 3 ");
            }
            System.out.println();
        };

        Thread t3 = new Thread(r3);
        t3.start();

        Thread mythread = new Thread(() -> {
            for(int i=0;i<=10;i++)
            {
                System.out.println("----------------"+i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });
        mythread.start();

        List<MyClass> al = new ArrayList<>();

        al.add(new MyClass(1, "C"));
        al.add(new MyClass(3, "A"));
        al.add(new MyClass(2, "E"));
        al.add(new MyClass(5, "B"));
        al.add(new MyClass(4, "D"));
        al.add(new MyClass(2, "F"));

        printList(al);
        Collections.sort(al, new MyComparator());//Passing object of comparator
        printList(al);

        printList(al);
        // Comparator is a functional interface
        Collections.sort(al, 

        new Comparator<MyClass>() {//Using anonymous subclass
            @Override
            public int compare(MyClass o1, MyClass o2) {
                return o1.getName().compareTo(o2.getName());
            }
        }
        
        );
        printList(al);

        printList(al);
        Collections.sort(al, (o1, o2) -> o1.getName().compareTo(o2.getName()));//Using lambda in one line.Doesn't need return type
        printList(al);

        printList(al);
        Collections.sort(al, (o1, o2) -> {//Using lambda with return type.
            if (o1.getId() == o2.getId()) {
                return o1.getName().compareTo(o2.getName());
            }
            return o1.getId() - o2.getId();
        });
        printList(al);

        printList(al);
        Collections.sort(al, Comparator.comparing(MyClass::getName));//What in this  :( ????
        printList(al);
    }

    public static void printList(List<MyClass> list) {
        System.out.println("----------");
        list.forEach(e -> System.out.println(e.getId() + ", " + e.getName()));//Lambda used.
    }
}
