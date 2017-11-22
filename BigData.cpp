#include"BigData.h"
#include<sstream>
#include<algorithm>

using std::istringstream;
using std::ostringstream;

BigData::BigData():
	data_(""), ispositive(true)
	{ }

BigData::BigData(const string &data) {
	if (ispunct(data[0])) {
		data_ = data.substr(1);
		if (data[0] == '+') {
			ispositive = true;
		}
		else {
			ispositive = false;
		}
	}
	else {
		data_ = data;
		ispositive = true;
	}

}

BigData DoAdd(const BigData &lhs, const BigData &rhs) {					//������
	int carry = 0;
	auto lhs_beg = lhs.data_.crbegin();
	auto rhs_beg = rhs.data_.crbegin();
	auto lhs_end = lhs.data_.crend();
	auto rhs_end = rhs.data_.crend();
	BigData result;
	while (lhs_beg != lhs_end || rhs_beg != rhs_end) {
		int digit1 = ((lhs_beg == lhs_end) ? 0 : *lhs_beg - '0');
		int digit2 = ((rhs_beg == rhs_end) ? 0 : *rhs_beg - '0');
		int sum = digit1 + digit2 + carry;
		result.data_.push_back((sum % 10) + '0');
		carry = sum / 10;
		rhs_beg = ((rhs_beg == rhs_end) ? rhs_beg : rhs_beg + 1);
		lhs_beg = ((lhs_beg == lhs_end) ? lhs_end : lhs_beg + 1);
	}
	if (carry == 1) {
		result.data_.push_back('1');
	}
	std::reverse(result.data_.begin(), result.data_.end());
	return result;
}


BigData DoSubtraction(const BigData &lhs, const BigData &rhs) {		//��(��) - ��(С)
	auto lhs_beg = lhs.data_.crbegin();
	auto rhs_beg = rhs.data_.crbegin();
	auto lhs_end = lhs.data_.crend();
	auto rhs_end = rhs.data_.crend();
	BigData result;
	int carry = 0;
	while (lhs_beg != lhs_end || rhs_beg != rhs_end) {
		int digit1 = ((lhs_beg == lhs_end) ? 0 : *lhs_beg - '0');
		int digit2 = ((rhs_beg == rhs_end) ? 0 : *rhs_beg - '0');
		if (digit1 - digit2 + carry < 0) {
			result.data_.push_back(digit1 - digit2 + carry + 10 + '0');
			carry = -1;
		}
		else {
			result.data_.push_back(digit1 - digit2 + carry + '0');
			carry = 0;
		}
		lhs_beg = ((lhs_beg == lhs_end) ? lhs_end : lhs_beg + 1);
		rhs_beg = ((rhs_beg == rhs_end) ? rhs_end : rhs_beg + 1);
	}

	auto result_beg = result.data_.crbegin();
	while (*result_beg == '0') {
		++result_beg;
	}
	int x = -(result_beg - result.data_.crend());
	result.data_ = result.data_.substr(0, x);
	result.ispositive = true;
	std::reverse(result.data_.begin(), result.data_.end());
	return result;
}

BigData DoMultiply(const BigData &lhs, const BigData &rhs) {		//��(��λ)*��(һλ)
	auto lhs_beg = lhs.data_.crbegin();
	auto lhs_end = lhs.data_.crend();
	auto rhs_beg = rhs.data_.crbegin();
	int carry = 0;
	BigData result;
	int digit1 = *lhs_beg - '0';
	int digit2 = *rhs_beg - '0';
	int product = 0;
	while (lhs_beg != lhs_end - 1) {
		digit1 = *lhs_beg - '0';
		product = digit1 * digit2 + carry;
		result.data_.push_back(product % 10 + '0');
		carry = product / 10;
		++lhs_beg;
	}
	digit1 = *lhs_beg - '0';
	product = digit1 * digit2 + carry;
	if (product > 10) {
		result.data_.push_back(product % 10 + '0');
		result.data_.push_back(product / 10 + '0');
	}
	else {
		result.data_.push_back(product + '0');
	}
	std::reverse(result.data_.begin(), result.data_.end());
	return result;
}

BigData DoDivide(const BigData &lhs, const BigData &rhs) {
	if (lhs == rhs) {
		return BigData("1");
	}
	else {
		int times = lhs.data_.size() - rhs.data_.size();
		BigData result("0");
		BigData temp_lhs(lhs);
		while (times >= 0) {
			BigData temp(rhs);
			for (int i = 0; i < times; ++i) {
				temp = temp * BigData("10");
			}

			if (temp > lhs) {
				--times;
				temp = temp / BigData("10");
			}

			int count = 0;
			BigData subtraction = temp_lhs - temp;
			while (subtraction.ispositive == true) {
				temp_lhs = temp_lhs - temp;
				subtraction = temp_lhs - temp;
				++count;
			}
			BigData temp2(std::to_string(count));
			for (int i = 0; i < times; ++i) {
				temp2 = temp2 * BigData("10");
			}
			result = result + temp2;
			--times;
		}
		return result;	
	}
}

const BigData operator+(const BigData &lhs, const BigData &rhs) {
	if (lhs.ispositive == true && rhs.ispositive == true) {
		return DoAdd(lhs, rhs);
	}
	else if (lhs.ispositive == true && rhs.ispositive == false) {
		BigData temp = (rhs);
		temp.ispositive = true;
		return lhs - temp;
	}
	else if (lhs.ispositive == false && rhs.ispositive == true) {
		BigData temp(lhs);
		temp.ispositive = true;
		return rhs - temp;
	}
	else {
		BigData temp1(lhs), temp2(rhs);
		temp1.ispositive = true;
		temp2.ispositive = true;
		temp1 = temp1 + temp2;
		temp1.ispositive = false;
		return temp1;
	}
}


