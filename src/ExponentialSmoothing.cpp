#include "project/ExponentialSmoothing.hpp"
#include "project/vecPush.hpp"
#include <armadillo>
#include <math.h> 

ExponentialSmoothing::ExponentialSmoothing(arma::vec &time_series, float alpha){
    param_alpha = alpha;
    ts = time_series;
}

arma::vec calculateWeigths(float alpha, int length) {
    arma::vec weigths = arma::zeros(length);
    weigths(0) = alpha;
    for (int ii = 1; ii < length; ii++){
        weigths(ii) = alpha*pow((1-alpha),ii);
    };

    return weigths;
}

void ExponentialSmoothing::fit(){
    weigths = calculateWeigths(param_alpha, ts.n_rows);
}

float weigthedMean(arma::vec &x, arma::vec &weigths){
    float weigthed_mean = arma::sum(x%weigths)/arma::sum(weigths);
    return weigthed_mean;
}

void vec_push(arma::vec &v, float value) {
    arma::vec av(1);
    av.at(0) = value;
    v.insert_rows(v.n_rows, av.row(0));
}

arma::vec ExponentialSmoothing::forecast(int horizon){
    arma::vec forecast = arma::zeros(horizon);
    arma::vec tmp_ts = ts;
    for (int ii = 0; ii < horizon; ii++){
        float point_forecast = weigthedMean(tmp_ts, weigths);
        forecast(ii) = point_forecast;
        vec_push(tmp_ts, )
    }
}