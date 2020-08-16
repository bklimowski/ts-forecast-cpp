#pragma once
#include<armadillo>

class ExponentialSmoothing {

    private:
        float param_alpha;
        arma::vec ts, weigths;
    public:
        ExponentialSmoothing(arma::vec &time_series, float alpha);
        void fit();
        arma::vec forecast(int horizon);
        arma::vec getWeigths() {return weigths;}

};
