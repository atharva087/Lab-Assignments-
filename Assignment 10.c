#include <stdio.h>

int isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

/* Returns the weekday for a date: 0 = Sunday, ..., 6 = Saturday. */
int getWeekday(int year, int month, int day) {
    static const int offsets[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    if (month < 3) {
        year--;
    }

    return (year + year / 4 - year / 100 + year / 400
            + offsets[month - 1] + day) % 7;
}

int main(void) {
    const char *months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };
    const int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int year;

    printf("Enter year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Please enter a valid year greater than 0.\n");
        return 1;
    }

    for (int month = 1; month <= 12; month++) {
        int totalDays = daysInMonth[month - 1];
        if (month == 2 && isLeapYear(year)) {
            totalDays = 29;
        }

        printf("\n      %s %d\n", months[month - 1], year);
        printf(" Su Mo Tu We Th Fr Sa\n");

        int startDay = getWeekday(year, month, 1);
        for (int i = 0; i < startDay; i++) {
            printf("   ");
        }

        for (int day = 1; day <= totalDays; day++) {
            printf("%3d", day);
            if ((startDay + day) % 7 == 0) {
                printf("\n");
            }
        }

        if ((startDay + totalDays) % 7 != 0) {
            printf("\n");
        }
    }

    return 0;
}