#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

__gnu_pbds::tree<std::pair<int, int>, __gnu_pbds::null_type, std::less<std::pair<int, int>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> tr;

int n, mode, x;
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d%d", &mode, &x);
    if (mode == 1)
      tr.insert({x, i});
    else if (mode == 2)
      tr.erase(tr.lower_bound({x, 0}));
    else if (mode == 3)
      printf("%d\n", tr.order_of_key({x, 0}) + 1);
    else if (mode == 4)
      printf("%d\n", tr.find_by_order(x - 1)->first);
    else if (mode == 5)
      printf("%d\n", ((--tr.lower_bound({x, 0}))->first));
    else if (mode == 6)
      printf("%d\n", tr.upper_bound({x, 2147483647})->first);
  }
}