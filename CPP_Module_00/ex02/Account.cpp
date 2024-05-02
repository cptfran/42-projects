#include "Account.hpp"
#include <iostream>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
int		Account::getNbAccounts() { return _nbAccounts; }
int		Account::getTotalAmount() { return _totalAmount; }
int		Account::getNbDeposits() { return _totalNbDeposits; }
int		Account::getNbWithdrawals() { return _totalNbWithdrawals; }
void	Account::displayAccountsInfos() {
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {}

void	Account::makeDeposit(int deposit) { _totalAmount += deposit; _totalNbDeposits++; }
bool	Account::makeWithdrawal(int withdrawal) {
	_totalAmount -= withdrawal;
	if (!checkAmount()) {
		_totalAmount += withdrawal;
		_totalNbWithdrawals = -1;
		return false;
	}
	_totalNbWithdrawals++;
	return true;
}
int		Account::checkAmount() const { return _totalAmount < 0 ? 0 : 1; }
void	Account::displayStatus() const {
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << std::endl;
}