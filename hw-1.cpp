

#include <iostream>
#include <string>
using namespace std;

void task1()
{
	string name;
	cin >> name;
	cout << name << endl;
}

void task2()
{
	double num1, num2;
	double sum, difference, product;
	double quotient;

	cin >> num1 >> num2;

	sum = num1 + num2;
	difference = num1 - num2;
	product = num1 * num2;

	if (num2 != 0) { quotient = num1 / num2; }

	cout << "Sum: " << sum << " Difference: " << difference << endl;
	cout << "Product: " << product << " Quotient: " << quotient << endl;
}

void task3() 
{
	double b, c;
	double x;

	cin >> b >> c;

	if (b != 0) { x = -c / b; }

	cout << "X: " << x << endl;
}

void task4()
{
	double a2, b2, c2, x1, x2, x0;
	double D;

	cin >> a2 >> b2 >> c2;

	D = b2 * b2 - 4 * a2 * c2;

	if (D > 0)
	{
		x1 = (-b2 + sqrt(D)) / 2 * a2;
		x2 = (-b2 - sqrt(D)) / 2 * a2;

		cout << "X1: " << x1 << " " << "X2: " << x2 << endl;
	}
	else if (D == 0)
	{
		x0 = (-b2) / 2 * a2;
		cout << "Root X: " << x0 << endl;
	}
	else if (D < 0) { cout << "No roots" << endl; }
}

void task5()
{
	bool isBright, isLampOn, areCurtainsOpen, isMorning;
	string isLampOnStr, areCurtainsOpenStr, isMorningStr;

	cout << "Is the lamp on? (y/n) ";
	cin >> isLampOnStr;

	cout << endl << "Is it morning? (y/n) ";
	cin >> isMorningStr;

	cout << endl << "Are curtains open? (y/n) ";
	cin >> areCurtainsOpenStr;

	if (isLampOnStr == "y") { isLampOn = true; }
	else { isLampOn = false; }

	if (isMorningStr == "y") { isMorning = true; }
	else { isMorning = false; }

	if (areCurtainsOpenStr == "y") { areCurtainsOpen = true; }
	else { areCurtainsOpen = false; }

	if (isLampOn || (isMorning && areCurtainsOpen)) { isBright = true; }
	else { isBright = false; }


	if (isBright) { cout << "The room is bright." << endl; }
	else { cout << "The room is dark" << endl; }
}



int main()
{
	//task1();

	//task2();

	//task3();
	

	//task4();

	task5();	

}
