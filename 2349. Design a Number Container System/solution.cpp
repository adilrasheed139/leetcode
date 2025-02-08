#include <unordered_map>
#include <set>

class NumberContainers {
public:
    std::unordered_map<int, int> index_to_number;
    std::unordered_map<int, std::set<int>> number_to_indices;

    NumberContainers() {}

    void change(int index, int number) {
        // If the index already has a number, remove it from the previous number's set
        if (index_to_number.count(index)) {
            int old_number = index_to_number[index];
            number_to_indices[old_number].erase(index);
            if (number_to_indices[old_number].empty()) {
                number_to_indices.erase(old_number);
            }
        }
        
        // Update mappings
        index_to_number[index] = number;
        number_to_indices[number].insert(index);
    }

    int find(int number) {
        if (number_to_indices.count(number) && !number_to_indices[number].empty()) {
            return *number_to_indices[number].begin();  // Return the smallest index
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
