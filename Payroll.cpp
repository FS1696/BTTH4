#include "Payroll.h"
#include <iostream>
#include <iomanip>

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

// Constructor
Payroll::Payroll(const std::string& period)
    : period(period)
{
}

// Thêm nhân viên
bool Payroll::addEmployee(
    std::unique_ptr<Employee> employee)
{
    // Không nhận nullptr
    if (!employee) {
        return false;
    }

    // Không cho phép trùng mã
    if (findEmployee(employee->getEmployeeId()) != nullptr) {
        return false;
    }

    employees.push_back(std::move(employee));

    return true;
}

// Tìm nhân viên
Employee* Payroll::findEmployee(
    const std::string& employeeId) const
{
    for (const auto& employee : employees) {

        if (employee->getEmployeeId() == employeeId) {
            return employee.get();
        }
    }

    return nullptr;
}

// Tính tổng bảng lương
double Payroll::calculateTotalPayroll() const
{
    double total = 0.0;

    /*
     * Không kiểm tra if theo từng loại nhân viên.
     * Chỉ gọi calculateGrossPay() qua Employee.
     */
    for (const auto& employee : employees) {
        total += employee->calculateGrossPay();
    }

    return total;
}

// Tính tổng theo phòng ban
double Payroll::calculatePayrollByDepartment(
    const std::string& department) const
{
    double total = 0.0;

    for (const auto& employee : employees) {

        if (employee->getDepartment() == department) {
            total += employee->calculateGrossPay();
        }
    }

    return total;
}

// Tìm người có thu nhập cao nhất
Employee* Payroll::findHighestPaidEmployee() const
{
    // Danh sách rỗng
    if (employees.empty()) {
        return nullptr;
    }

    Employee* highest = employees.front().get();

    for (const auto& employee : employees) {

        if (employee->calculateGrossPay()
            > highest->calculateGrossPay()) {

            highest = employee.get();
        }
    }

    return highest;
}

// Hiển thị bảng lương
void Payroll::displayPayroll() const
{
    std::cout
        << "\n========== BANG LUONG KY "
        << period
        << " ==========\n";

    if (employees.empty()) {
        std::cout << "Danh sach rong.\n";
        return;
    }

    // Đa hình động
    for (const auto& employee : employees) {
        employee->displayPayrollInfo();
    }

    std::cout
        << "========================================\n";
}

// Số lượng nhân viên
std::size_t Payroll::getEmployeeCount() const
{
    return employees.size();
}
