#include <iostream>
using namespace std;

int main()
{

    int n, a[n][n], b[n][n], c[n][n], x[n], y[n];
    cout << "Введите размерность матриц A, B, C и векторов X, Y:" << endl;
    cin >> n;
    
    cout << "Введите элементы матрицы A слева направо, сверху вниз:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout << "Введите элементы матрицы B слева направо, сверху вниз:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
    
    cout << "Введите элементы матрицы C слева направо, сверху вниз:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    
    cout << "Введите координаты вектора X:" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    
    cout << "Введите координаты вектора Y:" << endl;
    for (int i = 0; i < n; i++)
        cin >> y[i];
    
    //(Ax, By)
    int Ax[n];
    for (int i = 0; i < n; i++)
    {
        Ax[i] = 0;

        for (int j = 0; j < n; j++)
            Ax[i] = Ax[i] + a[i][j] * x[j];
    }

    int By[n];
    for (int i = 0; i < n; i++)
    {
        By[i] = 0;

        for (int j = 0; j < n; j++)
            By[i] = By[i] + b[i][j] * y[j];
    }

    int first_component = 0;
    for (int i = 0; i < n; i++)
        first_component = first_component + Ax[i] * By[i];
    
    //(Cx,y)
    int Cx[n];
    for (int i = 0; i < n; i++)
    {
        Cx[i] = 0;
        for (int j = 0; j < n; j++)
            Cx[i] = Cx[i] + c[i][j] * x[j];
    }
    
    int second_component = 0;
    for (int i = 0; i < n; i++)
        second_component = second_component + Cx[i] * y[i];
    
    //(x,By)
    int third_component = 0;
    for (int i = 0; i < n; i++)
        third_component = third_component + x[i] * By[i];
    
    double result = first_component + second_component / third_component;

    cout << "(Ax, By) + (Cx,y) / (x,By) = " << result << endl;
    
    return 0;
}