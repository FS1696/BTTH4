#ifndef SALES_EMPLOYEE_H
#define SALES_EMPLOYEE_H

#include "Employee.h"

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

class SalesEmployee : public Employee {
private:
    double baseSalary;
    double salesRevenue;
    double commissionRate;

public:
    // Constructor rút gọn
    SalesEmployee(const std::string& employeeId,
                  const std::string& fullName);

    // Constructor đầy đủ
    SalesEmployee(const std::string& employeeId,
                  const std::string& fullName,
                  const std::string& department,
                  double baseSalary,
                  double salesRevenue,
                  double commissionRate);

    // Ghi đè phương thức
    double calculateGrossPay() const override;

    std::string getEmployeeType() const override;

    void displayPayrollInfo() const override;

    // Cập nhật doanh số có kiểm soát
    void updateSalesRevenue(double newSalesRevenue);
};

#endif
