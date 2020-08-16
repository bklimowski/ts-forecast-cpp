#pragma once
#include <armadillo>
#include "project/LinearRegression.hpp"

class AutoregressiveModel: public LinearRegression
{   
    private:
        int reg_lag;
        arma::vec ts;
    public: 
        AutoregressiveModel(arma::vec &x, arma::vec &y, int lag);
        arma::mat laggedMatrix(arma::vec &x, int lag);
        float pointPrediction(arma::mat &x);
        arma::vec forecast(int horizon);
};