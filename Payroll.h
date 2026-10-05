#ifndef PAYROLL_H
#define PAYROLL_H

#include "Employee.h"

#include <memory>
#include <string>
#include <vector>

class Payroll {
private:
    std::string period;

    // Danh sách nhân sự đa hình
    std::vector<std::unique_ptr<Employee>> employees;

public:
    explicit Payroll(const std::string& period);

    // Thêm nhân viên
    bool addEmployee(
        std::unique_ptr<Employee> employee
    );

    // Tìm nhân viên theo mã
    Employee* findEmployee(
        const std::string& employeeId
    ) const;

    // Tính tổng bảng lương
    double calculateTotalPayroll() const;

    // Tính tổng theo phòng ban
    double calculatePayrollByDepartment(
        const std::string& department
    ) const;

    // Tìm người có thu nhập cao nhất
    Employee* findHighestPaidEmployee() const;

    // Hiển thị bảng lương
    void displayPayroll() const;

    // Số lượng nhân viên
    std::size_t getEmployeeCount() const;
};

#endif
