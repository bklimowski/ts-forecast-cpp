#pragma once
#include <armadillo>

class LinearRegression
{
protected:
    arma::mat X;
    arma::vec Y, coef;
    bool fit_intercept;

public:
    LinearRegression(arma::mat &x, arma::vec &y);
    void fit(bool fit_intercept);
    arma::vec predict(arma::mat &X_pred);
    arma::vec getCoef() const { return coef; }
    //~LinearRegression();
};
