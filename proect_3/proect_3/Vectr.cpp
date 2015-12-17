#include "stdafx.h"
#include "Vectr.h"

Vector::Vector()
{
	vector = NULL;
	size = 0;
}

Vector::Vector(const Vector & a)
{
	vector = new double[a.size];
	size = a.size;
	for (int i(0);i < a.size;i++)
	{
		vector[i] = a.vector[i];
	}
}

void Vector::show()
{
	std::cout << "( ";
	for (int i(0);i < size; i++) {
		std::cout << vector[i];
		if (i != size - 1)
			std::cout << " , ";
	}
	std::cout << " )\n";
}

void Vector::push(double x)
{
	if (vector == NULL)
	{
		size = 1;
		vector = new double[size];
		vector[0] = x;
		return;
	}

	double *a = new double[size];
	for (int i(0);i< size;i++)
		a[i] = vector[i];
	delete (vector);
	vector = new double[size + 1];
	for (int i(0);i< size;i++)
		vector[i] = a[i];
	vector[size] = x;
	size++;
}

void Vector::del(int index)
{
	for (int i = index; i < size - 1; i++)
	{
		vector[i] = vector[i + 1];
	}
	size--;
	double *a = new double[size];
	for (int i(0);i< size;i++)
		a[i] = vector[i];
	delete (vector);
	vector = new double[size];
	for (int i(0);i< size;i++)
		vector[i] = a[i];
}

Vector Vector::operator+(const Vector & a)
{
	Vector tmp;
	if (size == a.size) {
		tmp.size = size;
		tmp.vector = new double[tmp.size];
		for (int i(0);i < size;i++) {
			tmp.vector[i] = vector[i] + a.vector[i];
		}
		return tmp;
	}
	else {
		std::cout << "\nsize_1 != size_2\n";
		return tmp;
	}
}

Vector Vector::operator=(const Vector & a)
{
	if (vector != NULL)
		delete(vector);

	vector = new double[a.size];

	for (int i(0); i < a.size; i++)
	{
		vector[i] = a.vector[i];
	}
	size = a.size;
	return *this;
}

int operator<(const Vector & a1, const Vector&a2)
{
	return a1.size<a2.size;
}

int operator<(const Vector&a, const int c)
{
	int b = true;
	for (int i(0); i < a.size;i++)
	{
		if (a.vector[i] > c)
			b = false;
	}
	return b;
}

int Vector::operator>(const Vector & a)
{
	return size>a.size;
}

int operator>(const Vector&c, const int a)
{
	int b = true;
	for (int i(0); i < c.size;i++)
	{
		if (c.vector[i] < a)
			b = false;
	}
	return b;
}

int Vector::operator==( Vector & a)
{
	return size==a.size;
}

double Vector::operator[](int i)
{
	return vector[i];
}

Vector::Vector(int N, double a)
{
	size = N;
	vector = new double[N];
	for (int i(0); i < N;i++) {
		vector[i] = a;
	}
}

ostream& operator<<(ostream& os, Vector v) {
	v.show();
	return os;
}