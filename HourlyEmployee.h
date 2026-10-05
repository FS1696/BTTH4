#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H

#include "Employee.h"

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double workedHours;

public:
    // Constructor rút gọn
    HourlyEmployee(const std::string& employeeId,
                   const std::string& fullName);

    // Constructor đầy đủ
    HourlyEmployee(const std::string& employeeId,
                   const std::string& fullName,
                   const std::string& department,
                   double hourlyRate,
                   double workedHours);

    // Ghi đè phương thức của Employee
    double calculateGrossPay() const override;

    std::string getEmployeeType() const override;

    void displayPayrollInfo() const override;
};

#endif
