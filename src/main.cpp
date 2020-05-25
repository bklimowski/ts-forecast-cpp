#include "project/LinearRegression.hpp"
#include <armadillo>
#include <iostream>

int main() {
    
    arma::arma_rng::set_seed_random();
    arma::Mat<double> X = arma::randu(20, 2);
    arma::Mat<double> y = X.col(0) + 2 * X.col(1) + 2;

    LinearRegression linreg = LinearRegression(X, y);
    linreg.fit(true);

    std::cout<<linreg.predict(X)<<std::endl;
    std::cout<<linreg.getCoef()<<std::endl;
    return 0;
}
