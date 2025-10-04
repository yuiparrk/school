public class RUChange {
    public static void main(String[] args) {
        int quarter = 0;
        int dime = 0;
        int nickel = 0;
        int penny = 0;

        int input = Integer.parseInt(args[0]);

        if (input < 0) {
            System.out.println("Invalid Input!");
        } else {
        while (input > 0) {
            if (input >= 25) {
                input -= 25;
                quarter++;
            } else if (input >= 10) {
                input -= 10;
                dime++;
            } else if (input >= 5) {
                input -= 5;
                nickel++;
            } else if (input >= 1) {
                input -= 1;
                penny++;
            }
        }
        System.out.println("Quarters: " + quarter + " Dimes: " + dime + " Nickels: " + nickel + " Pennies: " + penny);
    }
        }

}
