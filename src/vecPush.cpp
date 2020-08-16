#pragma once
#include <armadillo>
#include "project/vecPush.hpp"

void vec_push(arma::vec &v, float value) {
    arma::vec av(1);
    av.at(0) = value;
    v.insert_rows(v.n_rows, av.row(0));
}