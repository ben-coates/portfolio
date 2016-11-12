// Benjamin Coates and Aaron Cawthorn
// Hand.java
// Object Oriented Programming
// Spring 2015

import java.util.ArrayList;
import java.util.List;

public class Hand {

    // Private Memembers
    /**
     * List that holds the cards in the hand.
     */
    private List<Card> hand = new ArrayList<Card>();

    /**
     * Constructor
     */
    public Hand()
    {
        // Does nothing
    }

    // Getters
    /**
     * Removes and returns the "top" card of the pile.  It just uses the ArrayList method
     */
    public Card getTopDeck()
    {
        assert(!isEmpty());
        return hand.remove(size() - 1);
    }

    /**
     * Gets the top card of the deck but does not remove it. Uses arrayList get method.
     * @return
     */
    public Card get()
    {
        assert(!isEmpty());
        return hand.get(size() - 1);
    }

    /**
     * Gets the size of the cards array. If the array is empty returns 0. If cards are in array returns size
     * @return The size of the cards array
     */
    public int size()
    {
        return hand.size();
    }

    /**
     * Gets the BlackJack value of the hand.
     * @return The value of the hard hand for BlackJack
     */
    public int getHandValue()
    {
        boolean aceIsPresent = false;
        int numberOfAces = 0;
        int handvalue = 0;
        for(int i = 0; i < hand.size(); i++)
        {
            Card card = hand.get(i);
            int currentcardvalue = card.getRankValue();
            if(currentcardvalue == 1)
            {
                aceIsPresent = true;
                ++numberOfAces;
            }
            handvalue = handvalue + card.getRankValue();
        }
        if(aceIsPresent == true)
        {
            for( ; numberOfAces > 0; numberOfAces--)
            {
                if(handvalue <= 11)
                {
                    handvalue = handvalue + 10;
                }
            }
        }
        return handvalue;
    }

    /**
     * Checks to see of the array of cards is empty
     * @return The boolean of wether the array is empty or not
     */
    public boolean isEmpty()
    {
        return hand.isEmpty();
    }

    // Setters
    /**
     * add - puts a Card at the end ("bottom") of the pile.  It just uses the ArrayList method
     * @Param PlaceCard the card to be added to the deck
     */
    public void add(Card PlaceCard)
    {
        hand.add(PlaceCard);
    }

    // Other Methods
    /**
     * Remove the top card from the deck and returns it
     * @return The top card that has been removed from the deck
     */
    public Card play()
    {
        assert(!isEmpty());
        Card cardplaying = getTopDeck();
        cardplaying.turn();
        return cardplaying;
    }

    public String toString(){
        String result = "";
        for(Card card : hand)
            result += card + "\n";
        return result;
    }
}
