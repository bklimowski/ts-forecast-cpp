#include "project/LinearRegression.hpp"
#include "project/AutoregressiveModel.hpp"
#include "project/ExponentialSmoothing.hpp"
#include <armadillo>
#include <iostream>

int main() {
    
    arma::arma_rng::set_seed_random();
    arma::vec X = arma::randu(10, 1);
    arma::vec y = X.col(0) + 2 * X.col(0) + 2;

    
    ExponentialSmoothing expsmth = ExponentialSmoothing(y, 0.2);
    expsmth.fit();
    std::cout<<expsmth.getWeigths()<<std::endl;

    // AutoregressiveModel linreg = AutoregressiveModel(X, y, 3);
    // linreg.fit(true);

    // std::cout<<linreg.forecast(3)<<std::endl;
    // std::cout<<linreg.getCoef()<<std::endl;

    return 0;
}
