//
// Created by V Buchkov on 6/6/24.
//

#ifndef SCHOOL_OF_QUANTS_PROJECT_LINEARINTERPOLATION_H
#define SCHOOL_OF_QUANTS_PROJECT_LINEARINTERPOLATION_H

#include <vector>

using namespace std;

class LinearInterpolation {
public:
    LinearInterpolation();

    LinearInterpolation(const LinearInterpolation &lin_inter);

    ~LinearInterpolation();

    // вектора передаём именно так, потому что не хотим менять (сортировать) оригинальные вектора
    void SetPoints(const vector<float> &x, const vector<float> &y);

    float GetValue(float x_new);

private:
    vector<float> m_x;
    vector<float> m_y;
};


#endif //SCHOOL_OF_QUANTS_PROJECT_LINEARINTERPOLATION_H
