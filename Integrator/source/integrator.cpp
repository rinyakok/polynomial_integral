#ifndef NUMERICAL_INTEGRATION_H
#define NUMERICAL_INTEGRATION_H

#include <etl/vector.h>
#include "integrator.h"

// Computes x^n using Horner's method (for n >= 0)
float power(float x, int n) {
    float result = 1.0f;
    while (n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }
        x *= x;
        n /= 2;
    }
    return result;
}

// Function to perform polynomial integration
float integratePolynomial(const etl::ivector<float>& coeffs, const float lowerLimit, const float upperLimit) {
    float result = 0.0f;

    for (size_t i = 0; i < coeffs.size(); ++i) {
        // etl::power is not suitable for runtime exponentiation that's why own power function is used
        float term_upper = power(upperLimit, (i + 1));
        float term_lower = power(lowerLimit, (i + 1));
        result += (coeffs[i] / (i + 1)) * (term_upper - term_lower);
    }

    return result;
}

#endif // NUMERICAL_INTEGRATION_H
