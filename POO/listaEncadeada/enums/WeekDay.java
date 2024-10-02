package enums;

public enum WeekDay{
    MONDAY(1), 
    TUESDAY(2), 
    WEDNESDAY(3), 
    THRUSDAY(4), 
    FRIDAY(5), 
    SATURDAY(6), 
    SUNDAY(7);

    private final int numeroDia;

    WeekDay(int numeroDia){
        this.numeroDia=numeroDia;
    }

    public int getNumeroDia() {
        return numeroDia;
    }

}
