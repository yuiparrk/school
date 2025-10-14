public class HealthMonitor {
    public static void main(String args[]) {
        double age = Double.parseDouble(args[0]);
        double sleepDuration = Double.parseDouble(args[1]);
        double qualityOfSleep = Double.parseDouble(args[2]);
        double physicalActivityLevel = Double.parseDouble(args[3]);
        double stressLevel = Double.parseDouble(args[4]);
        double heartRate = Double.parseDouble(args[5]);
        double dailySteps = Double.parseDouble(args[6]);

        char bmiCategory = args[7].charAt(0);
        char bloodPressure = args[8].charAt(0);
        char sleepDisorder = args[9].charAt(0);

        age = ((100 - age)/10) * 0.10;
        sleepDuration = (sleepDuration % 8) * 0.10;
        qualityOfSleep = qualityOfSleep * 0.10;
        physicalActivityLevel = (physicalActivityLevel/10) * 0.10;
        stressLevel = (10 - stressLevel) * 0.10;

        if (heartRate >= 60 && heartRate <= 100) {
            heartRate = 10 * 0.10;
        } else if (heartRate < 60) {
            heartRate = 7 * 0.10;
        } else {
            heartRate = 5 * 0.10;
        }
        
        dailySteps = ((dailySteps/8000) * 10) * 0.05;

 


    }
}
