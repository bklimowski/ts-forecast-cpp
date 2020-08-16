#include "project/AutoregressiveModel.hpp"
#include "project/LinearRegression.hpp"
#include "project/vecPush.hpp"

arma::mat AutoregressiveModel::laggedMatrix(arma::vec &x, int lag){

    int lagged_n_rows = x.n_rows - lag - 1;
    arma::mat lagged_x = arma::zeros(lag, lagged_n_rows);

    for (int ii = 0; ii < lag; ii++)
    {
        for (int jj = 0; jj < lagged_n_rows; jj++) {
           lagged_x(ii,jj) = x(jj+ii);
        };
    }; 

    return lagged_x.t();
}

AutoregressiveModel::AutoregressiveModel(arma::vec &x, arma::vec &y, int lag): LinearRegression(x, y)
{   
    lag++;
    int lagged_n_rows = x.n_rows - lag - 1;
    arma::mat lagged_x = AutoregressiveModel::laggedMatrix(x, lag);

    X = lagged_x;
    Y = y.head(lagged_n_rows);
    ts = x;
    reg_lag = lag;
}

float AutoregressiveModel::pointPrediction(arma::mat &x) {
    arma::vec prediction = AutoregressiveModel::predict(x);
    float point_prediction = prediction(prediction.n_rows-1);
    return point_prediction;
}

arma::vec AutoregressiveModel::forecast(int horizon){

    int lag = AutoregressiveModel::reg_lag;
    arma::vec forecast = arma::zeros(horizon);
    arma::mat tmp_x = AutoregressiveModel::X;
    arma::vec tmp_ts = ts;

    for (int ii = 0; ii < horizon; ii++) {
       float point_prediction = AutoregressiveModel::pointPrediction(tmp_x);
       forecast(ii) = point_prediction;
       std::cout<<point_prediction<<std::endl;
       vec_push(tmp_ts, point_prediction);
       std::cout<<tmp_ts<<std::endl;
       tmp_x = AutoregressiveModel::laggedMatrix(tmp_ts, lag);
    }

    return forecast;
}

