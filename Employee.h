#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

class Employee {
protected:
    std::string employeeId;
    std::string fullName;
    std::string department;
    double monthlyBonus;

public:
    // Constructor rút gọn
    Employee(const std::string& employeeId,
             const std::string& fullName);

    // Constructor đầy đủ
    Employee(const std::string& employeeId,
             const std::string& fullName,
             const std::string& department);

    virtual ~Employee() = default;

    // Ba phiên bản addBonus() nạp chồng
    void addBonus(double amount);

    void addBonus(double amount,
                  const std::string& reason);

    void addBonus(double rate,
                  double referenceAmount,
                  const std::string& reason);

    // Đặt lại thưởng khi bắt đầu kỳ lương mới
    void resetBonus();

    // Getter
    const std::string& getEmployeeId() const;
    const std::string& getFullName() const;
    const std::string& getDepartment() const;
    double getMonthlyBonus() const;

    // Hàm ảo thuần túy
    virtual double calculateGrossPay() const = 0;
    virtual std::string getEmployeeType() const = 0;
    virtual void displayPayrollInfo() const = 0;
};

#endif
