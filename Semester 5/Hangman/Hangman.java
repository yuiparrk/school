import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Use 1D arrays, StdIn, and StdOut to create a playable Hangman game 
 * Methods to complete: checkLetter(), markGuessed(), 
 *                      checkWin(), and exportStats()
 * 
 * To compile: javac Hangman.java
 * To run: java Hangman inputFileName outputFileName
 * example: java Hangman input1.in stats.out
 * 
 * DO NOT add any import statements
 * DO NOT add the project statement
 * DO NOT change the class name
 * DO NOT change the headers of ANY of the given functions
 * DO NOT add any new class fields
 * DO NOT use System.exit() 
 * 
 * @author Sulaiman Hasan
 * @author Kriti Kumaran
 */
public class Hangman {

    /**
     * Chooses and returns random word from the array for the game.  
     * @param inputFile The given input file to read from
     * @return the random word chosen for the game 
     */
    public static char[] selectWord(String inputFile){

	StdIn.setFile(inputFile);
        int n = StdIn.readInt();
        String[] words = new String[n];
        for(int i = 0; i < n; i++) {
            words[i] = StdIn.readString();
        }
        int index = StdRandom.uniform(n);

        int wordLength = words[index].length();
        char[] word = new char[wordLength];
        for ( int i = 0; i < words[index].length(); i++ ) {
            word[i] = words[index].charAt(i);
        }
        return word;
    }

    /**
     * Update the array of letters based on the character the user has guessed
     * Return true if the array was changed, or false otherwise
     * 
     * Loop through the word. If it contains the guessed letter, 
     * then update the letters array at that positionfrom an underscore to the correct character.
     * 
     * @param userLetters Array of chars, contains '_' for unknown spaces, or the correct letter if it was guessed before
     * @param guess The char letter the user has inputted as a guess
     * @param word The word to be guessed
     * @return true if the guessed letter is in the word, or false if it is not  
     */
public static boolean checkLetter(char[] userLetters, char[] word, char guess){
    boolean found = false;
    for (int i = 0; i < word.length; i++) {
        if (word[i] == guess) {
            userLetters[i] = guess;
            found = true;
        }
    }
    return found;
}
    /**
     * Update an array of booleans by marking a guessed letter’s specified index as true. 
     * Typecast the letter into an integer and subtract that by the ascii value of 'a' to obtain its index in the array.
     * Get the ascii value of 'a' by casting it to an int
     * Then, mark this index as true if it wasn’t already.
     *
     * @param guessedLetters Boolean array, contains true if the letter was guessed before, false if not 
     * @param letter The letter we are checking for
     * @return true if the letter was not guessed before, or false if the letter was already guessed
     */
public static boolean markGuessed(boolean[] guessedLetters, char letter){
    int index = (int) letter - (int) 'a';
    if (guessedLetters[index]) {
        return false; // already guessed
    } else {
        guessedLetters[index] = true;
        return true;
    }
}
    /**
     * Loop through the letters array to see if the word was guessed. 
     * If there are no underscores left in the array, the game is won.
     * 
     * @param userLetters Array of chars, contains '_' for unknown spaces, or the correct letter if it was guessed before
     * @return  true if there was a win, or false if there wasn’t. 
     */
 public static boolean checkWin(char[] userLetters){
    for (int i = 0; i < userLetters.length; i++) {
        if (userLetters[i] == '_') {
            return false;
        }
    }
    return true;
}

    /**
     * Follow the following format to export the stats to an output file:
     * 1st line: (You won) or (You lost)
     * 2nd line: Points: {int points}
     * 3rd line: The word was: {word}
     * 4th line: Total guesses: {int totalGuesses}
     * 5th line: Incorrect guesses: {int wrongGuesses}
     * Use checkWin() to determine if the game was won or not. 
     * If the game was won, calculate points as an int earned using the formula:
     *      100 - ((incorrect guesses)/(total guesses) * 100)
     * If the game was lost, set points to 0
     * 
     * @param userLetters Array of chars, contains '_' for unknown spaces, or the correct letter if it was guessed before
     * @param word The final word chosen for the game 
     * @param totalGuesses The total amount of guesses the user made
     * @param wrongGuesses The amount of incorrect guesses the user made
     * @param outputFile The name of the output file to print out to 
     */
public static void exportStats(char[] userLetters, char[] word, int totalGuesses, int wrongGuesses, String outputFile){
    boolean won = checkWin(userLetters);
    int points;
    if (won) {
        points = (int) (100 - ((double) wrongGuesses / totalGuesses) * 100);
    } else {
        points = 0;
    }

    StringBuilder sb = new StringBuilder();
    sb.append(won ? "You won\n" : "You lost\n");
    sb.append("Points: ").append(points).append("\n");
    sb.append("The word was: ").append(new String(word)).append("\n");
    sb.append("Total guesses: ").append(totalGuesses).append("\n");
    sb.append("Incorrect guesses: ").append(wrongGuesses).append("\n");

    StdOut.setFile(outputFile);
    StdOut.print(sb.toString());
}


