/**
 * Benjamin Coates
 * Person.java
 * Lab 3
 * CIS 222
 * Spring 2015
*/

class Person
{
    // Class attribute
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

    /**
     * Sets the new age of the person
     * @param age The new age of the person
     */
    private void setAge(int age) {
        this.age = age;
    }

    /**
     * Sets the new name of the person
     * @param name The new name of the person
     */
    private void setName(String name) {
        this.name = name;
    }


    /**
     * Sets the new gender of the person
     * @param gender The new gender of the person
     */
    private void setGender(String gender) {
        gender = gender.toLowerCase();
        assert(gender == "male" || gender == "female");
        this.gender = gender;
    }

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