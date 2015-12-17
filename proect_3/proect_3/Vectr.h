#pragma once

#include <iostream>

using namespace std;

class Vector {
	double *vector;
	int size;
public:
	Vector(int, double);
	Vector();
	Vector(const Vector &a);
	void show();
	void push(double);
	void del(int);
	int getSize() { return size; }
	Vector operator+(const Vector &a);
	Vector operator= (const Vector &a);
	friend int operator< (const Vector &a1, const Vector&a2);
	friend int operator< (const Vector &a, const int c);
	int operator> (const Vector &a);
	friend int operator> (const Vector&c, const int a);
	int operator== ( Vector &a);
	double operator[](int i);
	friend ostream& operator<<(ostream& os, Vector);
};
