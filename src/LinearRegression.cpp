#include "project/LinearRegression.hpp"
#include <armadillo>

LinearRegression::LinearRegression(arma::mat &x,
                                   arma::vec &y){

    X = x;
    Y = y;
}

void LinearRegression::fit(bool fit_inter = true){
    fit_intercept = fit_inter;
    if(fit_intercept){
        coef = arma::solve(
                arma::join_rows(arma::ones(X.n_rows, 1), X),
                Y);
    } else {
        coef = arma::solve(X, Y);
    }
}

arma::colvec LinearRegression::predict(arma::mat &X_pred){
    if(fit_intercept) {        
        return arma::join_rows(
                arma::ones(X_pred.n_rows, 1),
                X_pred)*coef;
    }
    else{
        return X_pred*coef;
    }
}
