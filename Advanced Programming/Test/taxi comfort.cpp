#include <iostream>
#include <vector>
#include <algorithm>

int calculateDiscomfort(const std::vector<int>& destinations) {
    int discomfort = 0;
    int remainingPassengers = destinations.size();
    int frontSeatPassenger = destinations[0];

    for (int i = 1; i < destinations.size(); i++) {
        int currentDestination = destinations[i];

        if (currentDestination <= frontSeatPassenger) {
            discomfort += remainingPassengers;
            remainingPassengers--;
        } else {
            frontSeatPassenger = currentDestination;
        }
    }

    return discomfort;
}

int assignFrontSeat(std::vector<int>& destinations) {
    int minDiscomfort = calculateDiscomfort(destinations);
    int frontSeatIndex = 0;

    for (int i = 1; i < destinations.size(); i++) {
        std::swap(destinations[0], destinations[i]);
        int discomfort = calculateDiscomfort(destinations);

        if (discomfort < minDiscomfort) {
            minDiscomfort = discomfort;
            frontSeatIndex = i;
        }

        std::swap(destinations[0], destinations[i]);
    }

    return frontSeatIndex;
}

int main() {
    int n; 
    std::cout << "Enter the number of taxis: ";
    std::cin >> n;

    std::vector<int> destinations(4 * n);

    std::cout << "Enter the destinations of each passenger:\n";
    for (int i = 0; i < 4 * n; i++) {
        std::cout << "Passenger " << i + 1 << ": ";
        std::cin >> destinations[i];
    }

    std::vector<int> discomforts(n);

    for (int i = 0; i < n; i++) {
        std::vector<int> taxi_destinations(destinations.begin() + (4 * i), destinations.begin() + (4 * i) + 4);
        discomforts[i] = calculateDiscomfort(taxi_destinations);
    }

    std::cout << "Minimized discomfort for each taxi:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Taxi " << i + 1 << ": " << discomforts[i] << std::endl;
    }

    return 0;
}
