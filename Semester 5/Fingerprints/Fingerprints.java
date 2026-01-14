/*
 * Represents all the fingerprints for one employee
 * Every employee has at least one fingerprint.
 */
public class Fingerprints {
    
    static final int THUMB  = 1;
    static final int INDEX  = 2;
    static final int MIDDLE = 3;
    static final int RING   = 4;
    static final int LITTLE = 5;

    private char[][] thumb;
    private char[][] index;
    private char[][] middle;
    private char[][] ring;
    private char[][] little;

    public Fingerprints () {
        thumb = null;
        index = null;
        middle = null;
        ring = null;
        little = null;
    }

    public void addFingerprint (char[][] fingerprint, int finger ) {
        switch (finger) {
            case THUMB:
                thumb = fingerprint;
                break;
        
            case INDEX:
                index = fingerprint;
                break;

            case MIDDLE:
                middle = fingerprint;
                break;  

            case RING:
                ring = fingerprint;
                break;

            case LITTLE:
                little = fingerprint;
                break;

            default:
                break;
        }
    }
    public char[][] getThumbFingerprint(){
        return thumb;
    }
    public char[][] getIndexFingerprint(){
        return index;
    }
    public char[][] getMiddleFingerprint(){
        return middle;
    }
    public char[][] getRingFingerprint(){
        return ring;
    }
    public char[][] getLittleFingerprint(){
        return little;
    }
}
