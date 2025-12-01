/*  Compilation:  javac FireboyAndWatergirl.java
 *  Execution:    java FireboyAndWatergirl n
 *
 *  @author Juliania Shyprykevych, Sarah Benedicto
 *
 *************************************************************************/
public class FireboyAndWatergirl {

    // heroes
    private static int FIREBOY = 1;
    private static int WATERGIRL = 2;

    /**
     * Finds path from start (row 0 col 0) to end (row.length-1 col[row].length-1)
     * of a 2D char "maze"
     * By traveling horizontally or vertically, the collectedDiamonds 2D array is
     * used to represent visited coordinates.
     * 
     * @param maze              2D char array representing cell contents: F, W, G, N
     * @param collectedDiamonds booleann 2D array representing each visited maze
     *                          coordinate.
     * @param row               Current row coordinate of path.
     * @param col               Current column coordinate of path.
     * @param int               hero: FIREBOY or WATERGIRL
     * @return int array of size 2 representing row and column of the end coordinate
     *         if path is found, null otherwise
     */
    public static void nextStep(char[][] maze, int row, int col, boolean[][] collectedDiamonds, int hero) {

        if (row < 0 || row >= maze.length || col < 0 || col >= maze[0].length)
            return;

        if (collectedDiamonds[row][col])
            return;

        char cell = maze[row][col];

        if (cell == 'G')
            return;

        if (hero == 1) {
            if (cell == 'W')
                return;
        }

        if (hero == 2) {
            if (cell == 'F')
                return;
        }

        collectedDiamonds[row][col] = true;

        nextStep(maze, row + 1, col, collectedDiamonds, hero);
        nextStep(maze, row, col - 1, collectedDiamonds, hero);
        nextStep(maze, row - 1, col, collectedDiamonds, hero);
        nextStep(maze, row, col + 1, collectedDiamonds, hero);
    }

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Error: FireboyAndWatergirl requires a file name as the first command line argument!");
            return;
        }

        // Read the maze from the file
        String file = (args[0]);
        StdIn.setFile(file);
        int d = StdIn.readInt();

        // create the maze arrays
        char[][] maze = new char[d][d];

        // create the visited arrays
        boolean[][] fireboyVisited = new boolean[d][d];
        boolean[][] watergirlVisited = new boolean[d][d];

        // fill the maze array
        for (int row = 0; row < d; row++) {
            for (int col = 0; col < d; col++) {
                StdIn.readChar();
                maze[row][col] = StdIn.readChar();
            }
        }

        // attempt the next step
        nextStep(maze, 0, 0, fireboyVisited, FIREBOY);

        System.out.println("Fireboy Visited:");
        for (int row = 0; row < d; row++) {
            for (int col = 0; col < d; col++) {
                if (fireboyVisited[row][col]) {
                    System.out.print("X ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

        // attempt the next step
        nextStep(maze, 0, 0, watergirlVisited, WATERGIRL);

        System.out.println("Watergirl Visited:");
        for (int row = 0; row < d; row++) {
            for (int col = 0; col < d; col++) {
                if (watergirlVisited[row][col]) {
                    System.out.print("X ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

    }
}