/*
 * This class represents the Employee's profile in the
 * company.
 */
public class Employee {
    private int ID;            // the employee ID
    private String firstName;
    private String lastName;
    private double age;
    private String levelOfSecurity; // General, Admin
    private int successLoginCount;  // number of times this employee login succeeded
    private double attemptLoginCount; // number of times this employee attempted loging
    private boolean loggedIn;
    private Fingerprints fingerprints;

    /*
     * Constructor
     * @param id: the employee's ID
     * @param firstName: the employee's first name
     * @param lastName: the employee's last name
     * @param age: the employee's age
     * @param levelOfSecurity: the employee's level of security in the company
     * @param fingerprint: the employee's fingerprint
     */
    public Employee(int id, String firstName, String lastName, double age, String levelOfSecurity, char[][] fingerprint) {
        this.ID = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
        this.levelOfSecurity = levelOfSecurity;
        this.successLoginCount = 0;
        this.attemptLoginCount = 0;
        this.loggedIn = false;
        this.fingerprints = new Fingerprints();
        this.fingerprints.addFingerprint(fingerprint, Fingerprints.THUMB);
    }

    /*
     * String representation of the object
     */
    public String toString() {
        return firstName + " " + lastName + "[" + ID + "]";
    }

    //// Accessor methods ////
    public int getID() {
        return ID;
    }
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public double getAge() {
        return age;
    }

    public String getLevelOfSecurity() {
        return levelOfSecurity;
    }

    public int getSuccessLoginCount() {
        return successLoginCount;
    }

    public double getAttemptLoginCount(){
        return attemptLoginCount;
    }

    public boolean getLoggedIn(){
        return loggedIn;
    }

    public char[][] getFingerprint() {
        return fingerprints.getThumbFingerprint();
    }

    public void incrementSuccessLoginCount() {
        this.successLoginCount += 1;
    }

    public void incrementAttemptLoginCount(){
        this.attemptLoginCount += 1;
    }

    public void setLoggedIn(boolean loggedIn){
        this.loggedIn = loggedIn;
    }  

    public void setID(int id){
        this.ID = id; 
    }

}