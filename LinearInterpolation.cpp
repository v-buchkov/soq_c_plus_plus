//
// Created by V Buchkov on 6/6/24.
//

#include "LinearInterpolation.h"
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

LinearInterpolation::LinearInterpolation() {}

LinearInterpolation::LinearInterpolation(const LinearInterpolation &lin_inter) {
    m_x = lin_inter.m_x;
    m_y = lin_inter.m_y;
}

LinearInterpolation::~LinearInterpolation() {}

void LinearInterpolation::SetPoints(const vector<float> &x, const vector<float> &y) {
    // создаём вектор под индексы, которые будут соответствовать порядку сортировки вектора x
    vector<int> indices(x.size());
    // заполняем индексы от 0 до размера вектора x (и, соответственно, вектора y) с шагом 1
    iota(indices.begin(), indices.end(), 1);

    // сортируем индексы по кастомному правилу - сравнению значений вектора x, соотвестсвующих данным индексам
    std::sort(indices.begin(), indices.end(), [&](int i, int j) { return x[i] < x[j]; });

    // заполняем внутренние вектора согласно индексам
    // таким образом, x будет отсортирован, а порядок y будет соответствовать порядку x
    for (int idx: indices) {
        m_x.push_back(x[idx]);
        m_y.push_back(y[idx]);
    }
}

float LinearInterpolation::GetValue(float x_new) {
    if (x_new < m_x.front() or x_new > m_x.back()) {
        cout << "Value of x′ is outside of the domain" << endl;
        return -9999.;
    }

    // найдём индекс левой границы интервала [x0; x1], где лежит x_new
    int idx_x0 = upper_bound(m_x.begin(), m_x.end(), x_new) - m_x.begin() - 1;

    float x0 = m_x[idx_x0];
    float x1 = m_x[idx_x0 + 1];

    float y0 = m_y[idx_x0];
    float y1 = m_y[idx_x0 + 1];

    // посчитаем по формуле из задания
    return y0 * (x_new - x1) / (x0 - x1) + y1 * (x_new - x0) / (x1 - x0);
}
