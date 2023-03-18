#include "dijkstra.h"

using namespace std;

int main()
{
  int a[N][N];
  int dist[N];
  int visited[N];
  int closed_cities[N];
  int closed_city;
  int temp;
  int begin_index;
  int end_index;

  std::cout << "Input Start Point: ";
  std::cin >> begin_index;
  std::cout << "Input Finish Point: ";
  std::cin >> end_index;
  begin_index--;
  end_index--;

  for (int i = 0; i < N; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j < N; j++)
    {
      std::cout << "Type distance " << i + 1 << " - " << j + 1 << ": ";
      std::cin >> temp;
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      std::cout << a[i][j] << " ";
    std::cout << std::endl;
  }

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
  
  for (int i = 0; i < N; i++)
    if (closed_cities[i] == 1)
      for (int j = 0; j < N; j++)
      {
        a[i][j] = 0;
        a[j][i] = 0;
      }

  Dijkstra(a, visited, dist, temp, begin_index, end_index);

  return 0;
}