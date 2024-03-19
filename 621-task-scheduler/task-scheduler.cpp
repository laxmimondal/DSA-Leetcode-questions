class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> taskCount;
        
        // Count the frequency of each task
        for (char task : tasks) {
            ++taskCount[task];
        }
        
        // Find the task with the highest frequency
        int maxFrequency = 0;
        for (const auto& [task, count] : taskCount) {
            maxFrequency = std::max(maxFrequency, count);
        }
        
        // Count the number of tasks with the same highest frequency
        int numMaxFrequencyTasks = 0;
        for (const auto& [task, count] : taskCount) {
            if (count == maxFrequency) {
                ++numMaxFrequencyTasks;
            }
        }
        
        // Calculate the minimum number of intervals required
        int minIntervals = (maxFrequency - 1) * (n + 1) + numMaxFrequencyTasks;
        
        // Return the maximum of the minimum intervals and the total number of tasks
        return std::max(minIntervals, static_cast<int>(tasks.size()));
    }
};