#include "SalariedEmployee.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

// Constructor rút gọn
SalariedEmployee::SalariedEmployee(
    const std::string& employeeId,
    const std::string& fullName)
    : SalariedEmployee(
          employeeId,
          fullName,
          "Unassigned",
          0.0,
          0.0)
{
}

// Constructor đầy đủ
SalariedEmployee::SalariedEmployee(
    const std::string& employeeId,
    const std::string& fullName,
    const std::string& department,
    double monthlySalary,
    double responsibilityAllowance)
    : Employee(employeeId, fullName, department),
      monthlySalary(monthlySalary),
      responsibilityAllowance(responsibilityAllowance)
{
    // Lương không được âm
    if (monthlySalary < 0) {
        throw std::invalid_argument(
            "Luong thang khong duoc am."
        );
    }

    // Phụ cấp không được âm
    if (responsibilityAllowance < 0) {
        throw std::invalid_argument(
            "Phu cap khong duoc am."
        );
    }
}

// Công thức:
// grossPay = monthlySalary
//          + responsibilityAllowance
//          + monthlyBonus
double SalariedEmployee::calculateGrossPay() const
{
    return monthlySalary
         + responsibilityAllowance
         + monthlyBonus;
}

// Trả về loại nhân viên
std::string SalariedEmployee::getEmployeeType() const
{
    return "SalariedEmployee";
}

// Hiển thị thông tin bảng lương
void SalariedEmployee::displayPayrollInfo() const
{
    std::cout << std::fixed << std::setprecision(0)

              << getEmployeeType()
              << " | " << employeeId
              << " | " << fullName
              << " | " << department
              << " | Luong: " << monthlySalary
              << " | PC: " << responsibilityAllowance
              << " | Thuong: " << monthlyBonus
              << " | Gross: "
              << calculateGrossPay()

              << '\n';
}
