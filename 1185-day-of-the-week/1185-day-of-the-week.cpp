class Solution {
public:

    int dayOfWeek(int d, int m, int y) {
        int days = 0;

        for (int year = 1970; year < y; year++) {
            bool leap = (year % 400 == 0) ||
                        (year % 4 == 0 && year % 100 != 0);

            days += leap ? 366 : 365;
        }

        int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        bool leap = (y % 400 == 0) ||
                    (y % 4 == 0 && y % 100 != 0);

        if (leap)
            monthDays[1] = 29;

        for (int month = 1; month < m; month++)
            days += monthDays[month - 1];

        days += d - 1;

        return days % 7;
    }

    // Your main LeetCode function
    string dayOfTheWeek(int day, int month, int year) {

        int result = dayOfWeek(day, month, year);

        string week[] = {
            "Thursday",
            "Friday",
            "Saturday",
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday"
        };

        return week[result];
    }
};