const BigData operator-(const BigData &lhs, const BigData &rhs) {
	if (lhs.ispositive == true && rhs.ispositive == true) {
		if (lhs == rhs) return BigData("0");
		else if (lhs > rhs) return DoSubtraction(lhs, rhs);
		else{
			BigData temp = DoSubtraction(rhs, lhs);
			temp.ispositive = false;
			return temp;
		}
	}
	else if (lhs.ispositive == true && rhs.ispositive == false) {
		BigData temp(rhs);
		temp.ispositive = true;
		return lhs + temp;
	}
	else if (lhs.ispositive == false && rhs.ispositive == true) {
		BigData temp(lhs);
		temp.ispositive = true;
		temp = temp + rhs;
		temp.ispositive = false;
		return temp;
	}
	else{
		if (lhs == rhs) {
			return BigData("0");
		}
		else {
			if (lhs > rhs) {
				BigData temp = DoSubtraction(lhs, rhs);
				temp.ispositive = false;
				return temp;
			}
			else {
				return DoSubtraction(rhs, lhs);
			}
		}
	}
}

const BigData operator*(const BigData &lhs, const BigData &rhs) {
	if (rhs == BigData("0") || lhs == BigData("0")) {
		return BigData("0");
	}
	if (lhs.ispositive == true && rhs.ispositive == true) {
		if (rhs == BigData("10")) {
			BigData temp(lhs);
			temp.ispositive = true;
			temp.data_.push_back('0');
			return temp;
		}
		else {
			int i = 0;
			BigData temp(rhs);
			auto temp_beg = rhs.data_.crbegin();
			auto temp_end = rhs.data_.crend();
			BigData result("0");
			while (temp_beg != temp_end) {
				string ch = "a";
				ch[0] = *temp_beg;
				BigData product = DoMultiply(lhs, BigData(ch));
				for (int j = 0; j != i; ++j) {
					product = product * BigData("10");
				}
				++i;
				result = result + product;
				++temp_beg;
			}
			return result;
		}
	}
	else if ( (lhs.ispositive == true && rhs.ispositive == false) || (lhs.ispositive == false && rhs.ispositive == true) ) {
		BigData temp1(lhs), temp2(rhs), result;
		temp1.ispositive = temp2.ispositive = true;
		result = temp1 * temp2;
		result.ispositive = false;
		return result;
	}
	else{
		BigData temp1(lhs), temp2(rhs), result;
		temp1.ispositive = temp2.ispositive = true;
		result = temp1 * temp2;
		return result;
	}
}

const BigData operator/(const BigData &lhs, const BigData &rhs) {
	if (rhs == BigData("0")) {
		std::cout << "��������Ϊ0" << std::endl;
		exit(1);
	}
	if (lhs == BigData("0")) {
		return BigData("0");
	}
	if (rhs == BigData("10")) {
		if (lhs > BigData("9")) {
			BigData temp = lhs.data_.substr(0, lhs.data_.size() - 1);
			return temp;
		}
		else {
			return BigData("0");
		}
	}
	else {
		if (lhs.ispositive == true && rhs.ispositive == true) {
			BigData temp = ( (lhs >= rhs) ? DoDivide(lhs, rhs) : BigData("0") );
			return temp;
		}
		else if (lhs.ispositive == false && rhs.ispositive == false) {
			BigData temp_lhs = lhs, temp_rhs = rhs;
			temp_lhs.ispositive = true;
			temp_rhs.ispositive = true;
			return temp_lhs / temp_rhs;
		}
		else {
			BigData temp_lhs = lhs, temp_rhs = rhs;
			temp_lhs.ispositive = true;
			temp_rhs.ispositive = true;
			BigData result = temp_lhs / temp_rhs;
			result.ispositive = false;
			return result;
		}



	}




	return BigData();
}

bool operator>(const BigData &lhs, const BigData &rhs) {
	if (lhs == rhs) {
		return false;
	}
	else {
		if (lhs.data_.size() == rhs.data_.size()) {
			return lhs.data_ > rhs.data_;
		}
		else {
			return lhs.data_.size() > rhs.data_.size();
		}
	}
}

bool operator<(const BigData &lhs, const BigData &rhs) {
	if (lhs == rhs)
		return false;
	else {
		return !(lhs > rhs);
	}
}

bool operator==(const BigData &lhs, const BigData &rhs) {
	return lhs.data_ == rhs.data_;
}

bool operator!=(const BigData &lhs, const BigData &rhs) {
	return !(lhs == rhs);
}

bool operator>=(const BigData &lhs, const BigData &rhs) {
	return (lhs > rhs || lhs == rhs);
}

bool operator<=(const BigData &lhs, const BigData &rhs) {
	return (lhs < rhs || lhs == rhs);
}


ostream& operator<<(ostream &os, const BigData &rhs) {
	if (rhs.ispositive == false) {
		os << '-' << rhs.data_;
	}
	else {
		os << rhs.data_;
	}
	return os;
}

istream& operator>>(istream &is, BigData &rhs) {
	is >> rhs.data_;
	if (ispunct(rhs.data_[0])) {
		rhs.data_ = rhs.data_.substr(1);
		if (rhs.data_[0] == '+') {
			rhs.ispositive = true;
		}
		else {
			rhs.ispositive = false;
		}
	}
	else {
		rhs.ispositive = true;
	}
	return is;
}