#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "SalesEmployee.h"
#include "Payroll.h"

/**************************************************
 * Mã sinh viên: 202419074
 * Họ tên: Vũ Thành Lâm
 **************************************************/

// So sánh số thực
bool almostEqual(double a, double b)
{
    return (a > b ? a - b : b - a) < 0.01;
}

// In kết quả test
void printTest(
    int number,
    const std::string& description,
    bool passed)
{
    std::cout
        << "Test "
        << std::setw(2)
        << number
        << ": "
        << std::left
        << std::setw(68)
        << description
        << (passed ? "PASS" : "FAIL")
        << std::right
        << '\n';
}

int main()
{
    try {

        // =====================================================
        // Tạo bảng lương kỳ 2026-09
        // =====================================================

        Payroll payroll("2026-09");

        // =====================================================
        // E001 - SalariedEmployee
        // Lương: 15.000.000
        // Phụ cấp: 2.000.000
        // Thưởng: 1.000.000
        // Gross = 18.000.000
        // =====================================================

        auto e1 =
            std::make_unique<SalariedEmployee>(
                "E001",
                "Nguyen Minh An",
                "Dao tao",
                15000000,
                2000000
            );

        e1->addBonus(1000000);

        // =====================================================
        // E002 - HourlyEmployee
        // 150 giờ × 100.000 + 500.000
        // = 15.500.000
        // =====================================================

        auto e2 =
            std::make_unique<HourlyEmployee>(
                "E002",
                "Tran Thu Binh",
                "Ho tro",
                100000,
                150
            );

        e2->addBonus(
            500000,
            "Thuong co dinh"
        );

        // =====================================================
        // E003 - HourlyEmployee
        // 170 giờ
        // 160 × 100.000
        // + 10 × 100.000 × 1.5
        // = 17.500.000
        // =====================================================

        auto e3 =
            std::make_unique<HourlyEmployee>(
                "E003",
                "Le Hoang Chi",
                "Ho tro",
                100000,
                170
            );

        // Không có thưởng

        // =====================================================
        // E004 - SalesEmployee
        // Base = 8.000.000
        // Sales = 200.000.000
        // Commission = 5%
        // Bonus = 2% × 50.000.000
        // Gross = 19.000.000
        // =====================================================

        auto e4 =
            std::make_unique<SalesEmployee>(
                "E004",
                "Pham Quoc Dung",
                "Kinh doanh",
                8000000,
                200000000,
                0.05
            );

        e4->addBonus(
            0.02,
            50000000,
            "Thuong theo doanh so"
        );

        // =====================================================
        // Thêm nhân viên vào Payroll
        // =====================================================

        payroll.addEmployee(std::move(e1));
        payroll.addEmployee(std::move(e2));
        payroll.addEmployee(std::move(e3));
        payroll.addEmployee(std::move(e4));

        // =====================================================
        // Hiển thị bảng lương
        // =====================================================

        payroll.displayPayroll();

        std::cout << std::fixed
                  << std::setprecision(0);

        // Tổng bảng lương
        std::cout
            << "Tong bang luong: "
            << payroll.calculateTotalPayroll()
            << '\n';

        // Tổng phòng Hỗ trợ
        std::cout
            << "Tong phong Ho tro: "
            << payroll.calculatePayrollByDepartment(
                   "Ho tro")
            << '\n';

        // Người có thu nhập cao nhất
        Employee* highest =
            payroll.findHighestPaidEmployee();

        if (highest != nullptr) {

            std::cout
                << "Nguoi co thu nhap cao nhat: "
                << highest->getFullName()
                << " ("
                << highest->calculateGrossPay()
                << ")\n";
        }

        // =====================================================
        // KIỂM THỬ
        // =====================================================

        std::cout
            << "\n================ KIEM THU "
            << "================\n";

        // -----------------------------------------------------
        // Test 01
        // -----------------------------------------------------

        Employee* found =
            payroll.findEmployee("E001");

        printTest(
            1,
            "SalariedEmployee E001 tinh gross = 18,000,000",
            found != nullptr &&
            almostEqual(
                found->calculateGrossPay(),
                18000000
            )
        );

        // -----------------------------------------------------
        // Test 02
        // -----------------------------------------------------

        found =
            payroll.findEmployee("E002");

        printTest(
            2,
            "HourlyEmployee E002 (150 gio) = 15,500,000",
            found != nullptr &&
            almostEqual(
                found->calculateGrossPay(),
                15500000
            )
        );

        // -----------------------------------------------------
        // Test 03
        // -----------------------------------------------------

        found =
            payroll.findEmployee("E003");

        printTest(
            3,
            "HourlyEmployee E003 (170 gio, OT) = 17,500,000",
            found != nullptr &&
            almostEqual(
                found->calculateGrossPay(),
                17500000
            )
        );

        // -----------------------------------------------------
        // Test 04
        // -----------------------------------------------------

        found =
            payroll.findEmployee("E004");

        printTest(
            4,
            "SalesEmployee E004 = 19,000,000",
            found != nullptr &&
            almostEqual(
                found->calculateGrossPay(),
                19000000
            )
        );

        // -----------------------------------------------------
        // Test 05 - Tổng payroll
        // -----------------------------------------------------

        printTest(
            5,
            "Tong payroll = 70,000,000",
            almostEqual(
                payroll.calculateTotalPayroll(),
                70000000
            )
        );

        // -----------------------------------------------------
        // Test 06 - Phòng Hỗ trợ
        // -----------------------------------------------------

        printTest(
            6,
            "Tong phong Ho tro = 33,000,000",
            almostEqual(
                payroll.calculatePayrollByDepartment(
                    "Ho tro"
                ),
                33000000
            )
        );

        // -----------------------------------------------------
        // Test 07 - Người cao nhất
        // -----------------------------------------------------

        highest =
            payroll.findHighestPaidEmployee();

        printTest(
            7,
            "Nguoi cao nhat la E004",
            highest != nullptr &&
            highest->getEmployeeId() == "E004"
        );

        // -----------------------------------------------------
        // Test 08 - Không cho mã trùng
        // -----------------------------------------------------

        auto duplicate =
            std::make_unique<SalariedEmployee>(
                "E001",
                "Nguoi Trung Ma",
                "Dao tao",
                1000000,
                0
            );

        bool duplicateAdded =
            payroll.addEmployee(
                std::move(duplicate)
            );

        printTest(
            8,
            "Khong them nhan su trung ma E001",
            !duplicateAdded
        );

        // -----------------------------------------------------
        // Test 09 - Constructor rút gọn
        // -----------------------------------------------------

        SalariedEmployee shortEmployee(
            "E005",
            "Nhan Vien Rut Gon"
        );

        printTest(
            9,
            "Constructor rut gon dat phong ban = Unassigned",
            shortEmployee.getDepartment()
                == "Unassigned"
        );

        // -----------------------------------------------------
        // Test 10 - addBonus(amount)
        // -----------------------------------------------------

        shortEmployee.addBonus(1000000);

        printTest(
            10,
            "addBonus(amount) cong dung 1,000,000",
            almostEqual(
                shortEmployee.getMonthlyBonus(),
                1000000
            )
        );

        // -----------------------------------------------------
        // Test 11 - addBonus(amount, reason)
        // -----------------------------------------------------

        shortEmployee.addBonus(
            500000,
            "Thuong ho tro"
        );

        printTest(
            11,
            "addBonus(amount, reason) cong dung 500,000",
            almostEqual(
                shortEmployee.getMonthlyBonus(),
                1500000
            )
        );

        // -----------------------------------------------------
        // Test 12 - addBonus(rate, referenceAmount, reason)
        // -----------------------------------------------------

        shortEmployee.addBonus(
            0.1,
            10000000,
            "Thuong theo ty le"
        );

        printTest(
            12,
            "addBonus(rate, referenceAmount, reason) = 1,000,000",
            almostEqual(
                shortEmployee.getMonthlyBonus(),
                2500000
            )
        );

        // -----------------------------------------------------
        // Test 13 - Bonus âm
        // -----------------------------------------------------

        bool invalidBonusRejected = false;

        try {

            shortEmployee.addBonus(-100);

        }
        catch (const std::invalid_argument&) {

            invalidBonusRejected = true;
        }

        printTest(
            13,
            "Tu choi bonus am",
            invalidBonusRejected
        );

        // -----------------------------------------------------
        // Test 14 - Giờ làm > 250
        // -----------------------------------------------------

        bool invalidHoursRejected = false;

        try {

            HourlyEmployee bad(
                "E006",
                "Bad Employee",
                "Ho tro",
                100000,
                251
            );

        }
        catch (const std::invalid_argument&) {

            invalidHoursRejected = true;
        }

        printTest(
            14,
            "Tu choi so gio lam > 250",
            invalidHoursRejected
        );

        // -----------------------------------------------------
        // Test 15 - Hoa hồng > 30%
        // -----------------------------------------------------

        bool invalidCommissionRejected = false;

        try {

            SalesEmployee bad(
                "E007",
                "Bad Sales",
                "Kinh doanh",
                8000000,
                100000000,
                0.31
            );

        }
        catch (const std::invalid_argument&) {

            invalidCommissionRejected = true;
        }

        printTest(
            15,
            "Tu choi hoa hong > 30%",
            invalidCommissionRejected
        );

        // -----------------------------------------------------
        // Test 16 - Payroll rỗng
        // -----------------------------------------------------

        Payroll emptyPayroll("2026-10");

        printTest(
            16,
            "Payroll rong co tong = 0",
            almostEqual(
                emptyPayroll.calculateTotalPayroll(),
                0
            )
        );

        // -----------------------------------------------------
        // Test 17 - Payroll rỗng không có highest
        // -----------------------------------------------------

        printTest(
            17,
            "Payroll rong khong co highest-paid employee",
            emptyPayroll.findHighestPaidEmployee()
                == nullptr
        );

        // -----------------------------------------------------
        // Test 18 - Cập nhật doanh số
        // -----------------------------------------------------

        SalesEmployee sales(
            "E008",
            "Test Sales",
            "Kinh doanh",
            8000000,
            100000000,
            0.05
        );

        sales.updateSalesRevenue(200000000);

        printTest(
            18,
            "Cap nhat doanh so hop le",
            almostEqual(
                sales.calculateGrossPay(),
                18000000
            )
        );

        // =====================================================

        std::cout
            << "===========================================\n";
    }

    catch (const std::exception& ex) {

        std::cerr
            << "Loi: "
            << ex.what()
            << '\n';

        return 1;
    }

    return 0;
}
