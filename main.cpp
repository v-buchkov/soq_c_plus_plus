#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "LinearInterpolation.h"

using namespace std;

// передаём указатели на x и y, чтобы поменять их - наполнить значениями
void GetData(const string &path, vector<float> &x, vector<float> &y) {
    ifstream f(path);
    if (f.is_open()) {
        int it = 0;
        string line;
        while (getline(f, line)) {
            if (it == 0) {
                it++;
                continue;
            }

            stringstream s(line);
            string data;
            vector<string> row;

            while (getline(s, data, ',')) {
                row.push_back(data);
            }

            // "заданной набором точек (x, y)" => x - первые, y - вторые
            x.push_back(stof(row[0]));
            y.push_back(stof(row[1]));
        }
    }
    f.close();
}

int main() {
    const string &PATH = "/Users/buchkovv/CLionProjects/school_of_quants_project/data/data.csv";
    float X_POINT = 7.004;

    vector<float> xpoints;
    vector<float> ypoints;

    GetData(PATH, xpoints, ypoints);

    LinearInterpolation lin_inter;
    lin_inter.SetPoints(xpoints, ypoints);

    float y_new = lin_inter.GetValue(X_POINT);
    cout << y_new << endl;

    return 0;
}
