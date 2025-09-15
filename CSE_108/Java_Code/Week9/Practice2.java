class Animal {
    private String name;
    private int age;

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void print() {
        System.out.print(name + " is a " + getClass().getName() + ", aged " + age);
    }

    public boolean isLethalToAdultHumans() {
        if (getClass().getName().equals("EasternBrownSnake"))
            return true;

        if (getClass().getName().equals("RedBackSpider"))
            return true;
        return false;
    }

    // your code
}

abstract class Bird extends Animal {
    public Bird(String name, int age) {
        super(name, age);
    }
}

abstract class Mammal extends Animal {

    public Mammal(String name, int age) {
        super(name, age);
    }

    public void printBloodType() {
        System.out.print(", Warm-Blooded!");
    }

}

abstract class Reptile extends Animal {
    public Reptile(String name, int age) {
        super(name, age);
    }
}

abstract class Fish extends Animal {
    public Fish(String name, int age) {
        super(name, age);
    }
}

abstract class Arachnid extends Animal {
    public Arachnid(String name, int age) {
        super(name, age);
    }
}

class Albatross extends Bird {

    public Albatross(String string, int i) {
        super(string, i);
    }

}

class Dog extends Mammal {

    public Dog(String string, int i) {
        super(string, i);
    }

}

class FruitBat extends Mammal {

    public FruitBat(String string, int i) {
        super(string, i);
    }

}

class EasternBrownSnake extends Reptile {

    public EasternBrownSnake(String string, int i) {
        super(string, i);
    }

}

class GreatWhiteShark extends Fish {

    public GreatWhiteShark(String string, int i) {
        super(string, i);
    }

}

class RedBackSpider extends Arachnid {

    public RedBackSpider(String string, int i) {
        super(string, i);
    }

}

class Platypus extends Mammal {

    public Platypus(String string, int i) {
        super(string, i);
    }

}

class Human extends Mammal {

    public Human(String string, int i) {
        super(string, i);
    }

}

// your code

public class Practice2 {
    public static void main(String[] args) {
        Bird alex = new Albatross("Alex", 39);
        Mammal spot = new Dog("Spot", 7);
        Mammal fred = new FruitBat("Fred", 10);
        Reptile steph = new EasternBrownSnake("Steph", 12);
        Fish bruce = new GreatWhiteShark("Bruce", 40);
        Arachnid charlotte = new RedBackSpider("Charlotte", 1);
        Mammal perry = new Platypus("Perry", 5);
        Mammal bob = new Human("Bob", 20);

        Animal[] animals = { alex, spot, fred, steph, bruce, charlotte, perry, bob };
        for (Animal a : animals) {
            a.print();
            if (a instanceof Mammal) {
                ((Mammal) a).printBloodType();
            }
            if (a.isLethalToAdultHumans()) {
                System.out.print(", and it's lethal!");
            }
            System.out.println();
        }
        System.out.println();
    }
}

/*
 * Write the necessary classes to achieve the following output of the main
 * method.
 * 
 * Alex is a Albatross, aged 39
 * Spot is a Dog, aged 7, Warm-Blooded!
 * Fred is a FruitBat, aged 10, Warm-Blooded!
 * Steph is a EasternBrownSnake, aged 12, and it's lethal!
 * Bruce is a GreatWhiteShark, aged 40
 * Charlotte is a RedBackSpider, aged 1, and it's lethal!
 * Perry is a Platypus, aged 5, Warm-Blooded!
 * Bob is a Human, aged 20, Warm-Blooded!
 * 
 */
