#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, no_withdrawals{0}
{
    if(balance >= bonus_point)
        Account::deposit(bonus);
}

bool Trust_Account::deposit(double amount)
{
    if(amount >= bonus_point)
        amount+= bonus;
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
    if(no_withdrawals >= withdraw_limit or amount > balance * amount_limit_percent)
        return false;
    else{
        no_withdrawals++;
        return Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os)const {
    os.precision(2);
    os << std::fixed;
    os << "[Trust_Account: " << name << ": " << balance << ", " <<int_rate<<" %, Withdrawals: "<<no_withdrawals << "]";
}
