#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H
#include "Savings_Account.h"

class Trust_Account: public Savings_Account
{
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr int withdraw_limit = 3;
    static constexpr double bonus = 50.00;
    static constexpr double bonus_point = 5000.00;
    static constexpr double amount_limit_percent = 0.20;
protected:
    int no_withdrawals;

public:
    Trust_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount)override;
    virtual void print(std::ostream &os)const override;
    virtual ~Trust_Account() = default;
};

#endif // TRUST_ACCOUNT_H
