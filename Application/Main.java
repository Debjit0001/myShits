public class Main {
    public static void main(String[] args) {
        int[] salary = { 12433, 43, 634, 62533, 743546, 7232,3245 , 745757234 };
        System.out.println(average(salary));
    }

    static double average(int[] salary) {
        int max = (salary[0] > salary[1]) ? salary[0] : salary[1];
        int min = (salary[0] < salary[1]) ? salary[0] : salary[1];

        double sum = 0;

        for (int i = 2; i < salary.length; i++) {
            if (salary[i] > max) {
                sum += max;
                max = salary[i];
            }

            else if (salary[i] < min) {
                sum += min;
                min = salary[i];
            }

            else
                sum += salary[i];
        }

        return sum / (salary.length - 2);
    }
}