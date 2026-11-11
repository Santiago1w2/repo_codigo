#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> l_adj = {
        {1, 3}, // 0 A
        {2, 4}, // 1 B
        {5}, // 2 E
        {4, 6}, // 3 C
        {5, 7}, // 4 D
        {8}, // 5 F
        {7}, // 6 I
        {8}, // 7 J
        {}, // 8 K
    };
    vector<bool> visited(l_adj.size(), false);
    stack<int> my_stack;

    my_stack.push(0);

    while (!my_stack.empty()) {
        int x = my_stack.top();
        my_stack.pop();
        if (visited[x]) {
            continue;
        }
        visited[x] = true;

        for (int i = 0; i < l_adj[x].size(); i++) {
            int u = l_adj[x][i];
            my_stack.push(u);
        }
    }
    // lo completamos la siguiente clase con problema rabbit

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}