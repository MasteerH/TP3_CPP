#include "Vector.h"
#include <cstdlib>
#include <iostream>
#include <cmath>

Vector::Vector() : Vec(nullptr), Size(0)
{
	//std::cout << "Vector::Vector()" << std::endl;
}

Vector::Vector(const Vector& v)
{
	//std::cout << "Vector::Vector(const Vector &v)" << std::endl;

	Size = v.Size;
	Vec = (double*)malloc(Size * sizeof(double));
	for (unsigned int i = 0; i < v.Size; ++i) Vec[i] = v.Vec[i];
}

Vector::Vector(Vector&& v) : Vec(v.Vec), Size(v.Size)
{
	//std::cout << "Vector::Vector(Vector&& v)" << std::endl;

	v.Vec = nullptr;
	v.Size = 0;
}

Vector::Vector(const double* tab, unsigned int size)
{
	//std::cout << "Vector::Vector(const double* tab, unsigned int size)" << std::endl;

	Size = size;
	Vec = (double*)malloc(size * sizeof(double));
	for (unsigned int i = 0; i < size; ++i) Vec[i] = tab[i];
}

Vector::~Vector()
{
	//std::cout << "Vector::~Vector()" << std::endl;

	free(Vec);
}

Vector& Vector::operator=(const Vector& v)
{
	//std::cout << "Vector& Vector::operator=(const Vector& v)" << std::endl;

	if (this == &v) return(*this);

	Size = v.Size;
	free(Vec);
	Vec = (double*)malloc(Size * sizeof(double));
	for (unsigned int i = 0; i < v.Size; ++i) Vec[i] = v.Vec[i];

	return(*this);
}

Vector& Vector::operator=(Vector&& v)
{
	//std::cout << "Vector& Vector::operator=(Vector&& v)" << std::endl;

	if (this == &v) return(*this);

	free(Vec);
	Vec = v.Vec;
	Size = v.Size;
	v.Vec = nullptr;
	v.Size = 0;

	return(*this);
}

void Vector::AddData(double d)
{
	Size++;
	Vec = (double*)realloc(Vec, Size * sizeof(double));
	Vec[Size - 1] = d;
}

void Vector::AddVector(const double* v, unsigned int size)
{
	Vec = (double*)realloc(Vec, (Size+size) * sizeof(double));
	for (unsigned int i = 0; i < size; ++i) Vec[Size + i] = v[i];
	Size += size;
}

void Vector::ReplaceVector(const double* v, unsigned int size)
{
	Size = size;
	free(Vec);
	Vec = (double*)malloc(Size * sizeof(double));
	for (unsigned int i = 0; i < size; ++i) Vec[i] = v[i];
}

void Vector::Reserve(unsigned int size)
{
	Size = size;
	Vec = (double*)realloc(Vec, Size * sizeof(double));
}

void Vector::Homothecy(double h)
{
	for (unsigned int i = 0; i < Size; ++i) Vec[i] *= h;
}

double Vector::Norm()
{
	double norm = 0;

	for (unsigned int i = 0; i < Size; ++i) norm += Vec[i] * Vec[i];
	norm = std::sqrt(norm);

	return norm;
}

double Vector::EuclideanDistance(const Vector& v1, const Vector& v2)
{
	if (v1.Size != v2.Size)
	{
		printf("Les deux vecteurs ne sont pas de meme dimension\n");
		return 0;
	}

	double dist = 0;

	for (unsigned int i = 0; i < v1.Size; ++i) dist += (v2.Vec[i] - v1.Vec[i]) * (v2.Vec[i] - v1.Vec[i]);
	dist = std::sqrt(dist);

	return dist;
}

Vector Vector::operator*=(double v) {
	for (unsigned int i = 0; i < Size; i++) {
		Vec[i] *= v;
	}
	return *this;
}

Vector Vector::operator-() const {

	Vector Vres = *this;
	for (unsigned int i = 0; i < Size; i++) {Vres[i] = -Vec[i];}
	return Vres;
}

Vector Vector::operator/(double v) const {

	Vector Vres = *this;
	if (v == 0) {
		std::cerr << "Division par 0 impossible" << std::endl;
		return Vres;
	}
	for (unsigned int i = 0; i < Size; i++) {Vres[i] = Vec[i] / v;}
	return Vres;
}

bool Vector::operator==(const Vector& v) const {

	if (Size != v.Size) return false;
	for (unsigned int i = 0; i < Size; i++) {
		if (Vec[i] != v.Vec[i]) return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& v) const {

	return !(*this == v);
}

Vector operator+(const Vector &v1, const Vector &v2) {

	if (v1.GetSize() != v2.GetSize()) {
		std::cerr << "Les deux vecteurs ne sont pas de meme dimension" << std::endl;
		return Vector();
	}
	Vector Vres = v1;
	for (unsigned int i = 0; i<Vres.GetSize(); i++){Vres[i] = v1[i] + v2[i];}
	return Vres;
}

Vector operator-(const Vector &v1, const Vector &v2) {

	if (v1.GetSize() != v2.GetSize()) {
		std::cerr << "Les deux vecteurs ne sont pas de meme dimension" << std::endl;
		return Vector();
	}
	Vector Vres = v1;
	for (unsigned int i = 0; i<Vres.GetSize(); i++){Vres[i] = v1[i] - v2[i];}
	return Vres;
}

double operator*(const Vector &v1, const Vector &v2) {

	if (v1.GetSize() != v2.GetSize()) {
		std::cerr << "Les deux vecteurs ne sont pas de meme dimension" << std::endl;
		return 0;
	}
	double res = 0;
	for (unsigned int i = 0; i<v1.GetSize(); i++){res += v1[i] * v2[i];}
	return res;
}