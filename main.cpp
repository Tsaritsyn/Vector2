/*
Не нужно создавать отдельный репозиторий под каждое упражнение.
Нужно было создать один репозиторий sem4 на весь семестр.
Попросите Ивана или ещё кого-нибудь, кто в прошлом семестре к нам на семинары ходил, 
подробнее прокомментировать, как мы сдавать упражнения.

Ваш вектор2 посмотрю до четверга.
*/

#include <iostream>
#include "Vector2.h"

using namespace std;

int main()
{
	Vector2 a, b;
	cout << "Write the first vector\n";
	cin >> a;
	cout << "Repeat vector: " << a;
	cout << "Opposite vector: " << -a;
	cout << "Length of vector: " << a.length() << endl;
	cout << "Vector of 1 length: " << a.unit();
	cout << "Normal vector: " << a.normal();
	
	float k;
	cout << "Write a number\n";
	cin >> k;
	cout << "Multiplications of vector: " << a * k << k * a;
	cout << "Division of vector: " << a / k;

	float f;
	cout << "Write an angle in degrees\n";
	cin >> f;
	cout << "Rotated vector: " << a.getRotatedDegrees(f);
	a.rotateDegrees(f);
	cout << "New first: " << a;
	
	cout << "Write the second vector\n";
	cin >> b;
	cout << "Sum of vectors: " << a + b;
	a += b;
	cout << "New first: " << a;
	cout << "Difference of vectors: " << a - b;
	b -= a;
	cout << "New second: " << b;
	cout << "Scalar multiplication: " << a * b << endl;
	//cout << "Vector multiplication: " << a ^ b;

	
	return 0;
}
