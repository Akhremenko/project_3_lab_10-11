// proect_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <iterator> 
#include <algorithm>
#include <iostream>
#include "Vectr.h"

using namespace std;

struct ff {
	bool operator()(const Vector& a) const
	{
		return a < 0;
	}
};

struct f {
	bool operator()(const Vector& a) const
	{
		return a > 0;
	}
};

int main()
{
	vector<Vector> v,v1;

	Vector a,b,c;
	b.push(-1);
	b.push(-2);

	c.push(-3);
	c.push(-3);
	c.push(-3);
	
	for (int i(0); i < 4;i++) //в а вставляем с начала i , в вектор вставляем а c конца
	{
		a.push(i);
		v.push_back(a);
		cout << v[i];
	}

	cout << "\n";
	a.push(111); //в а пишем 111
	vector<Vector>::iterator p = v.begin();
	*p = a; //присваиваем ему значение а
	v.push_back(b); //и вставляем в вектор v ( б и с)
	v.push_back(c);

	for (int i(0); i < v.size(); i++)
		cout << v[i];

	sort(v.begin(),v.end()); //сортировка
	reverse(v.begin(), v.end());
	cout << "\n";
	for (int i(0); i < v.size(); i++)
		cout << v[i];// выводим векьлр

	set<Vector> s;
	
	remove_copy_if(v.begin(),v.end(), inserter(s, s.end()), f());
	v.erase(remove_if(v.begin(), v.end(), ff()), v.end());
	v.push_back(a);
	sort(v.begin(),v.end());

	set<Vector>::iterator t = s.begin();
	cout << "\n!!!!!!\n";
	while (t != s.end())
	{
		cout << *t;
		t++;
	}
	cout << "\n!!!!!!\n";

	for (int i(0); i < v.size(); i++)
		cout << v[i];
	cout << "\n";
	v.push_back(a);
	merge(v.begin(),v.end(),s.begin(),s.end(),back_inserter(v1));
	for (int i(0); i < v1.size(); i++)
		cout << v1[i];

	vector<int>::iterator::difference_type result1;
	result1 = count_if(v1.begin(),v1.end(),ff());
	cout << "\ncount_if= " << result1 << "\n";

	vector<Vector>::iterator k = find_if(v1.begin(), v1.end(), ff());

	cout <<"\nfind_if\n"<<*k;

    return 0;
}

