class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        vector<int> indegrees (numCourses, 0);
        for (vector<int>& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegrees[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            count++;
            for (auto it : adj[t]) {
                indegrees[it]--;
                if (indegrees[it] == 0) q.push(it);
            }
        }
        return count == numCourses;
         
    }
};
