// Benjamin Coates and Aaron Cawthorn
// Card.java
// Object Oriented Programming
// Spring 2015

import java.lang.reflect.Array;

public class Card
{
    // Private members
    /**
     * Hold the vlaue of the card. Value represents suit and rank gotten from enumerations
     * Value must be >= 0 and < 52.
     */
    private int value;

    /**
     * faceup hold wether the card is faceup by bool
     */
    private boolean faceUp;

    /**
     * Array that holds the suit names
     */
    private static String[] suits = new String[]
            {"Spades", "Hearts", "Diamonds", "Clubs"};

    /**
     * Array that holds the ranks names of the cards
     */
    private static String[] ranks = new String[]
            {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    // Methods
    // Constructor
    /**
     * Constructor for a Card
     * @param value The number value of the card. Suit and Rank gotten from enumerations
     */
    public Card(int value)
    {
        setValue(value);
    }

    // Getters
    /**
     * Returns the value of the card
     * @return The rank of the card
     */
    public int getValue()
    {
        return value;
    }

    /**
     * Returns a boolean of true when faceuo
     * @return True if faceup adn false if facedown
     */
    public boolean getFaceUp()
    {
        return faceUp;
    }

    /**
     * Returns the rank of the card in integer format
     * @return The rank of the card
     */
    public int getRank()
    {
        int rank = (value % 13);
        return rank;
    }

    /**
     * Returns the rankvalue of the card for the game of blackjack.
     * Ranks 2-10 are returned as is. Ranks 11-13 are returned as 10. Rank 14 is returned as 1.
     * @return rankvalue of the card.
     */
    public int getRankValue()
    {
        int rankvalue = getRank() + 2;
        if(rankvalue == 14)
        {
            rankvalue = 1;
        }
        else if(rankvalue > 10 && rankvalue < 14)
        {
            rankvalue = 10;
        }
        return rankvalue;
    }

    // Setters
    /**
     * Sets the value of the Card
     * @param value The value of the card
     */
    private void setValue(int value)
    {
        assert(value >= 0 && value < 52);
        this.value = value;
    }

    /**
     * Turns the card over
     */
    public void turn()
    {
        faceUp = ! faceUp;
    }

    // Other Public Methods
    /**
     * Overrides toString
     * @return The card in a string
     */
    public String toString()
    {
        return rankToString() + " of " + suitToString();
    }

    // Other Private Methods
    private String suitToString()
    {
        int suit = (value % 4);
        return suits[suit];
    }

    /**
     * Turns the ranks 11, 12, 13, & 14 into strings of Jack, Queen, King and Ace
     * @return The correct string for the correct value
     */
    private String rankToString()
    {
        return ranks[getRank()];
    }
}


