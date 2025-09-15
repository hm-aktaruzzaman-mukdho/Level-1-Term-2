package generics;

interface MyInterface<E> 
{
    void newFunction();
}

class MyClass<T>{
    T value;

    void println()
    {
        System.out.println("Value : "+value);
    }

}

class NewClass<T> extends MyClass<T> implements MyInterface<T>
{
    
    T data;

    public NewClass(T data,T value)
    {
        super.value=value;
        this.data=data;
    }
    public void newFunction() {
        System.out.println("Data : "+data);
    }

}

public class MyPractice
{
    public static void main(String[] args) {
        NewClass<String> testclass=new NewClass<>("@5","Hello");
        testclass.println();
        testclass.newFunction();
    }
}
