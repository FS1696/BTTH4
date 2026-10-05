#include "SalesEmployee.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

// Constructor rút gọn
SalesEmployee::SalesEmployee(
    const std::string& employeeId,
    const std::string& fullName)
    : SalesEmployee(
          employeeId,
          fullName,
          "Unassigned",
          0.0,
          0.0,
          0.0)
{
}

// Constructor đầy đủ
SalesEmployee::SalesEmployee(
    const std::string& employeeId,
    const std::string& fullName,
    const std::string& department,
    double baseSalary,
    double salesRevenue,
    double commissionRate)
    : Employee(employeeId, fullName, department),
      baseSalary(baseSalary),
      salesRevenue(salesRevenue),
      commissionRate(commissionRate)
{
    // Lương cơ bản không âm
    if (baseSalary < 0) {
        throw std::invalid_argument(
            "Luong co ban khong duoc am."
        );
    }

    // Doanh số không âm
    if (salesRevenue < 0) {
        throw std::invalid_argument(
            "Doanh so khong duoc am."
        );
    }

    // Tỷ lệ hoa hồng [0, 0.3]
    if (commissionRate < 0 || commissionRate > 0.3) {
        throw std::invalid_argument(
            "Hoa hong phai nam trong [0, 0.3]."
        );
    }
}

// Công thức:
// grossPay = baseSalary
//          + salesRevenue * commissionRate
//          + monthlyBonus
double SalesEmployee::calculateGrossPay() const
{
    return baseSalary
         + salesRevenue * commissionRate
         + monthlyBonus;
}

// Loại nhân viên
std::string SalesEmployee::getEmployeeType() const
{
    return "SalesEmployee";
}

// Hiển thị thông tin
void SalesEmployee::displayPayrollInfo() const
{
    std::cout << std::fixed << std::setprecision(0)

              << getEmployeeType()
              << " | " << employeeId
              << " | " << fullName
              << " | " << department
              << " | Base: " << baseSalary
              << " | Sales: " << salesRevenue
              << " | Commission: "
              << commissionRate * 100 << "%"
              << " | Thuong: " << monthlyBonus
              << " | Gross: "
              << calculateGrossPay()

              << '\n';
}

// Cập nhật doanh số
void SalesEmployee::updateSalesRevenue(
    double newSalesRevenue)
{
    if (newSalesRevenue < 0) {
        throw std::invalid_argument(
            "Doanh so moi khong duoc am."
        );
    }

    salesRevenue = newSalesRevenue;
}
