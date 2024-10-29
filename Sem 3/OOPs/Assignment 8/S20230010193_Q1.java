/**
 * Name: Purval Madhukar Bhude
 * Roll No. S20230010193
 * Assignment 8 Exercise 1
 */

abstract class AnimalBehavior {
    abstract void makeSound();
    abstract void move();
}

class Mammal extends AnimalBehavior {
    void makeSound() {
        System.out.println("Mammal Sound");
    }
    void move() {
        System.out.println("Mammal Move");
    }
}

class Bird extends AnimalBehavior {
    void makeSound() {
        System.out.println("Bird Sound");
    }
    void move() {
        System.out.println("Bird Move");
    }
}

class Lion extends Mammal {
    void makeSound() {
        System.out.println("Roar");
    }
    void move() {
        System.out.println("Runs on the ground");
    }
}

class Eagle extends Bird {
    void makeSound() {
        System.out.println("Screech");
    }
    void move() {
        System.out.println("Soars high");
    }
}

class Zoo {
    private AnimalBehavior[] animals;
    private int index;

    public Zoo(int capacity) {
        animals = new AnimalBehavior[capacity];
        index = 0;
    }

    void addAnimal(AnimalBehavior animal) {
        if (index < animals.length) {
            animals[index++] = animal;
        } else {
            System.out.println("Zoo is full, can't add more animals.");
        }
    }

    void makeAllSounds() {
        for (int i = 0; i < index; i++) {
            animals[i].makeSound();
        }
    }

    void moveAll() {
        for (int i = 0; i < index; i++) {
            animals[i].move();
        }
    }
}

class S20230010193_Q1 {
    public static void main(String[] args) {
        Zoo myZoo = new Zoo(2);  

        Lion lion = new Lion();
        Eagle eagle = new Eagle();

        myZoo.addAnimal(lion);
        myZoo.addAnimal(eagle);

        System.out.println("All Animals Make Sounds:");
        myZoo.makeAllSounds();

        System.out.println("\nAll Animals Move:");
        myZoo.moveAll();
    }
}
