class ProductOfNumbers {
    private:
        vector<int> prefix; // Stores prefix product
    public:
        ProductOfNumbers() {
            prefix = {1}; // Initialize with 1 to make division easy
        }
        
        void add(int num) {
            if (num == 0) {
                prefix = {1}; // Reset on zero
            } else {
                prefix.push_back(prefix.back() * num);
            }
        }
        
        int getProduct(int k) {
            if (k >= prefix.size()) return 0; // If k exceeds valid product range
            return prefix.back() / prefix[prefix.size() - 1 - k];
        }
    };    