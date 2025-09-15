class Production{
    int value;

    public void produce(int i)
    {
        this.value=i;
        System.out.println(Thread.currentThread().getName()+" produces "+value);
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        System.out.println(Thread.currentThread().getName()+" Exit.");
    }

    synchronized public void consume()
    {
        System.out.println(Thread.currentThread().getName()+" consumes "+value);
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

        System.out.println(Thread.currentThread().getName()+" Exit.");
    }
}

class Producer implements Runnable{

    private Production production;

    public Producer(Production production,String name)
    {
        this.production=production;
        new Thread(this,name).start();
    }


    @Override
    public void run() {
        for(int i=0;i<20;i++)
        {
            production.produce(i);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
    }
    
}

class Consumer implements Runnable{
    private Production production;

    public Consumer(Production production,String name) {
        this.production = production;
        new Thread(this, name).start();
    }

    @Override
    public void run()
    {
        for(int i=0;i<10;i++)
        {
            production.consume();
            try{
                Thread.sleep(2000);
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
    }
}

class MainClass{
    public static void main(String[] args) {
        
        Production production = new Production();
        new Producer(production,"    Producer");
        new Consumer(production, "----Consumer 1");
        new Consumer(production, "Consumer 2");
    }
}