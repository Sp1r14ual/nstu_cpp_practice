#include <iostream>
#include <cstdlib>
#include <limits>
#define INF std::numeric_limits<int>::max()
#define N 6

using namespace std;

void Build_Path(int a[N][N], int dist[N], int begin_index, int end_index)
{
  if (dist[end_index] == INF)
  {
    std::cout << "Path is not found." << std::endl;
    return;
  }

  int ver[N];
  ver[0] = end_index + 1;
  int k = 1;
  int weight = dist[end_index];

  while (end_index != begin_index)
  {
    for (int i = 0; i < N; i++)
      if (a[i][end_index] != 0)
      {
        int temp = weight - a[i][end_index];
        if (temp == dist[i])
        {
          weight = temp;
          end_index = i;
          ver[k] = i + 1;
          k++;
        }
      }
  }

  std::cout << "Path" << std::endl;
  for (int i = k - 1; i >= 0; i--)
    std::cout << ver[i] << " " << std::endl;
}

void Dijkstra(int a[N][N], int visited[N], int dist[N], int temp, int begin_index, int end_index)
{
  int min_index;
  int min;

  do {
    min_index = INF;
    min = INF;
    for (int i = 0; i < N; i++)
    {
      if ((visited[i] == 1) && (dist[i] < min))
      {
        min = dist[i];
        min_index = i;
      }
    }

    if (min_index != INF)
    {
      for (int i = 0; i < N; i++)
      {
        if (a[min_index][i] > 0)
        {
          temp = min + a[min_index][i];
          if (temp < dist[i])
            dist[i] = temp;
        }
      }
      visited[min_index] = 0;
    }
  } while (min_index < INF);

  Build_Path(a, dist, begin_index, end_index);
}