#include <stdio.h>
#include <string.h>

#define num_id 13
int mapping(int n) { return n; }

struct Node
{
  Node *sons[num_id];
  Node()
  {
    for (int i = 0; i < num_id; i++)
      sons[i] = NULL;
  }
  ~Node()
  {
    for (int i = 0; i < num_id; i++)
      if (sons[i] != NULL)
        sons[i]->~Node();
  }
};

int cnt;

void insert(Node *root, int *str, int lenn)
{
  Node *index = root;
  for (int i = 0; i < lenn; i++)
  {
    if (index->sons[mapping(str[i])] == NULL)
      index->sons[mapping(str[i])] = new Node;
    index = index->sons[mapping(str[i])];
  }
  return;
}

int query(Node *root, int *str, int lenn)
{
  Node *index = root;
  int depth = 0;
  for (int i = 0; i < lenn; i++)
  {
    if (index->sons[mapping(str[i])] == NULL)
      return depth;
    index = index->sons[mapping(str[i])];
    depth++;
  }
  return depth;
}

#define maxn 50007
#define maxm 17

int T;
int n, m, a[maxn][maxm], b[maxm];

int main()
{
  scanf("%d", &T);
  while (T--)
  {
    Node *trie = new Node;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
        scanf("%d", &a[i][j]);
      for (int j = 1; j <= m; j++)
        b[a[i][j]] = j;
      insert(trie, b + 1, m);
    }
    for (int i = 1; i <= n; i++)
      printf("%d ", query(trie, a[i] + 1, m));
    puts("");
  }
  return 0;
}