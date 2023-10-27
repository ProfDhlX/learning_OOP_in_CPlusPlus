#include <iostream>
#include <sstream>
using namespace std;

//creating class for nepalidate conversion.
class NepaliDate {
private:
    int yearBS;
    int monthBS;
    int dayBS;
    int yearAD;
    int monthAD;
    int dayAD;

    int daysInMonthAD[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysInMonthBS[12] = {30, 30, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30};
    int AD_START_YEAR = 1943;
    int BS_START_YEAR = 2000;
    int AD_START_MONTH = 4;
    int AD_START_DAY = 13;

public:
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

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    void convertBSToAD() {
        int bsYearDays = 0;
        for (int i = BS_START_YEAR; i < yearBS; i++) {
            bsYearDays += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 0; i < monthBS - 1; i++) {
            bsYearDays += daysInMonthBS[i];
        }
        bsYearDays += dayBS;

        int adYearDays = bsYearDays + (AD_START_YEAR - BS_START_YEAR) * 365;
        int adMonthDays = 0;
        for (int i = 0; i < 12; i++) {
            adMonthDays += daysInMonthAD[i];
            if (i == 1 && isLeapYear(AD_START_YEAR)) {
                adMonthDays++;
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

    void printDateBS() {
        cout << "Nepali Date (BS): " << yearBS << "-" << monthBS << "-" << dayBS << endl;
    }

    void printDateAD() {
        cout << "Gregorian Date (AD): " << yearAD << "-" << monthAD << "-" << dayAD << endl;
    }

    void userInputAndConvert() {
        char choice;
        cout << "Enter 'A' to convert from AD to BS, or 'B' to convert from BS to AD: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            string inputDate;
            cout << "Enter a date in AD format (dd/mm/yyyy): ";
            cin >> inputDate;
            istringstream iss(inputDate);
            int day, month, year;
            char delimiter;
            iss >> day >> delimiter >> month >> delimiter >> year;

            yearAD = year;
            monthAD = month;
            dayAD = day;

            convertADToBS();
            printDateBS();
        } else if (choice == 'B' || choice == 'b') {
            string inputDate;
            cout << "Enter a date in BS format (dd/mm/yyyy): ";
            cin >> inputDate;
            istringstream iss(inputDate);
            int day, month, year;
            char delimiter;
            iss >> day >> delimiter >> month >> delimiter >> year;

            yearBS = year;
            monthBS = month;
            dayBS = day;

            convertBSToAD();
            printDateAD();
        } else {
            cout << "Invalid choice. Please enter 'A' or 'B." << endl;
        }
    }
};

int main() {
    NepaliDate dateConverter;

    dateConverter.userInputAndConvert();

    return 0;
}