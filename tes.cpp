#include <iostream>
#include <vector>
#include <algorithm>

struct Date {
    int day;
    int month;
    int year;
};

bool compareDates(const Date& date1, const Date& date2) {
    if (date1.year != date2.year)
        return date1.year < date2.year;
    if (date1.month != date2.month)
        return date1.month < date2.month;
    return date1.day < date2.day;
}

int main() {
    int n;
    std::cout << "Masukkan jumlah tanggal: ";
    std::cin >> n;

    std::vector<Date> dates;
    for (int i = 0; i < n; i++) {
        Date date;
        std::cout << "Masukkan tanggal ke-" << i + 1 << " (dd mm yyyy): ";
        std::cin >> date.day >> date.month >> date.year;
        dates.push_back(date);
    }

    std::sort(dates.begin(), dates.end(), compareDates);

    std::cout << "Tanggal setelah diurutkan:\n";
    for (const auto& date : dates) {
        std::cout << date.day << " " << date.month << " " << date.year << std::endl;
    }

    return 0;
}
