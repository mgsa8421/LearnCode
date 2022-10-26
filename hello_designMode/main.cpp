#include <iostream>
using namespace std;

class Operation
{
public:
	Operation(float A,float B)
	{
		NumberA = A;
		NumberB = B;
	};

	Operation()
	{
		NumberA = 1;
		NumberB = 2;
	};

	void setNumberA(float valA)
	{
		NumberA = valA;
	};

	void setNumberB(float valB)
	{
		NumberB = valB;
	};

	float getsNumberA(){
		return NumberA;
	};

	float getsNumberB(){
		return NumberB;
	};

private:
	float NumberA;
	float NumberB;
};

int main()
{
	Operation op;
	float getB = op.getsNumberB();
	cout << getB << endl;
}