import java.util.*;

/*
 * The Driver class is used to test the Company and Person methods
 * for the biometric fingerprint authentication system.
 * 
 * Provides an interactive menu-driven interface for managing employees,
 * running authentication reports, and testing fingerprint matching.
 * 
 * @author Juliania Shyprykevych
 * @author Maaz Mansuri
 */
public class Driver {

    public static Company company = new Company();
    public static ArrayList<Employee> employeeList = company.getEmployeeList();

    /*
     * Main method that provides an interactive menu system for testing
     * the biometric fingerprint authentication system.
     * 
     * First allows user to onboard employees from a CSV file, then provides
     * options for running reports, analyzing security, logging in employees,
     * viewing account information, and adding new employees.
     * 
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {
        // Menu options for initial setup and main operations
        String[] startingOptions = new String[]{"Onboard employees through CSV", "Onboard employees individually", "Quit"};
        String[] secondOptions = new String[]{"Add Employee", "Authenticate Employee", "Test Authentication Robustness", "Show Company Account Information", "Show Personal Account", "Quit"};

        // Control variables for menu flow and threshold memory
        boolean companyOnboarded = false;
        boolean quit = false;

        do { // Initial setup loop - requires employee onboarding before main features
            System.out.println("\nWhat would you like to do?");
            for (int i = 0; i < startingOptions.length; i++) {
                System.out.println(i + 1 + ": " + startingOptions[i]);
            }
            System.out.print("Select option > ");
            String firstChoiceStr = StdIn.readLine();
            if (firstChoiceStr != "") {
                int firstChoice = Integer.parseInt(firstChoiceStr);
                switch (firstChoice) {
                    case 1: // Onboard employees through CSV
                        System.out.print("enter company csv you wish to onboard > ");
                        String companyCSV = StdIn.readLine();
                        if (companyCSV != "") {
                            StdIn.setFile(companyCSV);
                            String[] employeeFiles = StdIn.readLine().split(",");
                            StdIn.resetFile();
                            StdIn.resync();
                            for (String filenametxt : employeeFiles) {
                                if (company.onboardEmployee(filenametxt)) {
                                    companyOnboarded = true;
                                } else if (!company.onboardEmployee(filenametxt)) {
                                    System.out.println("You already added this employee.");
                                }
                                StdIn.resync();
                            }
                        }
                        break;

                    case 2: // Onboard employees invididually
                        String filenametxt = null;
                        do {
                            System.out.print("enter employee file (if you do not wish to log anyone else in, press enter) > ");
                            filenametxt = StdIn.readLine();
                            if (filenametxt != "") {
                                if (company.onboardEmployee(filenametxt)) {
                                    companyOnboarded = true;
                                } else if (!company.onboardEmployee(filenametxt)) {
                                    System.out.println("You already added this employee.");
                                }
                                StdIn.resync();
                            }
                        } while (filenametxt != "");
                        break;

                    case 3: // Exit program
                        company.quit();
                        quit = true;
                        return;

                    default:
                        System.out.println("\nSorry that's not an option");
                        break;
                }
            } else {
                System.out.println("You must choose an option!");
            }
        } while (!companyOnboarded);

        do { // Main menu loop - provides full functionality after onboarding
            System.out.println("\nWhat would you like to do now that the company is onboarded?");
            for (int i = 0; i < secondOptions.length; i++) {
                System.out.println(i + 1 + ": " + secondOptions[i]);
            }
            System.out.print("Select option > ");
            StdIn.resync();
            int secondChoice = Integer.parseInt(StdIn.readLine());
            StdIn.resync();
            switch (secondChoice) {
                case 1: // Add new employee to company database
                    System.out.print("Person's file name > ");
                    String newPersonFile = StdIn.readLine();
                    StdIn.resync();
                    Employee newPerson = company.createEmployee(newPersonFile); // create Employee from file
                    StdIn.resync();
                    StdIn.resetFile();

                    // Attempt to add employee (prevents duplicates)
                    if (company.onboardEmployee(newPersonFile)) {
                        System.out.println("\nWelcome " + newPerson.getFirstName());
                        StdIn.resync();
                    } else {
                        System.out.println("\nYou already added this employee.");
                    }
                    break;

                case 2: // Authenticate a single employee login attempt
                    System.out.print("Person's file name > ");
                    String personLogin = StdIn.readLine();
                    Employee personToLogin = company.createEmployee(personLogin);
                    StdIn.resync();
                    System.out.print("Threshold of error (numbers 1-100) > ");
                    int loginThreshold = Integer.parseInt(StdIn.readLine());
                    StdIn.resync();

                    if (personToLogin.getLoggedIn()) { // Employee already logged in
                        System.out.println("\nThis employee is already logged in");
                    } else {
                        LoginCredentials loginCredentialsToLogin = new LoginCredentials(personToLogin.getID(), personToLogin.getFingerprint());

                        if (company.authenticate(loginCredentialsToLogin, loginThreshold)) { // Successful login
                            System.out.println("\nHello " + personToLogin.getFirstName() + "! You are a " + personToLogin.getLevelOfSecurity() + " employee.");
                        } else if (!company.authenticate(loginCredentialsToLogin, loginThreshold)) { // Unsuccessful login
                            System.out.println("\nSorry we were not able to log the user in");
                        }
                    }
                    break;

                case 3: // Test robustness against one employee
                    System.out.println("\nPart 1 is inputting the login file that will simulate multiple attempts to log in employees");
                    System.out.print("Login file (HackAttempts#.txt) > ");
                    String loginAttemptFile = StdIn.readLine();
                    StdIn.resync();
                    System.out.println("\nPart 2 is inputting the authentication threshold");
                    System.out.print("Threshold of error (numbers 1-100) > ");
                    int testThreshold = Integer.parseInt(StdIn.readLine());
                    StdIn.resync();

                    // Parse login attempt file into ArrayList for processing
                    ArrayList<String> loginAttemptListString = new ArrayList<String>();
                    StdIn.setFile(loginAttemptFile);
                    while (StdIn.hasNextLine()) {
                        loginAttemptListString.add(StdIn.readLine());
                    }
                    StdIn.resetFile();
                    StdIn.resync();

                    // Create Login Credentials for each login attempt in the attempts file
                    ArrayList<LoginCredentials> loginAttemptArrayList = new ArrayList<>();
                    for (String personFile : loginAttemptListString) {
                        Employee employee = company.createEmployee(personFile);
                        loginAttemptArrayList.add(new LoginCredentials(employee.getID(), employee.getFingerprint()));
                    }
                    Employee hackedEmployee = new Employee(0, null, null, 0.0,null, null);
                    for (Employee employee : employeeList){
                        if (employee.getID() == loginAttemptArrayList.get(0).getID()){
                            hackedEmployee = employee;
                            break;
                        }
                    }
                    int numLoginSuccesses = company.testAuthenticationRobustness(loginAttemptArrayList, testThreshold);
                    System.out.print("\nYou were able to hack into " + hackedEmployee.getFirstName().strip() + "'s account " + numLoginSuccesses + " number of times.\n");
                    StdIn.resync();
                    break;

                case 4: // Generate comprehensive company information report
                    StdOut.setFile("CompanyInformation.out");
                    company.getImageToString(); // outputs all employee data with fingerprints
                    System.out.println("\nCheck your files for the output file - CompanyInformation.out.");
                    System.out.print("\nList of current employees:");
                    for (Employee employee : employeeList) {
                        System.out.print("\n  " + employee.getFirstName() + " " + employee.getLastName().strip());
                    }
                    System.out.println();
                    StdOut.resetFile();
                    StdIn.resync();
                    break;

                case 5: // Generate individual employee information report
                    System.out.println("\nWhich employee would you like to see the report for?");

                    // Display numbered list of all employees
                    for (int i = 0; i < employeeList.size(); i++) {
                        System.out.println(i + 1 + ": " + employeeList.get(i).getFirstName() + " " + employeeList.get(i).getLastName());
                    }
                    System.out.print("Employee number > ");
                    int informationIndex = Integer.parseInt(StdIn.readLine()) - 1; // convert to 0-based index

                    // Validate selection and generate individual report
                    if (informationIndex >= employeeList.size()) {
                        System.out.println("\nNumber out of bounds.");
                    } else {
                        String informationEmployeeFirst = employeeList.get(informationIndex).getFirstName();
                        String informationEmployeeLast = employeeList.get(informationIndex).getLastName();
                        StdOut.setFile(informationEmployeeFirst + informationEmployeeLast + "AccountInformation.out");
                        int employeeID = company.createEmployee(informationEmployeeFirst + "0.txt").getID();
                        company.getImageToString(employeeID); // output specific employee data
                        StdOut.resetFile();
                        StdIn.resync();
                        System.out.println("\nCheck your files for the output file - " + informationEmployeeFirst + informationEmployeeLast + "Information.out");
                        StdOut.resetFile();
                    }
                    break;

                case 6: // Exit program
                    company.quit();
                    quit = true;
                    return;

                default:
                    System.out.println("\nSorry that's not an option");
                    break;
            }
        } while (companyOnboarded && !quit);
    }
}