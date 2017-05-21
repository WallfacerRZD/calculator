#include "stdafx.h"
#include"functions.h"
#include<string>
#include<sstream>
#include"MyStack.h"
#include<map>
#include<set>

using std::set;
using std::string;
using std::map;
using std::istringstream;

std::string TransforToPostFix(const std::string &s) {
	map<string, int> priority;
	priority["+"] = 1;
	priority["-"] = 1;
	priority["*"] = 2;
	priority["/"] = 2;
	priority["("] = 10;
	set<string> ops_set = { "+", "-", "*", "/", "(", ")"};
	istringstream in(s);
	string str;
	string result;												//后缀表达式结果以" "分隔
	MyStack<string> ops;
	while (in >> str) {
		if (ops_set.find(str) == ops_set.end()) {			//是数，直接加入结果
			result = result + str + ' ';
		}
		else {
			if (str == ")") {												//是")"，弹出栈顶元素并写入结果直到遇到"("，并将"("弹出
				while (ops.Top() != "(") {
					string temp = ops.TopAndPop();
					result = result + temp + " ";
				}
				ops.Pop();
			}
			else {
				if (ops.IsEmpty() || ops.Top() == "(" || priority[ops.Top()] < priority[str]) {
					ops.Push(str);
				}
				else {
					while (!ops.IsEmpty() && ops.Top() != "(" &&priority[ops.Top()] >= priority[str]) {
						string temp = ops.TopAndPop();			//
						result = result + temp + " ";
					}
					ops.Push(str);
				}
			}
		}
	}
	while (!ops.IsEmpty()) {
		string temp = ops.TopAndPop();
		result = result + temp + " ";
	}
	return result;
}

BigData GetPostFixVal(const string&data) {
	set<string> ops = { "+", "-", "*", "/" };
	istringstream in(data);
	string str;
	MyStack<BigData> val;
	while (in >> str) {
		if (ops.find(str) == ops.end()) {
			BigData temp(str);
			val.Push(temp);
		}
		else {
			BigData rhs = val.TopAndPop();
			BigData lhs = val.TopAndPop();
			if (str == "+")		val.Push(lhs + rhs);
			else if (str == "-") val.Push(lhs - rhs);
			else if (str == "*") val.Push(lhs * rhs);
			else if (str == "/") val.Push(lhs / rhs);
		}
	}
	return val.Top();
}