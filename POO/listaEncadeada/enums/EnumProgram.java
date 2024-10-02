package enums;

public class EnumProgram {
public static void main(String[] args) {

    for (WeekDay dia : WeekDay.values()) {
        System.out.println(dia);
    }
    WeekDay monday = WeekDay.MONDAY;
    System.out.println(monday.getNumeroDia());
}

}
