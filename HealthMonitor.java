/**
 * Health Monitor has students implement 1D arrays as a way to store and analyze
 * a patient's health metrics.
 * The overall goal is to determine whether the patient is healthy by
 * calculating their Health Score,
 * and comparing it to predetermined ranges.
 * Write the HealthMonitor program inside the main method as per the assignment
 * description.
 *
 * Input Format:
 * | Age | Sleep Duration | Quality of Sleep | Physical Activity Level | Stress
 * Level | Heart Rate | Daily Steps | Sex | BMI | BP | Sleep Disorder |
 *
 * Compilation: javac healthMonitor.java
 * Execution: java healthMonitor <input metrics>
 *
 * @author Isha Gajera
 * @author Anna Lu
 */
public class HealthMonitor {
    public static void main(String[] args) {
        // WRITE YOUR CODE HERE
        double age = Double.parseDouble(args[0]);
        double sleepDuration = Double.parseDouble(args[1]);
        double qualityOfSleep = Double.parseDouble(args[2]);
        double physicalActivityLevel = Double.parseDouble(args[3]);
        double stressLevel = Double.parseDouble(args[4]);
        double heartRate = Double.parseDouble(args[5]);
        double dailySteps = Double.parseDouble(args[6]);

        char sex = args[7].charAt(0);
        char bmiCategory = args[8].charAt(0);
        char bloodPressure = args[9].charAt(0);
        char sleepDisorder = args[10].charAt(0);

        age = ((100 - age) / 10) * 0.10;
        sleepDuration = (sleepDuration % 8) * 0.10;
        qualityOfSleep = qualityOfSleep * 0.10;
        physicalActivityLevel = (physicalActivityLevel / 10) * 0.10;
        stressLevel = (10 - stressLevel) * 0.10;

        if (heartRate >= 60 && heartRate <= 100) {
            heartRate = 10 * 0.10;
        } else if (heartRate < 60) {
            heartRate = 7 * 0.10;
        } else {
            heartRate = 5 * 0.10;
        }

        dailySteps = ((dailySteps / 8000) * 10) * 0.05;

        double bmiNumber;
        if (bmiCategory == 'N') {
            bmiNumber = 10.0;
        } else if (bmiCategory == 'O') {
            bmiNumber = 7.0;
        } else if (bmiCategory == 'U') {
            bmiNumber = 5.0;
        } else {
            bmiNumber = 3.0;
        }
        bmiNumber = bmiNumber * 0.15;

        double bloodPressureNumber;
        if (bloodPressure == 'N') {
            bloodPressureNumber = 10.0;
        } else if (bloodPressure == 'E') {
            bloodPressureNumber = 7.0;
        } else if (bloodPressure == 'O') {
            bloodPressureNumber = 5.0;
        } else {
            bloodPressureNumber = 3.0;
        }
        bloodPressureNumber = bloodPressureNumber * 0.10;

        double sleepDisorderNumber;
        if (sleepDisorder == 'N') {
            sleepDisorderNumber = 10.0;
        } else if (sleepDisorder == 'A') {
            sleepDisorderNumber = 5.0;
        } else {
            sleepDisorderNumber = 3.0;
        }
        sleepDisorderNumber = sleepDisorderNumber * 0.10;

double sum = age + sleepDuration + qualityOfSleep + physicalActivityLevel + stressLevel + heartRate 
           + dailySteps + bmiNumber + bloodPressureNumber + sleepDisorderNumber;

String healthStatus;
if (sex == 'M') {
    if (sum > 7.5)
        healthStatus = "healthy";
    else if (sum >= 6.5)
        healthStatus = "average";
    else
        healthStatus = "unhealthy";
} else {
    if (sum > 7.0)
        healthStatus = "healthy";
    else if (sum >= 6.0)
        healthStatus = "average";
    else 
        healthStatus = "unhealthy";
}
                System.out.printf("Patient's health score of %.4f is %s.%n", sum, healthStatus);
    }
}
