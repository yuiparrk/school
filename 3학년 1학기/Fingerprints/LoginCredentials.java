/*
 * This class represents the credentials being 
 * used to attempt to login into the company's system.
 */
public class LoginCredentials {
    
    private int ID;                // employee ID is required for login
    private char[][] fingerprint;  // employee fingerprint required for login

    /*
     * Constructor
     */
    public LoginCredentials(int ID, char[][] fingerprint) {
        this.ID = ID;
        this.fingerprint = fingerprint;
    }

    /*
     * Returns the ID being used to login
     */
    public int getID() {
        return ID;
    }

    /*
     * Returns the fingerpring being used to login
     */
    public char[][] getFingerprint() {
        return fingerprint;
    }
}
