#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <limits>
#define INF std::numeric_limits<int>::max()
#define N 6

void Build_Path(int a[N][N], int dist[N], int begin_index, int end_index)
{
  if (dist[end_index] == INF)
  {
    std::cout << "Path is not found." << std::endl;
    return;
  }

  // Восстановление пути
  int ver[N]; // массив посещенных вершин
  ver[0] = end_index + 1; // начальный элемент - конечная вершина
  int k = 1; // индекс предыдущей вершины
  int weight = dist[end_index]; // вес конечной вершины

  while (end_index != begin_index) // пока не дошли до начальной вершины
  {
    for (int i = 0; i < N; i++) // просматриваем все вершины
      if (a[i][end_index] != 0)   // если связь есть
      {
        int temp = weight - a[i][end_index]; // определяем вес пути из предыдущей вершины
        if (temp == dist[i]) // если вес совпал с рассчитанным
        {                 // значит из этой вершины и был переход
          weight = temp; // сохраняем новый вес
          end_index = i;       // сохраняем предыдущую вершину
          ver[k] = i + 1; // и записываем ее в массив
          k++;
        }
      }
  }

  // Вывод пути (начальная вершина оказалась в конце массива из k элементов)
  std::cout << "Shortest Path" << std::endl;
  for (int i = k - 1; i >= 0; i--)
    std::cout << ver[i] << " " << std::endl;
}

void Dijkstra(int a[N][N], int visited[N], int dist[N], int temp, int begin_index, int end_index)
{
  int min_index;
  int min;

  // Шаг алгоритма
  do {
    min_index = INF;
    min = INF;
    for (int i = 0; i < N; i++)
    { // Если вершину ещё не обошли и вес меньше min
      if ((visited[i] == 1) && (dist[i] < min))
      { // Переприсваиваем значения
        min = dist[i];
        min_index = i;
      }
    }
    // Добавляем найденный минимальный вес
    // к текущему весу вершины
    // и сравниваем с текущим минимальным весом вершины
    if (min_index != INF)
    {
      for (int i = 0; i < N; i++)
      {
        if (a[min_index][i] > 0)
        {
          temp = min + a[min_index][i];
          if (temp < dist[i])
          {
            dist[i] = temp;
          }
        }
      }
      visited[min_index] = 0;
    }
  } while (min_index < INF);

  // Вывод кратчайших расстояний до вершин
  std::cout << "Shortest Distances to Vertices: " << std::endl;
  for (int i = 0; i < N; i++)
    std::cout << dist[i] << " ";
  std::cout << std::endl;

  Build_Path(a, dist, begin_index, end_index);
}

int main()
{
  int a[N][N]; // матрица связей
  int dist[N]; // минимальное расстояние
  int visited[N]; // посещенные вершины
  int closed_cities[N];
  int closed_city;
  int temp;
  int begin_index; //индекс начальной вершины
  int end_index; //индекс конечной вершины

  std::cout << "Input Start Point: ";
  std::cin >> begin_index;
  std::cout << "Input Finish Point: ";
  std::cin >> end_index;
  begin_index--;
  end_index--;

  // Инициализация матрицы связей
  for (int i = 0; i < N; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j < N; j++)
    {
      std::cout << "Type Distance " << i + 1 << " - " << j + 1 << ": ";
      std::cin >> temp;
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  // Вывод матрицы связей
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      std::cout << a[i][j] << " ";
    std::cout << std::endl;
  }

  //Инициализация вершин и расстояний
  for (int i = 0; i < N; i++)
  {
    dist[i] = INF;
    visited[i] = 1;
    closed_cities[i] = 0;
  }
  dist[begin_index] = 0;

  //ввод закрытых городов
  std::cout << "Type Closed Cities (0 to stop)" << std::endl;
  do
  {
    std::cin >> closed_city;
    if (closed_city == 0)
      break;
    if (!(closed_city > 0 && closed_city < N + 1))
    {
      std::cout << "Error" << std::endl;
      exit(1);
    }
    closed_cities[closed_city - 1] = 1;    
  } while(closed_city != 0);

  //"выбрасываем" закрытые города из матрицы связей
  for (int i = 0; i < N; i++)
  {
    if (closed_cities[i] == 1)
    {
      for (int j = 0; j < N; j++)
      {
        a[i][j] = 0;
        a[j][i] = 0;
      }
    }
  }

  Dijkstra(a, visited, dist, temp, begin_index, end_index);

  return 0;
}