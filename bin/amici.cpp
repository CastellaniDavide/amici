/**
 * @file amici.cpp
 *
 * @version 01.01 2020-11-4
 *
 * @brief https://training.olinfo.it/#/task/amici/statement
 *
 * @ingroup amici
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>

//#define DEBUG
using namespace std;

// Variabiles
int N, K, T;
vector <int> amici;
vector <int> next_positions;

void change(vector <int> &actual, vector <int> &pattern)
{
    vector <int> temp(actual.size());
    for(int i = 0; i < actual.size(); ++i)
        temp[i] = actual[i];

    for(int i = 0; i < temp.size(); ++i)
    {
        actual[i] = pattern[actual[i]];
    }
#ifdef DEBUG
    for(int i = 0; i < actual.size(); ++i)
        cout << actual[i] << " ";
    cout << endl;
#endif // DEBUG
}

int get_initial(vector <int> &final_)
{
    sort(final_.begin(), final_.end());
    if (final_[0] != 0)
        return final_[0];

    int result = final_.size();
    while(binary_search(final_.begin(), final_.end(), --result)) {}
    return final_[result];
}

// 9 3 2 2 1 6 3 9 5 4 8 7 1 6 8
// Solution: 8
// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
#ifndef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> N >> K >> T;
    next_positions.resize(N);
    T = T % N;

    for (int i = 0; i < N; ++i)
    {
        cin >> next_positions[i];
        next_positions[i]--;
    }

    for (int i = 0; i < K; ++i)
    {
        int temp;
        cin >> temp;
        amici.push_back(temp - 1);
    }

#ifdef DEBUG
    for(int i = 0; i < amici.size(); ++i)
        cout << amici[i] << " ";
    cout << endl;
#endif // DEBUG

    for (int i = 0; i < T; ++i)
    {
        change(amici, next_positions);
    }

    // Output
    cout << get_initial(amici) << endl;

    // End
    return 0;
}

/*
#define MAXN = 1000000;
#define MAXK = MAXN-1;
#define MAXT = 100000000;

int N, K, T;

int perm[MAXN+1];
int amici[MAXK+1];

int permraised[MAXN+1];
int used[MAXN+1];
int revcicli[MAXN+1];
int indice[MAXN+1];
vector< vector< int > > cicli;

int
main(void)
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  assert(scanf("%d%d%d", &N, &K, &T) == 3);
  for (int i = 0; i < N; ++i)
    {
      assert(scanf("%d", perm+i) == 1);
      --perm[i];
    }
  for (int i = 0; i < K; ++i)
    {
      assert(scanf("%d", amici+i) == 1);
      --amici[i];
    }
  assert(2 <= N && N <= MAXN);
  assert(2 <= K && K <= N-1);
  assert(0 <= T && T <= MAXT);


  for (int i = 0; i < N; ++i)
    if (used[i] == 0)
      {
        vector< int > nuovo;
        int tmp = 0;
        int x = i;
        int rev = cicli.size();
        do
          {
            nuovo.push_back(x);
            revcicli[x] = rev;
            used[x] = 1;
            indice[x] = tmp++;
            x = perm[x];
          } while(x != i);
        permraised[i] = nuovo[T % nuovo.size()];
        cicli.push_back(nuovo);
      }
    else
      {
        permraised[i] = cicli[revcicli[i]]
          [(indice[i] + T) % cicli[revcicli[i]].size()];
      }

  for (int i = 0; i < K; ++i)
    used[permraised[amici[i]]] = 2;

  if (used[0] == 2)
    if (used[N-1] == 2)
      {
        for (int i = 2; i < N; ++i)
          if (used[i-1] != 2 && used[i] == 2)
            {
              printf("%d\n", i+1);
              return 0;
            }
      }
    else
      printf("1\n");
  else
    for (int i = 1; i < N; ++i)
      if (used[i] == 2)
        {
          printf("%d\n", i+1);
          return 0;
        }
  return 1;
}
*/
