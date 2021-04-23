// 计算从起点start到终点target的最近距离
int BFS(TreeNode *start, TreeNode *target)
{
    queue<TreeNode*> q;
    set<TreeNode*> visited;  // 已访问的点

    q.push(start);
    visited.insert(start);
    int step = 0;

    while (!q.empty()) {
        int size = q.size(); // 遍历一层
        for (int i = 0; i < size; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->val == target->val) {
                return step;
            }

            if (cur->left && visited.find(cur->left) == visited.end()) {
                q.push(cur->left);
            }
            if (cur->right && visited.find(cur->right) == visited.end()) {
                q.push(cur->right);
            }
        }
        step++;
    }
  return step;
}
