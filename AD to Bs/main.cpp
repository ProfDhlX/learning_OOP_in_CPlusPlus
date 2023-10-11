#include <iostream>
using namespace std;

class NepaliDate {
private:
    int yearBS;
    int monthBS;
    int dayBS;
    int yearAD;
    int monthAD;
    int dayAD;

    // Array of days in a month for AD and BS
    int daysInMonthAD[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInMonthBS[12] = {30, 30, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30};

    // Constants for AD to BS conversion
    int AD_START_YEAR = 1943;
    int BS_START_YEAR = 2000;
    int AD_START_MONTH = 4;
    int AD_START_DAY = 13;

public:
    // Constructor to initialize the NepaliDate object
    NepaliDate(int year, int month, int day, bool isBS) {
        if (isBS) {
            yearBS = year;
            monthBS = month;
            dayBS = day;
            convertBSToAD();
        } else {
            yearAD = year;
            monthAD = month;
            dayAD = day;
            convertADToBS();
        }
    }

    // Function to convert BS to AD
    void convertBSToAD() {
        int bsYearDays = 0;
        for (int i = 0; i < yearBS - BS_START_YEAR; i++) {
            bsYearDays += 365;
            for (int j = 0; j < 12; j++) {
                bsYearDays += daysInMonthBS[j];
            }
        }
        for (int i = 0; i < monthBS - 1; i++) {
            bsYearDays += daysInMonthBS[i];
        }
        bsYearDays += dayBS;

        int adYearDays = bsYearDays + (AD_START_YEAR - BS_START_YEAR) * 365;
        int adMonthDays = 0;
        for (int i = 0; i < 12; i++) {
            adMonthDays += daysInMonthAD[i];
            if (i < AD_START_MONTH - 1) {
                if (i == 1 && isLeapYear(AD_START_YEAR)) {
                    adMonthDays++;
                }
            }
        }
        adMonthDays -= AD_START_DAY;

        yearAD = AD_START_YEAR;
        while (adYearDays >= 365) {
            int daysInYear = isLeapYear(yearAD) ? 366 : 365;
            if (adYearDays < daysInYear) {
                break;
            }
            adYearDays -= daysInYear;
            yearAD++;
        }

        for (int i = 0; i < 12; i++) {
            int daysInMonth = daysInMonthAD[i];
            if (i == 1 && isLeapYear(yearAD)) {
                daysInMonth++;
            }
            if (adYearDays < daysInMonth) {
                monthAD = i + 1;
                dayAD = adYearDays + 1;
                break;
            }
            adYearDays -= daysInMonth;
        }
    }

    // Function to convert AD to BS
    void convertADToBS() {
        int adYearDays = 0;
        for (int i = AD_START_YEAR; i < yearAD; i++) {
            adYearDays += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 0; i < monthAD - 1; i++) {
            adYearDays += daysInMonthAD[i];
            if (i == 1 && isLeapYear(yearAD)) {
                adYearDays++;
            }
        }
        adYearDays += dayAD;

        yearBS = BS_START_YEAR;
        int bsMonthDays = 0;
        int daysInYear = isLeapYear(yearBS) ? 366 : 365;
        while (adYearDays >= daysInYear) {
            adYearDays -= daysInYear;
            yearBS++;
            daysInYear = isLeapYear(yearBS) ? 366 : 365;
        }
        for (int i = 0; i < 12; i++) {
            bsMonthDays += daysInMonthBS[i];
            if (i == 1 && isLeapYear(yearBS)) {
                bsMonthDays++;
            }
            if (adYearDays < bsMonthDays) {
                monthBS = i + 1;
                dayBS = adYearDays + 1;
                break;
            }
            adYearDays -= bsMonthDays;
        }
    }

    // Function to check if a year is a leap year
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // Function to print the converted date in BS
    void printDateBS() {
        cout << "Nepali Date: " << yearBS << "-" << monthBS << "-" << dayBS << endl;
    }

    // Function to print the converted date in AD
    void printDateAD() {
        cout << "Gregorian Date: " << yearAD << "-" << monthAD << "-" << dayAD << endl;
    }
};

int main() {
    // Example usage to convert AD to BS and vice versa
    NepaliDate date1(2079, 1, 1, true); // Convert BS to AD
    date1.printDateAD();

    NepaliDate date2(2022, 4, 13, false); // Convert AD to BS
    date2.printDateBS();

    return 0;
}
