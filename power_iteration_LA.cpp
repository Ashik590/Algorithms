#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

double calculate_magnitude(vector<double> vec)
{
    double mag = 0;

    for (auto e : vec)
        mag += e * e;

    return sqrt(mag);
}

vector<double> multiply(vector<vector<double>> matrix, vector<double> x)
{
    int n = x.size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[j][i] *= x[i];

    vector<double> newX(n, 0);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            newX[i] += matrix[i][j];

    return newX;
}

vector<double> normalize(vector<double> vec)
{
    double magnitude = calculate_magnitude(vec);

    int n = vec.size();
    for (int i = 0; i < n; i++)
        vec[i] /= magnitude;

    return vec;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    vector<double> intial_vector(n, 0);
    intial_vector[0] = 1;

    vector<double> x = intial_vector;
    double oldLembda;

    double newLembda = calculate_magnitude(x);
    double ε = 1e-6;
    vector<double> y;
    do
    {
        oldLembda = newLembda;
        y = multiply(matrix, x);
        newLembda = calculate_magnitude(y);

        x = normalize(y);

    } while (abs(newLembda - oldLembda) > ε);

    cout << "Largest Eigen Value = " << newLembda << nl;

    cout << "Corresponding Eigen vector = ( ";
    for (auto e : y)
        cout << e << ", ";

    cout << ")^T " << nl;

        return 0;
}