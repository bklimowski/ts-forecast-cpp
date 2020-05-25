#include <armadillo>

class LinearRegression {
    private:
        arma::Mat<double> X, Y;
        arma::colvec coef;        
        bool fit_intercept;
    public:
        LinearRegression(arma::Mat<double> &x, arma::Mat<double> &y);
        void fit(bool fit_intercept);
        arma::colvec predict(arma::Mat<double> &X_pred);
        arma::colvec getCoef() {return coef;}
        //~LinearRegression();
}
