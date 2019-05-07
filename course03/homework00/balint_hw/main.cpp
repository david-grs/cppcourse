#include <iostream>

class Date {
private:
  int y, m, d;

  bool yearvalid() const { return y >= 1600 && y <= 2500; }

  bool monthvalid() const { return m >= 1 && m <= 12; }
  static bool isleapyear(int y) {
    if (y % 4 != 0) {
      return false;
    }
    if (y % 100 != 0) {
      return true;
    }
    if (y % 400 != 0) {
      return false;
    }
    return true;
  }
  int maxDayInMonth(int y, int m) const {
    switch (m) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    case 2:
      return isleapyear(y) ? 29 : 28;
    default:
      throw std::runtime_error("Invalid month value");
    };
  }
  int dayDiff(Date first, Date second) const {
    if (first == second) {
      return 0;
    }
    if (!(first < second)) {
      return -1 * dayDiff(second, first);
    }

    Date dayCnt = first.nextDay();
    int cnt = 1;
    while (dayCnt < second) {
      cnt++;
      dayCnt = dayCnt.nextDay();
    }
    return cnt;
  }

public:
  Date(int y, int m, int d) : y(y), m(m), d(d){};
  Date nextDay() const {
    Date firstguess = {y, m, d + 1};
    if (!firstguess.isValid()) {
      firstguess = {y, m + 1, 1};
      if (!firstguess.isValid()) {
        firstguess = {y + 1, 1, 1};
      }
    }
    return firstguess;
  }
  bool isValid() const {
    if (!yearvalid() || !monthvalid()) {
      return false;
    }
    if (d < 1 || d > maxDayInMonth(y, m)) {
      return false;
    }
    return true;
  }
  int getY() const { return y; }
  int getM() const { return m; }
  int getD() const { return d; }

  bool operator==(const Date &other) const {
    return std::tie(y, m, d) == std::tie(other.y, other.m, other.d);
  }
  bool operator<(const Date &other) const {
    return std::tie(y, m, d) < std::tie(other.y, other.m, other.d);
  }
  int daysSinceEpoch() const { return dayDiff({1970, 1, 1}, *this); }

  std::string dayOfWeek() const {
    if (!isValid()) {
      throw std::runtime_error("dayOfWeek() called while !isValid()");
    }
    int offset = (((daysSinceEpoch() % 7) + 7) % 7);
    switch (offset) {
    case 0:
      return "Thursday";
    case 1:
      return "Friday";
    case 2:
      return "Saturday";
    case 3:
      return "Sunday";
    case 4:
      return "Monday";
    case 5:
      return "Tuesday";
    case 6:
      return "Wednesday";
    default:
      throw std::logic_error("Shouldn't happen");
    }
  }
};
std::ostream &operator<<(std::ostream &strm, const Date &a) {
  return strm << a.getY() << "-" << a.getM() << "-" << a.getD();
}

int main() {

  Date test2 = {2019, 5, 5};

  std::cout << "Nr of days since epoch is: " << test2.daysSinceEpoch()
            << std::endl;
  std::cout << "Day of week is : " << test2.dayOfWeek() << std::endl;

  return 0;
}
