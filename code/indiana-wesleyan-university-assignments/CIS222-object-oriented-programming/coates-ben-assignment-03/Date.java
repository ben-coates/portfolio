/**
 * Benjamin Coates
 * Date.java
 * Lab 3
 * CIS 222
 * Spring 2015
 */

import java.lang.String;
import java.util.Calendar;
import java.util.GregorianCalendar;

class Date
{
    // Class atributes
    /**
     * Gregorain style Calendar
     */
    private Calendar when = new GregorianCalendar();

    /**
     * Where the date will take place
     */
    private String where;

    /**
     * First person on the date
     */
    private Person person1;

    /**
     * Second person on the date
     */
    private Person person2;

    //Constructors

    /**
     * Creates a new instance of the object Date.
     * Uses set functions to maintain DRY code.
     * Empty Constructor, no parameter
     * Sets when to the current date, where to here, Person1 and Person2 are NULL
     */
    Date()
    {
        when = Calendar.getInstance();
        setWhere("Here");
    }

    /**
     * Creates a new instance of the object Date.
     * Uses set functions to maintain DRY code.
     * @param year The year of the date
     * @param month The month of the date
     * @param date The day of the date
     * @param where The location of the date
     */
    Date(int year, int month, int date, String where)
    {
        setWhen(year, month, date);
        setWhere(where);
    }

    /**
     * Creates a new instance of the object Date.
     * Uses set functions to maintain DRY code.
     * @param year The year of the date
     * @param month The month of the date
     * @param date The day of the date
     * @param where The location of the date
     * @param person1 The first person on the date
     * @param person2 The second person on the date
     */
    Date(int year, int month, int date, String where, Person person1, Person person2)
    {
        setWhen(year, month, date);
        setWhere(where);
        setPerson1(person1);
        setPerson2(person2);
    }

    // Getters

    /**
     * Gets the instance of the Calendar of the date
     * @return The Calendar object when
     */
    public Calendar getWhen()
    {
        return when;
    }

    /**
     * Gets the location of the date
     * @return The location of the date
     */
    public String getWhere()
    {
        return where;
    }

    /**
     * Gets the instance of the first person on the date
     * @return The instance of the first person on the date
     */
    public Person getPerson1()
    {
        return person1;
    }

    /**
     * Gets the instance of the second person on the date
     * @return The instance of the second person on the date
     */
    public Person getPerson2()
    {
        return person2;
    }

    // Setters

    /**
     * Sets the Year, Month, and Day of the Calendar object of the date
     * @param year The year of the date
     * @param month The month of the date
     * @param date The day of the date
     */
    public void setWhen(int year, int month, int date)
    {
        when.set(year, month, date);
    }

    /**
     * Sets the location of the date
     * @param where The location of the date
     */
    public void setWhere(String where)
    {
        this.where = where;
    }

    /**
     * Sets the first person on the date
     * Makes use of the thisIsIWU function
     * @param person The instance of the first person on the date
     */
    public void setPerson1(Person person)
    {
        if(thisIsIWU(person, getPerson2()))
        {
            this.person1 = person;
        }
        else
        {
            System.out.println("Persons genders cannot be the same! THIS IS IWU!!! WE DON'T DO THAT!");
        }
    }

    /**
     * Sets the second person on the date
     * Makes use of the thisIsIWU function
     * @param person The instance of the first person on the date
     */
    public void setPerson2(Person person)
    {
        if(thisIsIWU(person, getPerson1()))
        {
            this.person2 = person;
        }
        else
        {
            System.out.println("Persons genders cannot be the same! THIS IS IWU!!! WE DON'T DO THAT!");
        }
    }

    // Other Methods

    /**
     * Overrides to String method
     * @return The MONTH/DAY/YEAR of the Calander, where, person1 and person2.
     */
    @java.lang.Override
    public java.lang.String toString()
    {
        return "Date{" +
        "when=" + when.get(Calendar.MONTH) + "/"
                + when.get(Calendar.DATE) + "/"
                + when.get(Calendar.YEAR) +
        ", where='" + getWhere() +
        ", person1=" + getPerson1() +
        ", person2=" + getPerson2() +
        '}';
    }

    /**
     * Prints info of the toString to the console
     */
    public void printInfo()
    {
        System.out.println(toString());
    }

    /**
     * Method that checks to see if the genders of the two persons on the date are the same
     * If they are not the same, it returns true.
     * If they are the same, it returns false.
     * @param person1 The first person on the date
     * @param person2 The second person on the date
     * @return returns true if genders are different, returns false if genders are the same.
     */
    private boolean thisIsIWU(Person person1, Person person2)
    {
        if(person1 == null || person2 == null)
        {
            return true;
        }
        if(person1.getGender() != person2.getGender())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}