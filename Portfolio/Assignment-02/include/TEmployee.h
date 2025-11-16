#pragma once
#include <string>
#include <utility>

/**
 * @brief Basic employee object used everywhere in the assignment.
 */
enum class EDepartment { IT, Finance, HR };

class TEmployee {
private:
    std::string mFirstName;
    std::string mLastName;
    EDepartment mDepartment;

public:
    /// @brief Simple constructor used when loading names.
    TEmployee(std::string first, std::string last, EDepartment dept)
        : mFirstName(std::move(first)),
          mLastName(std::move(last)),
          mDepartment(dept) {}

    const std::string& First() const { return mFirstName; }
    const std::string& Last() const { return mLastName; }
    EDepartment Department() const { return mDepartment; }

    /// @brief Quick helper turing enums into strings.
    std::string ToString() const {
        const char* d = (mDepartment == EDepartment::IT ? "IT" :
                         (mDepartment == EDepartment::Finance ? "Finance" : "HR"));
        return mFirstName + " " + mLastName + " (" + d + ")";
    }
};
