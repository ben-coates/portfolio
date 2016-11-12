/**
 * Benjamin Coates
 * Person.java
 * Lab 3
 * CIS 222
 * Spring 2015
*/

class Person
{
    // Class attributes
    /**
     * Age of the person
     */
    private int age = 0;

    /**
     * Name of the person
     */
    private String name = "";

    /**
     * Gender of the person
     */
    private String gender = "";

    // Class constructor
    /**
     * Creates a new instance of the object person
     * Uses set functions to maintain DRY code. (i.e. avoids repetition, code reuse)
     * @param name Name of the newly created person
     * @param age Age of the newly created person
     * @param gender Gender of the newly created person
     */
    Person(int age, String name, String gender)
    {
        setAge(age);
        setName(name);
        setGender(gender);
    }

    // Getters
    /**
     * Gets the age of the person
     * @return The age of the person
     */
    public int getAge()
    {
        return age;
    }

    /**
     * Gets the name of the person
     * @return The name of the person
     */
    public String getName() {
        return name;
    }

    /**
     * Gets the gender of the person
     * @return The gender of the person
     */
    public String getGender() {
        return gender;
    }

    // Setters
    /**
     * Sets the new age of the person
     * Checks to see if age is greater than zero.
     * If not prints message to console
     * @param age The new age of the person
     */
    private void setAge(int age)
    {
        if(age > 0) {
            this.age = age;
        }
        else
        {
            System.out.println("Age must be greater than 0");
        }
    }

    /**
     * Sets the new name of the person
     * Checks to see if name has at least one character
     * If not prints a message to the console
     * @param name The new name of the person
     */
    private void setName(String name)
    {
        if (name != "")
        {
            this.name = name;
        }
        else
        {
            System.out.println("Name must be at least on character long");
        }
    }


    /**
     * Sets the new gender of the person
     * Converts the input into all lowercase
     * Checks to see of gender is either male or female
     * If not, prints a message to the console
     * @param gender The new gender of the person
     */
    private void setGender(String gender) {
        if(gender.compareToIgnoreCase("male") >= 0 || gender.compareToIgnoreCase("female") >= 0)
        {
            this.gender = gender.toLowerCase();
        }
        else
        {
            System.out.println("Gender must equal \"male\" or \"female\"");
        }
    }

    // Other Methods
    /**
     * Returns the information of the object in a String
     * @return The present information of the existing person in a String
     */
    @java.lang.Override
    public java.lang.String toString() {
        return "Person{" +
                "age=" + age +
                ", name='" + name + '\'' +
                ", gender='" + gender + '\'' +
                '}';
    }

    /**
     * Prints the info of toString to the console
     */
    public void printInfo()
    {
        System.out.println(toString());
    }
}