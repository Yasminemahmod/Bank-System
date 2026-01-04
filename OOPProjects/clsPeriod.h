#pragma once
#include "clsDate.h";

class clsPeriod
{
private:
    clsDate _startDate;
    clsDate _endDate;

public:
    clsPeriod(clsDate startDate, clsDate endDate){
        _startDate= startDate;
        _endDate = endDate;
    }

    clsDate StartDate() { return _startDate; }
    clsDate EndDate() { return _endDate; }

    static bool IsDateWithinPeriod(clsPeriod per, clsDate date) {
        return (!clsDate::IsDate1BeforeDate2(date, per.StartDate()) &&
            !clsDate::IsDate1AfterDate2(date, per.EndDate()));
    }

    bool IsDateWithinPeriod(clsDate date) {
        return IsDateWithinPeriod(*this, date);
    }
};
