class Solution {
public:
    bool canAssign(int mid, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - mid, workers.end());
        int pillsLeft = pills;

        for (int i = mid - 1; i >= 0; --i) {
            int task = tasks[i];

            auto it = availableWorkers.lower_bound(task);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);  // assign without pill
            } else {
                if (pillsLeft == 0) return false;
                it = availableWorkers.lower_bound(task - strength);
                if (it == availableWorkers.end()) return false;
                availableWorkers.erase(it);  // assign with pill
                pillsLeft--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};