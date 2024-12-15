#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Define a max-heap with custom comparator for maximum gain
        auto gain = [](vector<int>& cls) {
            int pass = cls[0], total = cls[1];
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };
        priority_queue<pair<double, vector<int>>> maxHeap;
        
        // Push all classes into the heap with their initial gain
        for (auto& cls : classes) {
            maxHeap.push({gain(cls), cls});
        }
        
        // Distribute extra students
        while (extraStudents-- > 0) {
            auto [currentGain, cls] = maxHeap.top();
            maxHeap.pop();
            cls[0]++; // Increase passi
            cls[1]++; // Increase totali
            maxHeap.push({gain(cls), cls}); // Recompute gain and push back
        }
        
        // Compute the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, cls] = maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)cls[0] / cls[1];
        }
        
        return totalRatio / classes.size();
    }
};
