#include <iostream>
#include <iomanip>
using namespace std;

void input_matrix(double** a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

}

void input_vector(double* x, int n)
{
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

double first_component(double** a, double** b, double* x, double* y, int n, double* By)
{
    //(Ax, By)
    double* Ax = new double[n];
    for (int i = 0; i < n; i++)
    {
        Ax[i] = 0;

        for (int j = 0; j < n; j++)
            Ax[i] = Ax[i] + a[i][j] * x[j];
    }

//  double* By = new double[n];
    for (int i = 0; i < n; i++)
    {
        By[i] = 0;

        for (int j = 0; j < n; j++)
            By[i] = By[i] + b[i][j] * y[j];
    }

    double first_component = 0;
    for (int i = 0; i < n; i++)
        first_component = first_component + Ax[i] * By[i];
    
    return first_component;
}

double second_component(double** c, double* x, double* y, int n)
{
    //(Cx,y)
    double* Cx = new double[n];
    for (int i = 0; i < n; i++)
    {
        Cx[i] = 0;
        for (int j = 0; j < n; j++)
            Cx[i] = Cx[i] + c[i][j] * x[j];
    }
    
    double second_component = 0;
    for (int i = 0; i < n; i++)
        second_component = second_component + Cx[i] * y[i];
    
    return second_component;
}

double third_component(double** b, double* x, double* y, int n, double* By)
{
    //(x,By)
    double third_component = 0;
    for (int i = 0; i < n; i++)
        third_component = third_component + x[i] * By[i];
    
    return third_component;

}

double solve(double** a, double** b, double** c, double* x, double* y, int n)
{
    double* By = new double[n];
    return first_component(a, b, x, y, n, By) + second_component(c, x, y, n) / third_component(b, x, y, n, By);
}

int main()
{

    int n;
    cout << "Введите размерность матриц A, B, C и векторов X, Y:" << endl;
    cin >> n;
    double** a = new double*[n]; 
    double** b = new double*[n]; 
    double** c = new double*[n]; 
    double* x = new double[n];
    double* y = new double[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new double[n];
        b[i] = new double[n];
        c[i] = new double[n];
    
    }
    
    cout << "Введите элементы матрицы A слева направо, сверху вниз:" << endl;
    input_matrix(a, n);

    cout << "Введите элементы матрицы B слева направо, сверху вниз:" << endl;
    input_matrix(b, n);
    
    cout << "Введите элементы матрицы C слева направо, сверху вниз:" << endl;
    input_matrix(c, n);
    
    cout << "Введите координаты вектора X:" << endl;
    input_vector(x, n);
    
    cout << "Введите координаты вектора Y:" << endl;
    input_vector(y, n);
   
    double result = solve(a, b, c, x, y, n);

    cout << setprecision(8) << "(Ax, By) + (Cx,y) / (x,By) = " << result << endl;
    
    return 0;
}