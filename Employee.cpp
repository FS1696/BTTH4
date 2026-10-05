#include "Employee.h"
#include <stdexcept>

// Constructor rút gọn
Employee::Employee(const std::string& employeeId,
                   const std::string& fullName)
    : Employee(employeeId, fullName, "Unassigned")
{
}

// Constructor đầy đủ
Employee::Employee(const std::string& employeeId,
                   const std::string& fullName,
                   const std::string& department)
    : employeeId(employeeId),
      fullName(fullName),
      department(department),
      monthlyBonus(0.0)
{
    // Kiểm tra mã nhân sự
    if (employeeId.empty()) {
        throw std::invalid_argument(
            "Ma nhan su khong duoc rong."
        );
    }

    // Kiểm tra họ tên
    if (fullName.empty()) {
        throw std::invalid_argument(
            "Ho ten khong duoc rong."
        );
    }

    // Kiểm tra phòng ban
    if (department.empty()) {
        throw std::invalid_argument(
            "Phong ban khong duoc rong."
        );
    }
}

// addBonus(amount)
void Employee::addBonus(double amount)
{
    if (amount <= 0) {
        throw std::invalid_argument(
            "Khoan thuong phai > 0."
        );
    }

    monthlyBonus += amount;
}

// addBonus(amount, reason)
void Employee::addBonus(double amount,
                         const std::string& reason)
{
    if (amount <= 0) {
        throw std::invalid_argument(
            "Khoan thuong phai > 0."
        );
    }

    if (reason.empty()) {
        throw std::invalid_argument(
            "Ly do thuong khong duoc rong."
        );
    }

    monthlyBonus += amount;
}

// addBonus(rate, referenceAmount, reason)
void Employee::addBonus(double rate,
                         double referenceAmount,
                         const std::string& reason)
{
    if (rate <= 0 || rate > 0.5) {
        throw std::invalid_argument(
            "Ty le thuong phai > 0 va <= 0.5."
        );
    }

    if (referenceAmount <= 0) {
        throw std::invalid_argument(
            "Gia tri tham chieu phai > 0."
        );
    }

    if (reason.empty()) {
        throw std::invalid_argument(
            "Ly do thuong khong duoc rong."
        );
    }

    monthlyBonus += rate * referenceAmount;
}

// Reset thưởng
void Employee::resetBonus()
{
    monthlyBonus = 0.0;
}

// Getter mã nhân viên
const std::string& Employee::getEmployeeId() const
{
    return employeeId;
}

// Getter họ tên
const std::string& Employee::getFullName() const
{
    return fullName;
}

// Getter phòng ban
const std::string& Employee::getDepartment() const
{
    return department;
}

// Getter thưởng
double Employee::getMonthlyBonus() const
{
    return monthlyBonus;
}
