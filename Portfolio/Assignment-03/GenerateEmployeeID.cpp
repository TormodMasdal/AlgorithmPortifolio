#include <random>
#include "GenerateEmployeeID.h"

#include <unordered_set>

// Function only visible in this file
static std::mt19937& GetPRNG() {
    static std::mt19937 engine{ std::random_device{}() };
    return engine;
}

// Keep track of used IDs
static std::unordered_set<int> usedIDs;

int GenerateEmployeeID() {
    std::uniform_int_distribution<int> dist(100,  999); // Generate a 3 digit id
    int id;
    do {
        id = dist(GetPRNG());
    }
    while (usedIDs.count(id) != 0);  // Try again if already used

    usedIDs.insert(id);
    return id;
}
