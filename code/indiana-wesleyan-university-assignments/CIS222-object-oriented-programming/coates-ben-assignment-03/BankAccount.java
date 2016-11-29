// File name: BankAccount.java
// Name: Benjamin Coates
// Class: CIS-222
// Lab: Lab 2
// Term: Spring 2015
// **************************************

import java.lang.String;

public class BankAccount
{
    /**
     * the number of the account 
     */
    private long accountNumber;

    /**
     * the amount in the checking account
     */
    private double checkingTotal;

    /**
     * the amount in the savings account
     */
    private double savingsTotal;

    /**
     * the total amount in the bank account 
     */
    private double accountTotal;

    /**
     * the name of the holder 
     */
    private String name;

    /**
     * Empty Constructor 
     */
    public BankAccount()
    {
        setAccountNumber(00);
        setCheckingTotal(0.00);
        setSavingsTotal(0.00);
        setAccountTotal();
        setName("");
    }

    /** Constructor that recieves four parameters
     *  @param accountnumber The account number of the bank account
     *  @param checkingtotal The checking account total of the bank account
     *  @param savingstotal The savings accout total of the bank account
     *  @param fullname The name of the bank account holder
     */
    public BankAccount(long accountnumber, double checkingtotal, double savingstotal, String fullname)
    {
        setAccountNumber(accountnumber);
        setCheckingTotal(checkingtotal);
        setSavingsTotal(savingstotal);
        setAccountTotal();
        setName(fullname);
    }

    /**
     * Method that performs a checking withdrawl
     * @param withdrawl The amount being withdrawn from checking
     * Calls setAccountTotal()
     */
    public void checkingWithdrawl(double withdrawl)
    {
        this.checkingTotal = checkingTotal - withdrawl;
        setAccountTotal();
    }

    /**
     * Method that performs a savings withdrawl
     * @param withdrawl The amount being withdrawn from savings
     * Calls setAccountTotal()
     */
    public void savingsWithdrawl(double withdrawl)
    {
        this.savingsTotal = savingsTotal - withdrawl;
        setAccountTotal();
    }

    /**
     * Method that performs a checking deposit
     * @param deposit The amount being deposited in checking
     * Calls setAccountTotal()
     */
    public void checkingDeposit(double deposit)
    {
        this.checkingTotal = checkingTotal + deposit;
        setAccountTotal();
    }

    /**
     * Method that performs a savings deposit
     * @param deposit The amount being deposited in savings
     * Calls setAccountTotal()
     */
    public void savingsDeposit(double deposit)
    {
        this.savingsTotal = savingsTotal + deposit;
        setAccountTotal();
    }

    /**
     * Method that gets the account number
     * @return The account number of the bank account
     */
    public long getAccountNumber()
    {
        return accountNumber;
    }

    /**
     * Method that sets the account number
     * @param accountNumber The new account number of the bank account
     */
    public void setAccountNumber(long accountNumber)
    {
        this.accountNumber = accountNumber;
    }

    /**
     * Method that gets the checking account total
     * @return The checking account total
     */
    public double getCheckingTotal()
    {
        return (checkingTotal);
    }

    /**
     * Method that sets the checking account total
     * @param checkingTotal The new checking account total
     * Calls setAccountTotal()
     */
    public void setCheckingTotal(double checkingTotal)
    {
        this.checkingTotal = checkingTotal;
        setAccountTotal();
    }

    /**
     * Method that gets the savings account total
     * @return The savings account total
     */
    public double getSavingsTotal()
    {
        return savingsTotal;
    }

    /**
     * Method that sets the savings account total
     * @param savingsTotal The new savings account total
     * Calls setAccountTotal()
     */
    public void setSavingsTotal(double savingsTotal)
    {
        this.savingsTotal = savingsTotal;
        setAccountTotal();
    }

    /**
     * Method that gets the account total
     * @return The account total
     */
    public double getAccountTotal()
    {
        return accountTotal;
    }

    /**
     * Method that sets the account total by adding checking and savings total
     * Called whenever there is an adjustment to the savings or checking account totals
     */
    public void setAccountTotal()
    {
        this.accountTotal = getCheckingTotal() + getSavingsTotal();
    }

    /**
     * Method that gets the name of the the account holder
     * @return The name of the account holder
     */
    public String getName()
    {
        return name;
    }

    /**
     * Method that sets the name of the account user
     * @param name The new name of the account holder
     */
    public void setName(String name)
    {
        this.name = name;
    }

    /**
     * Method that overides the toString java method
     * @return A String with an account summary of all account information
     */
    public String toString()
    {
        return "Account Summary " +
                "Name: " + name +
                "Account Number: " + accountNumber +
                "Account Total: $" + accountTotal +
                "Checking: $" + checkingTotal +
                "Savings: $" + savingsTotal;
    }
}
