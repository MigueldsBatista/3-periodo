
public class Cpu {
String name;
double clock;
public Cpu(String name, double clock) {
this.name = name;
this.clock = clock;
}

void overClock(double acc) {
clock *= acc;
}
}