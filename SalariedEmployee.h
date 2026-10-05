#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H

#include "Employee.h"

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

class SalariedEmployee : public Employee {
private:
    double monthlySalary;
    double responsibilityAllowance;

public:
    // Constructor rút gọn
    SalariedEmployee(const std::string& employeeId,
                     const std::string& fullName);

    // Constructor đầy đủ
    SalariedEmployee(const std::string& employeeId,
                     const std::string& fullName,
                     const std::string& department,
                     double monthlySalary,
                     double responsibilityAllowance);

    // Ghi đè phương thức của Employee
    double calculateGrossPay() const override;

    std::string getEmployeeType() const override;

    void displayPayrollInfo() const override;
};

#endif
