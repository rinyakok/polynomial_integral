#include <etl/vector.h>

// This is a Wrapper Template function to convert etl::array to etl::vector and call ivector
template <size_t n>
float integratePolynomial(const etl::array<float, n>& coeffs, float lowerLimit, float upperLimit) {
    etl::vector<float, n> coeffVec(coeffs.begin(), coeffs.end());
    const etl::ivector<float>& coeffIvec = coeffVec;
    
    return integratePolynomial(coeffIvec, lowerLimit, upperLimit);
}
