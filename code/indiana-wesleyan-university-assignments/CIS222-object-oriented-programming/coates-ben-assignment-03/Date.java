/**
 * Benjamin Coates
 * Date.java
 * Lab 3
 * CIS 222
 * Spring 2015
 */

import java.lang.String;
import java.util.Calendar;
import java.util.TimeZone;

class Date
{
    // Class atributes
    private Calendar when;
    private String where = "";
    private Person person1;
    private Person person2;

    Date()
    {
        when = Calendar.getInstance(TimeZone.getTimeZone("America/Indianapolis"));
        setWhere("Here");
    }

    Date(Calendar when, String where)
    {
        setWhen(when);
        setWhere(where);
    }

    Date(Calendar when, String where, Person person1, Person person2)
    {
        setWhen(when);
        setWhere(where);
        setPerson1(person1);
        setPerson2(person2);
    }

    public Calendar getWhen()
    {
        return when.getInstance();
    }

    public String getWhere()
    {
        return where;
    }

    public Person getPerson1()
    {
        return person1;
    }

    public Person getPerson2()
    {
        return person2;
    }

    public void setWhen(Calendar when)
    {
        this.when = when;
    }

    public void setWhere(String where)
    {
        this.where = where;
    }

    public void setPerson1(Person person)
    {
        person1 = person;
    }

    public void setPerson2(Person person)
    {
        person2 = person;
    }

    @java.lang.Override
    public java.lang.String toString()
    {
        return "Date{" +
                "when=" + when +
                ", where='" + where + '\'' +
                ", person1=" + person1 +
                ", person2=" + person2 +
                '}';
    }
}