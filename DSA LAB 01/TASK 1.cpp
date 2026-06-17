#include <iostream>
using namespace std;

class BankAccount {
private:
    double TAmount;
public:
    BankAccount() 
	{ 
    	TAmount = 0.0; 
	}
    BankAccount(double initialBalance) 
	{ 
	     TAmount = initialBalance;
	}
    BankAccount(const BankAccount &B1) 
	{ 
	    TAmount = B1.TAmount; 
	}
    void withdraw(double amount) 
	{ 
	   if (amount <= TAmount) 

	{
		 TAmount -= amount;
	}
	      
	}
    double getTAmount() const 
	{ 
	return TAmount; 
	}
};

int main() {
    BankAccount account1;
    cout << " Account1: $" << account1.getTAmount() << endl;

    BankAccount account2(1000.0);
    cout << " Account2: $" << account2.getTAmount() << endl;

    BankAccount account3(account2);
    account3.withdraw(200);
    cout << " Account3: $" << account3.getTAmount() << endl;
    cout << " Account2: $" << account2.getTAmount() << endl;

    return 0;
}


