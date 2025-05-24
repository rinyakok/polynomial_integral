// integration.h
#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <etl/array.h>
#include <etl/vector.h>

// ivector overload
extern float integratePolynomial(const etl::ivector<float>& coeffs, float lowerLimit, float upperLimit);

// function template declaration
template <size_t n>
float integratePolynomial(const etl::array<float, n>& coeffs, float lowerLimit, float upperLimit);

#include "integrator.tpp"


#endif // INTEGRATION_H
