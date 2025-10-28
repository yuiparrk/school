
/**
 * Write the GlassBridge program inside the main method
 * according to the assignment description.
 *
 * When executing your code, copy from the assignment detail and make sure it matches with what you should be getting.
 * After reading the bridge details by column and storing it in a 2-D array, read the path by row and store that in a 1D array.
 * Then loop through the bridge according to the path making sure the bridge is safe, True means the panel on the bridge is safe, False means the panel is unsafe.
 * At the end, if the path leads you all the way to the end of the bridge without encountering a false block, return Safe, else return False.
 *
 * To compile:
 *        javac GlassBridge.java
 * To execute:
 *        java GlassBridge *enter the glass bridge true/false* *enter the "LR" sequence (path) you want to test*
 *
 * DO NOT change the class name
 * DO NOT use System.exit()
 * DO NOT change add import statements
 * DO NOT add project statement
 *
 *  @author Ved Patel
 */
public class GlassBridge {

    public static void main(String[] args) {

        boolean[][] bridge = new boolean[2][10];

        int index = 0;
        for (int col = 0; col < 10; col++) {
            bridge[0][col] = Boolean.parseBoolean(args[index]);
            bridge[1][col] = Boolean.parseBoolean(args[index + 1]);
            index += 2;
        }

        char[] path = new char[10];
        for (int i = 0; i < 10; i++) {
            path[i] = args[index + i].charAt(0);
        }

        boolean Safe = true;
        for (int i = 0; i < 10; i++) {
            int row = (path[i] == 'L' || path[i] == 'l') ? 0 : 1;
            if (!bridge[row][i]) {
                Safe = false;
                break;
            }
        }

        if (Safe) {
            System.out.println("Safe");
        } else {
            System.out.println("Unsafe");
        }
    }
}
