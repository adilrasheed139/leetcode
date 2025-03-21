class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, int> indegree;
            unordered_map<string, vector<string>> graph;
            unordered_set<string> available(supplies.begin(), supplies.end());
            
            // Step 1: Build the graph and in-degree map
            for (int i = 0; i < recipes.size(); i++) {
                for (const string& ingredient : ingredients[i]) {
                    graph[ingredient].push_back(recipes[i]); // ingredient -> recipe
                    indegree[recipes[i]]++; // Increase in-degree for recipes
                }
            }
    
            // Step 2: Topological Sorting using BFS
            queue<string> q;
    
            // Add all available supplies to the queue (they have zero in-degree)
            for (const string& item : supplies) {
                q.push(item);
            }
    
            vector<string> result;
            
            while (!q.empty()) {
                string curr = q.front();
                q.pop();
    
                // If curr is a recipe, add it to the result
                if (find(recipes.begin(), recipes.end(), curr) != recipes.end()) {
                    result.push_back(curr);
                }
    
                // Reduce in-degree for recipes that depend on this ingredient
                for (const string& nextRecipe : graph[curr]) {
                    indegree[nextRecipe]--;
                    
                    // If all required ingredients are available, add to queue
                    if (indegree[nextRecipe] == 0) {
                        q.push(nextRecipe);
                    }
                }
            }
    
            return result;
        }
    };
    