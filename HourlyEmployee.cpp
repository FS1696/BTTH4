#include "HourlyEmployee.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

/**************************************************
 * Mã sinh viên: [ĐIỀN MÃ SINH VIÊN]
 * Họ tên:      [ĐIỀN HỌ TÊN]
 **************************************************/

// Constructor rút gọn
HourlyEmployee::HourlyEmployee(
    const std::string& employeeId,
    const std::string& fullName)
    : HourlyEmployee(
          employeeId,
          fullName,
          "Unassigned",
          0.0,
          0.0)
{
}

// Constructor đầy đủ
HourlyEmployee::HourlyEmployee(
    const std::string& employeeId,
    const std::string& fullName,
    const std::string& department,
    double hourlyRate,
    double workedHours)
    : Employee(employeeId, fullName, department),
      hourlyRate(hourlyRate),
      workedHours(workedHours)
{
    // Đơn giá giờ không được âm
    if (hourlyRate < 0) {
        throw std::invalid_argument(
            "Don gia gio khong duoc am."
        );
    }

    // Số giờ làm phải nằm trong [0, 250]
    if (workedHours < 0 || workedHours > 250) {
        throw std::invalid_argument(
            "So gio lam phai nam trong [0, 250]."
        );
    }
}

// Tính thu nhập
double HourlyEmployee::calculateGrossPay() const
{
    double basePay;

    // Không vượt 160 giờ
    if (workedHours <= 160) {

        basePay = workedHours * hourlyRate;

    }
    // Có giờ vượt 160
    else {

        basePay =
            160 * hourlyRate
            + (workedHours - 160)
              * hourlyRate
              * 1.5;
    }

    return basePay + monthlyBonus;
}

// Loại nhân viên
std::string HourlyEmployee::getEmployeeType() const
{
    return "HourlyEmployee";
}

// Hiển thị thông tin
void HourlyEmployee::displayPayrollInfo() const
{
    std::cout << std::fixed << std::setprecision(0)

              << getEmployeeType()
              << " | " << employeeId
              << " | " << fullName
              << " | " << department
              << " | Rate: " << hourlyRate
              << " | Gio: " << workedHours
              << " | Thuong: " << monthlyBonus
              << " | Gross: "
              << calculateGrossPay()

              << '\n';
}
