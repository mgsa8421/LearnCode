#include <iostream>
using namespace std;

// 运算操作基类
class Operation
{
public:
	// 构造函数重载
	Operation(float A, float B)
	{
		NumberA = A;
		NumberB = B;
	}

	Operation()
	{
		NumberA = 1;
		NumberB = 2;
	}

	void setNumberA(float valA)
	{
		NumberA = valA;
	}

	void setNumberB(float valB)
	{
		NumberB = valB;
	}

	float getsNumberA()
	{
		return NumberA;
	}

	float getsNumberB()
	{
		return NumberB;
	}

	virtual float getValue()
	{
		return 0;
	}

protected:
	float NumberA;
	float NumberB;
};

// 四个具体的运算类，重写值计算函数
class operateAdd : public Operation
{
public:
	float getValue()
	{
		return NumberA + NumberB;
	}
};

class operateSub : public Operation
{
public:
	float getValue()
	{
		return NumberA - NumberB;
	}
};

class operateMul : public Operation
{
public:
	float getValue()
	{
		return NumberA * NumberB;
	}
};

class operateDiv : public Operation
{
public:
	float getValue()
	{
		return NumberA / NumberB;
	}
};

class SimpleFactory
{
public:
	Operation *CreatOpertion(char opt)
	{
		Operation* optObj = new Operation;
		optObj = nullptr;
		switch (opt)
		{
		case '+':
			optObj = new operateAdd;
			return optObj;
			break;
		case '-':
			optObj = new operateSub;
			return optObj;
			break;
		case '*':
			optObj = new operateMul;
			return optObj;
			break;
		case '/':
			optObj = new operateDiv;
			return optObj;
			break;
		default:
			cout << "无效的成绩" << endl;
		}

		return optObj;
	}
};

int main()
{
	SimpleFactory factory;
	Operation *ope = factory.CreatOpertion('*');
	ope->setNumberA(2);
	ope->setNumberB(3);
	float value = ope->getValue();
	cout << value;
	return 0;
};