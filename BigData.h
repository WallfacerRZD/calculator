#ifndef BIGDATA_H
#define BIGDATA_H

#include<string>
#include<iostream>

using std::string;
using std::istream;
using std::ostream;

struct DigitNode;

class BigData {
public:
	friend BigData DoAdd(const BigData &lhs, const BigData &rhs);
	friend BigData DoSubtraction(const BigData &lhs, const BigData &rhs);
	friend BigData DoMultiply(const BigData &lhs, const BigData &rhs);
	friend BigData DoDivide(const BigData &lhs, const BigData &rhs);
	//жиди
	friend const BigData operator+(const BigData &lhs, const BigData &rhs);
	friend const BigData operator-(const BigData &lhs, const BigData &rhs);
	friend const BigData operator*(const BigData &lhs, const BigData &rhs);
	friend const BigData operator/(const BigData &lhs, const BigData &rhs);
	friend bool operator>(const BigData &lhs, const BigData &rhs);
	friend bool operator<(const BigData &lhs, const BigData &rhs);
	friend bool operator==(const BigData &lhs, const BigData &rhs);
	friend bool operator!=(const BigData &lhs, const BigData &rhs);
	friend bool operator>=(const BigData &lhs, const BigData &rhs);
	friend bool operator<=(const BigData &lhs, const BigData &rhs);
	friend ostream& operator<<(ostream &os, const BigData &rhs);
	friend istream& operator >> (istream &is, BigData &rhs);

	BigData();
	BigData(const string &data);
	BigData(const BigData &rhs) = default;
	BigData& operator=(const BigData &rhs) = default;
	~BigData() = default;
	string data_;
	bool ispositive;
};


#endif
