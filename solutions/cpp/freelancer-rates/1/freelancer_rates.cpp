// INFO: Headers from the standard library should be inserted at the top via
// #include <LIBRARY_NAME>
#include<cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    double daily_rate = 8. * hourly_rate;
    return daily_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    double discounted_price = before_discount * (1 - discount/100);
    return discounted_price;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    double monthly_rate_before_discount = daily_rate(hourly_rate) * 22;
    double monthly_rate = apply_discount(monthly_rate_before_discount, discount);
    return ceil(monthly_rate);
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    double discounted_daily_rate = apply_discount(daily_rate(hourly_rate), discount);
    double days_in_budget = budget / discounted_daily_rate;
    return floor(days_in_budget);
}
