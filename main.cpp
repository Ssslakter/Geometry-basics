#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct vector
{
	double x, y;
	double Length()
	{
		return sqrt(x * x + y * y);
	}
	vector Normalize()
	{
		double m = Length();
		vector ans;
		ans.x = x / m;
		ans.y = y / m;
		return ans;
	}
	vector Rotate(double angle)
	{
		vector rotated;
		rotated.x = x * cos(angle) - y * sin(angle);
		rotated.y = x * sin(angle) + y * cos(angle);
		return rotated;
	}
};

vector operator +(vector a, vector b)
{
	vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
vector operator *(double c, vector a)
{
	vector b; b.x = c * a.x; b.y = c * a.y;
	return b;
}
vector operator -(vector a, vector b)
{
	return a + (-1) * b;
}
double operator ^(vector a, vector b)
{
	return a.x * b.y - a.y * b.x;
}
double operator *(vector a, vector b)
{
	return a.x * b.x + a.y * b.y;
}

struct line
{
	double a, b, c;
	vector unit_normal_vector()
	{
		vector n;
		n.x = a;
		n.y = b;
		return n.Normalize();
	}
};

vector Intersection(line l1, line l2)
{
	vector ans;
	ans.x = 0;
	ans.y = 0;
	double outer_product = l1.a * l2.b - l2.a * l1.b;
	if (outer_product != 0)
	{
		ans.x = (l1.b * l2.c - l1.c * l2.b) / outer_product;
		ans.y = (l1.c * l2.a - l1.a * l2.c) / outer_product;
	}
	return ans;
}

line LineFromPoints(vector a, vector b)
{
	line ans;
	ans.a = b.y - a.y;
	ans.b = a.x - b.x;
	ans.c = a.y * b.x - a.x * b.y;
	return ans;
}

line LineFromDirection(vector point, vector direction)
{
	line ans;
	ans.a = direction.y;
	ans.b = 0 - direction.x;
	ans.c = direction.x * point.y - direction.y * point.x;
	return ans;
}

int main()
{
	vector a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	vector m = 0.5 * (a + b), n = 0.5 * (a + c);
	line cm = LineFromPoints(c, m), bn = LineFromPoints(b, n);
	vector answer = Intersection(cm, bn);
	cout << setprecision(10) << answer.x << " " << answer.y;
	return 0;
}
