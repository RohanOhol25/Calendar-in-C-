#include <stdio.h>

// leap year function 
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return 1;
    return 0;
}
// Days in month function 
int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}
// Starting day Function 
int getStartingDay(int year) {
    int startDay = 1; 
    int days = 0;

    for (int i = 1900; i < year; i++) {
        days += isLeapYear(i) ? 366 : 365;
    }

    return (startDay + days) % 7;
}
//  Calendar print function
void printCalendar(int month, int year) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    const char *daysOfWeek = "Sun Mon Tue Wed Thu Fri Sat";

    int daysInMonth = getDaysInMonth(month, year);
    int startingDay = getStartingDay(year);

    for (int i = 1; i < month; i++) {
        startingDay = (startingDay + getDaysInMonth(i, year)) % 7;
    }

    printf("\n    %s %d\n", months[month - 1], year);
    printf("%s\n", daysOfWeek);

    for (int i = 0; i < startingDay; i++) {
        printf("    ");
    }

    for (int day = 1; day <= daysInMonth; day++) {
        printf("%3d ", day);
        if ((startingDay + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid input! Please enter a valid month (1-12) and year.\n");
        return 1;
    }

    printCalendar(month, year);

    return 0;
}