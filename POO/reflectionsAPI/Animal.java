public class Animal {
private String name;
private String genre;
private String family;
private String habitat;

public Animal(String name, String genre, String family, String habitat) {
    this.name = name;
    this.genre = genre;
    this.family = family;
    this.habitat = habitat;
}
public Animal(){}
public String getFamily() {
    return family;
}

public String getGenre() {
    return genre;
}

public String getHabitat() {
    return habitat;
}
public String getName() {
    return name;
}

public void setFamily(String family) {
    this.family = family;
}

public void setGenre(String genre) {
    this.genre = genre;
}
public void setHabitat(String habitat) {
    this.habitat = habitat;
}

public void setName(String name) {
    this.name = name;
}
}
