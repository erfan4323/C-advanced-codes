#include <iostream>
#include <vector>
#include <ctime>

// Function to check if the array is sorted
bool isSorted(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

// Function to shuffle the array randomly
void shuffleArray(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n; i++) {
        size_t j = i + rand() % (n - i);
        std::swap(arr[i], arr[j]);
    }
}

// Function to perform bogosort
void bogosort(std::vector<int>& arr) {
    srand(time(0)); // Seed the random number generator
    while (!isSorted(arr)) {
        shuffleArray(arr);
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {5, 2, 9, -1, 7};
           
    std::cout << "Array before sorting: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    
    bogosort(arr);
    
    std::cout << "\nArray after sorting: ";
    for (const auto& num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
