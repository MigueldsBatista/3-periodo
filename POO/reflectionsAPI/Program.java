import java.lang.reflect.Field;

public class Program {
public static void main(String[] args) {
    Animal animal = new Animal();
    animal.setName("Lion");
    animal.setGenre("Mammal");
    animal.setFamily("Felidae");
    animal.setHabitat("Savannah"); 
    
    Field[] animalFields = animal.getClass().getDeclaredFields();
    for(int i = 0; i < animalFields.length; i++) {
        Field field = animalFields[i];
        System.err.println("Field name: " + field.getName());
        }
    }
}
// Output:
