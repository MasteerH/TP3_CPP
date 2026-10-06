#pragma once

class Vector
{
public:
	Vector();
	Vector(const Vector& v);
	Vector(Vector&& v);
	Vector(const double *tab, unsigned int size);
	~Vector();
	Vector& operator=(const Vector& v);
	Vector& operator=(Vector&& v);
	inline const double* GetVector() const { return(Vec); }
	inline unsigned int GetSize() const { return(Size); }
	void AddData(double d);
	void AddVector(const double* v, unsigned int size);
	void ReplaceVector(const double* v, unsigned int size);
	void Reserve(unsigned int size);
	inline double& operator[](unsigned int i) { return(Vec[i]); }
	inline double operator[](unsigned int i) const { return(Vec[i]); }
	void Homothecy(double h);
	double Norm();
	static double EuclideanDistance(const Vector& v1, const Vector& v2);
	Vector operator*=(double v);
	Vector operator-() const;
	Vector operator/(double v) const;
	bool operator==(const Vector& v) const;
	bool operator!=(const Vector& v) const;

private:
	double* Vec;
	unsigned int Size;
};

Vector operator+(const Vector &v1, const Vector &v2);
Vector operator-(const Vector &v1, const Vector &v2);
double operator*(const Vector &v1, const Vector &v2);
