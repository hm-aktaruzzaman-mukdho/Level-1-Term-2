package generics;

class GenCons {
    private double val;

    public <T extends Number> GenCons(T arg) //Generic constructor.This type parameter can only take Number class or its subclass.
    {
        val = arg.doubleValue();
    }

    void showVal() {
        System.out.println("val: " + val);
    }

    public static <V> boolean isIn(V x, V[] a) 
    //Unbounded generics.Here the type parameter V can take any class or interfaces as input.
    //For function the type parameter is placed before the return type of the function.
    {
        for (V t : a) {
            if (t.equals(x))
                return true;
        }
        return false;
    }
}

public class MyGenerics4 {
    public static void main(String args[]) {
        GenCons test = new <Integer>GenCons(100);
        GenCons test2 = new GenCons(123.5F);
        test.showVal();
        test2.showVal();
        Integer[] iArray = { 1, 2, 3, 4, 5 };
        System.out.println(GenCons.<Integer>isIn(1, iArray));
        Double[] dArray = { 1.2, 3.4, 5.6, 7.8, 9.1 };
        System.out.println(GenCons.<Double>isIn(5.6, dArray));
    }
}