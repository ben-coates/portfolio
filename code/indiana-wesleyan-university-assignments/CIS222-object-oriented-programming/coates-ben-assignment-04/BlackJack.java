// Benjamin Coates and Aaron Cawthorn
// BlackJack.java
// Object Oriented Programming
// Spring 2015

import java.util.Scanner;

public class BlackJack {

    /**
     * Checks that the input give falls within the range of the two numbers given
     * @param input The number to be checked
     * @param low The low number of the range
     * @param high The high number of the range
     * @return False if the number false out of range, truw if it is range.
     */
    public static boolean checkInput(int input, int low, int high)
    {
        if(input < low || input > high)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    /**
     * Deals two cards to the player and dealer
     * @param shoe The shoe that the cards come from
     * @param dealer The dealer
     * @param player The player
     */
    public static void deal(Shoe shoe, Dealer dealer, Player player)
    {
        Card[] deal = shoe.deal(4);
        int i = 0;
        while(i < 4)
        {
            dealer.add(deal[i]);
            ++i;
            player.add(deal[i]);
            ++i;
        }
    }

    /**
     * Performs a turn of the player
     * @param shoe The shoe the card posibly dealt will come from
     * @param player The player
     * @param dealer The dealer
     */
    public static void playerTurn(Shoe shoe, Player player, Dealer dealer)
    {
        while(player.doesPlayerStay(dealer.get()) == false)
        {
            // Checks to see is cards are in the shoe
            if(shoe.isEmpty())
            {
                break;
            }
            player.add(shoe.deal());
        }
    }

    /**
     * Performs a turn of the dealer
     * @param shoe The shoe the cards possibly dealt will come from
     * @param player The player
     * @param dealer The dealer
     */
    public static void dealerTurn(Shoe shoe, Player player, Dealer dealer)
    {
        while(dealer.doesDealerStay() == false)
        {
            // Checks to see if cards are in the shoe
            if(shoe.isEmpty())
            {
                break;
            }
            dealer.add(shoe.deal());
        }
    }

    /**
     * Checks to see if the player or dealer won the round or if there was a push
     * @param dealer The dealer
     * @param player The player
     * @return Returns 0 if the delaer won, 1 if the player won, 2 if there was a push
     */
    public static int checkForWinner(Dealer dealer, Player player)
    {
        if(dealer.getHandValue() > 21 && player.getHandValue() > 21)
        {
            // This is a push and no one wins the round
            return 2;
        }
        else if(dealer.getHandValue() == player.getHandValue())
        {
            // This is a push no one wins the round
            return 2;
        }
        else if(dealer.getHandValue() > 21 && player.getHandValue() <= 21)
        {
            // Player wins the round
            return 1;
        }
        else if(dealer.getHandValue() <= 21 && player.getHandValue() > 21)
        {
            // Dealer wins the round
            return 0;
        }
        else if(dealer.getHandValue() <= 21 && player.getHandValue() <= 21 &&
                dealer.getHandValue() < player.getHandValue())
        {
            // Player wins the round
            return 1;
        }
        else if(dealer.getHandValue() <= 21 && player.getHandValue() <= 21 &&
                dealer.getHandValue() > player.getHandValue())
        {
            // Dealer wins the round
            return 0;
        }
        else
        {
            // This should never happen, but if it does, no one wins the round.
            return 2;
        }
    }

    /**
     * Prints the results of the games
     * @param dealergamewins The number of games the dealer won
     * @param playergamewins The number of games the player won
     */
    public static void printResults(int dealergamewins, int playergamewins)
    {
        System.out.println("Results:");
        System.out.println("Dealer: " + dealergamewins + "\t" + "Player: " + playergamewins);
        System.out.println();
    }

    /**
     * Plays the games
     * @param numberofgames The number of games to be played
     * @param numberofdecks The number of decks being used
     * @param playerstrategy The player strategy being used
     */
    public static void play(int numberofgames, int numberofdecks, int playerstrategy)
    {
        // Variables that hold the game wins
        int dealergamewins = 0;
        int playergamewins = 0;

        // Loop that executes the number of games is to be played
        for(int i = numberofgames; i > 0; i--)
        {
            // Created and shuffles a shoe with the approproate amount of decks.
            Shoe shoe = new Shoe(numberofdecks);
            shoe.shuffle();

            // Variables that hold the round wins
            int dealerwins = 0;
            int playerwins = 0;

            // Loop for the game
            while(!shoe.isEmpty())
            {
                // Creates a dealer and player using the player strategy
                Dealer dealer = new Dealer();
                Player player = new Player(playerstrategy);

                // Checks to make sure there are enough cards to be dealt
                if(shoe.size() < 4)
                {
                    break;
                }

                // Deals to the players
                deal(shoe, dealer, player);

                // Executes the player and dealer turns
                playerTurn(shoe, player, dealer);
                dealerTurn(shoe, player, dealer);

                // Checks for winner of round
                if(checkForWinner(dealer, player) == 1)
                {
                    playerwins++;
                }
                else if(checkForWinner(dealer, player) == 0)
                {
                    dealerwins++;
                }
            }
            // Checks for winner of game
            if(dealerwins > playerwins)
            {
                dealergamewins++;
            }
            else
            {
                playergamewins++;
            }
        }
        // Prints the results
        printResults(dealergamewins, playergamewins);
    }

    /**
     * Asks the user if they would like to run the program again
     * @param in The input scanner
     * @return Returns true if they want to continue, false if they do not
     */
    public static boolean doAgain(Scanner in)
    {
        final String playagain = "yes";
        String answer;

        System.out.println("Play agian?");
        System.out.print(">Enter \"yes\" or \"no\": ");
        answer = in.next();

        if(answer.equalsIgnoreCase(playagain))
        {
            System.out.println("...");
            return true;
        }
        else
        {
            return false;
        }
    }

    public static void main(String[] args)
    {
        // Variables
        boolean playagain = true;
        int numberofdecks;
        int numberofgames;
        int playerstrategy;

        // Input scanner
        Scanner in = new Scanner(System.in);

        // Formatting
        System.out.println("----------");

        // Program Loop
        do
        {
            // Asks user for number of decks to be in shoe
            System.out.print(">Enter number of decks in shoe (From 1 to 6): ");
            numberofdecks = in.nextInt();
            if(!checkInput(numberofdecks, 1, 6))
            {
                System.out.println("Invalid input!");
                break;
            }

            // Asks user for number of gamess to be played
            // Prompts from 1 to 1000 but does not checks to make sure input is correct
            System.out.print(">Enter number of games to play (From 1 to 1000): ");
            numberofgames = in.nextInt();
            if(!checkInput(numberofgames, 1, 1000))
            {
                System.out.println("Invalid input!");
                break;
            }
            

            // Asks user for strategy to be used
            // Prompts from 1 to 4 but does not checks to make sure input is correct
            System.out.print(">Enter strategy to employ (1 is Always Stay, 2 is Always Hit, 3 is Best, 4 is Random): ");
            playerstrategy = in.nextInt();
            if(!checkInput(playerstrategy, 1, 4))
            {
                System.out.println("Invalid input!");
                break;
            }

            // Outputs the information just recieved
            System.out.println("Playing " + numberofgames + " games with " + numberofdecks + " Deck(s)");
            System.out.println("...");

            // Plays the game
            play(numberofgames, numberofdecks, playerstrategy);

        } while(playagain == doAgain(in));

        // Formatting
        System.out.println("----------");
    }
}