// Benjamin Coates and Aaron Cawthorn
// Dealer.java
// Object Oriented Programming
// Spring 2015

public class Dealer extends Hand
{
    boolean stay = false;
    
    
    Dealer()
    {
        // Nothing in the constructor
    }

    /**
     * Returns a boolean of whether the dealer stays or not
     * @return Boolean true if the dealer stays and false if they do not
     */
    public boolean doesDealerStay()
    {
        if(getHandValue() >= 17)
        {
            stay = true;
        }
        return stay;
    }
    
    
    
}