    /**
     * Provided functionality to run the Hangman game
     * Use this to test your methods and play the game
     * @param args Command line arguments, args[0] is the input file name, args[1] is the output file name
     */
    public static void main(String[] args) {
        if(args.length != 2){
            StdOut.println("Incorrect number of command line arguments\nCorrect usage: java Hangman inputFileName outputFileName");
        }
        else{
            if(!Files.exists(Paths.get(args[0]))) {
                StdOut.println("The file " + args[0] + " was not found and might not exist, make sure you type the name of the file correcly");
            }
            else{
                String gameWord = new String(selectWord(args[0]));
                StdIn.resetFile();

                StdOut.println("The word contains " + gameWord.length() + " characters");

                boolean[] guessedLetters = new boolean[26];

                char[] userLetters = new char[gameWord.length()];
                for(int i = 0; i < userLetters.length; i++){
                    userLetters[i] = '_';
                }

                int totalGuesses = 0;
                int wrongGuesses = 0;

                boolean quit = false;

                while(wrongGuesses < 6){
                    StdOut.print("Enter a letter guess, or 0 to quit: ");
                    char inputChar = StdIn.readLine().charAt(0);
                    
                    if(inputChar == '0'){
                        quit = true;
                        break;
                    }

                    int validChar = validateChar(inputChar);

                    if(validChar == -1){
                        StdOut.println("The character " + inputChar + " is not a valid letter, please enter in a letter");
                    }
                    else{
                        char guess = (char) validChar;
                        if(markGuessed(guessedLetters, guess)){
                            totalGuesses++;
                            StdOut.println("You guessed " + guess);
                            if(checkLetter(userLetters, gameWord.toCharArray(), guess)){
                                StdOut.println(guess + " was in the word");
                                if(checkWin(userLetters)){
                                    break;
                                }
                            }
                            else{
                                wrongGuesses++;
                                StdOut.println(guess + " was not in the word");
                            }
                        }
                        else{
                            StdOut.println("You already guessed the letter " + guess + ", please enter another letter");
                        }
                    }

                    for(int i = 0; i < userLetters.length; i++){
                        StdOut.print(userLetters[i] + " ");
                    }
                    StdOut.print("\n\n");
                    
                    StdOut.println("Hangman character:");
                    StdOut.println(printHangman(wrongGuesses));
                }
                if(!quit){
                    StdOut.println("Printing stats to " + args[1] + "...");
                    exportStats(userLetters, gameWord.toCharArray(), totalGuesses, wrongGuesses, args[1]);
                }
                else{
                    StdOut.println("Program exited");
                }

            }
        }
    }

    /**
     * PROVIDED, used by the main method to accept or reject character input
     * Converts uppercase letters to lowercase
     * @param inputChar The input the user gave
     * @returns the ascii value of the lowercase letter, or -1 if invalid
     */
    public static int validateChar(char inputChar){
        int ascii = (int) inputChar;
        if(ascii >= 97 && ascii <= 122){
            return ascii;
        }
        else if(ascii >= 65 && ascii <= 90){
            return ascii + 32;
        }
        else{
            return -1;
        }
    }

    /**
     * PROVIDED, used by the main method to print out the hangman person
     * @param lives How many incorrect guesses the user has
     * @returns The string representation of the hangman person
     */
    public static String printHangman(int lives){
        return switch (lives) {
            case 0 -> """
                    
                    """;
            case 1 -> """
                    O
                    """;
            case 2 -> """
                    O
                    |
                    """;
            case 3 -> """
                    O
                    |\\
                    """;
            case 4 -> """
                    O
                   /|\\
                    """;
            case 5 -> """
                    O
                   /|\\
                   /
                    """;
            case 6 -> """
                    O
                   /|\\
                   / \\
                    """;
            default -> "";
        };

    }


}
