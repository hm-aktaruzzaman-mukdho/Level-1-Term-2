class TestObject {

    //Add and remove synchronized keyword and see the change.
    public synchronized void print1() {
        for (int i = 0; i < 5; i++) {
            System.out.println("   Printing " + i + " by " + Thread.currentThread());
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized void print2() {
        for (int i = 0; i < 5; i++) {
            System.out.println("---Printing " + i + " by " + Thread.currentThread());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Caller1 implements Runnable {
    TestObject obj;

    Caller1(TestObject obj, String name) {
        this.obj = obj;
        new Thread(this, name).start();
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            obj.print1();
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
}

class Caller2 implements Runnable {
    TestObject obj;

    public Caller2(TestObject obj, String name) {
        this.obj = obj;
        new Thread(this, name).start();
    }

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            obj.print2();
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

        }
    }
}

class Monitor_Testing {

    public static void main(String[] args) {
        TestObject object = new TestObject();
        new Caller1(object, "Mukdho");
        new Caller2(object, "Moonpy");
    }
}
