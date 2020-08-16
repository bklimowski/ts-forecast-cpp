#pragma once
#include<armadillo>

class ExponentialSmoothing {

    private:
        arma::colvec ts, weigths;
    public:
        ExponentialSmoothing(arma::colvec &time_series);
        fit(double alpha);
        predict(int horizon)
}
