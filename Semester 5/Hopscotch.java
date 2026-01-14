public class Hopscotch {
    public static void main(String[] args) {
        int input = Integer.parseInt(args[0]);

        for (int i = 1; i <= input; i+= 3) {
            System.out.print(i + " ");
        }

                for (int i = 2; i <= input; i+= 3) {
            System.out.print(i + " ");
        }

                for (int i = 3; i <= input; i+= 3) {
            System.out.print(i + " ");
        }
    }
}
