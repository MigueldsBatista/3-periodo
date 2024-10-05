package NewGame;

public enum DominoPiece {
    BLANK_BLANK(0, 0), // 0
    BLANK_ONE(0, 1),   // 1
    BLANK_TWO(0, 2),   // 2
    BLANK_THREE(0, 3), // 3
    BLANK_FOUR(0, 4),  // 4
    BLANK_FIVE(0, 5),  // 5
    BLANK_SIX(0, 6),   // 6
    
    ONE_ONE(1, 1),     // 7
    ONE_TWO(1, 2),     // 8
    ONE_THREE(1, 3),   // 9
    ONE_FOUR(1, 4),    // 10
    ONE_FIVE(1, 5),    // 11
    ONE_SIX(1, 6),     // 12
    
    TWO_TWO(2, 2),     // 13
    TWO_THREE(2, 3),   // 14
    TWO_FOUR(2, 4),    // 15
    TWO_FIVE(2, 5),    // 16
    TWO_SIX(2, 6),     // 17
    
    THREE_THREE(3, 3), // 18
    THREE_FOUR(3, 4),  // 19
    THREE_FIVE(3, 5),  // 20
    THREE_SIX(3, 6),   // 21
    
    FOUR_FOUR(4, 4),   // 22
    FOUR_FIVE(4, 5),   // 23
    FOUR_SIX(4, 6),    // 24
    
    FIVE_FIVE(5, 5),   // 25
    FIVE_SIX(5, 6),    // 26
    
    SIX_SIX(6, 6);     // 27

    private final Integer value1;
    private final Integer value2;

    DominoPiece(Integer value1, Integer value2) {
        this.value1 = value1;
        this.value2 = value2;
    }

    public int getValue1() {
        return value1;
    }

    public int getValue2() {
        return value2;
    }
}
