/*
Hotel Occupancy

Write a program that calculates the occupancy rate for a hotel. The program should start by asking the user how many floors the 
hotel has.  A loop should then iterate once for each floor. In each iteration, the loop should ask the user for the number of rooms
on the floor and how many of them are occupied. After all the iterations, the program should display how many rooms the hotel has,
how many of them are occupied, how many are unoccupied, and the percentage of rooms that are occupied. The percentage may be 
calculated by dividing the number of rooms occupied by the number of rooms.

NOTE: It is traditional that most hotels do not have a thirteenth floor. The loop in this program should skip the entire thirteenth
iteration.
*/

#include <iostream>

int main()
{
    int floors;
    int rooms = 0;
    int occupied = 0;
    int unoccupied;
    double unoccupiedPercentage;

    std::cout << "How many floors does the hotel have?" << std::endl;
    std::cin >> floors;

    for (int i = 1; i <= floors; i++)
    {
        if (i == 13)
        {
            continue;
        }

        int floorRooms;
        int occupiedRooms;

        std::cout << "How many rooms are in floor " << i << "?" << std::endl;
        std::cin >> floorRooms;
        std::cout << "How many rooms are occupied?" << std::endl;
        std::cin >> occupiedRooms;

        rooms += floorRooms;
        occupied += occupiedRooms;
    }

    unoccupied = rooms - occupied;
    unoccupiedPercentage = (static_cast<double>(occupied) / rooms) * 100;

    std::cout << "Total Number of Rooms: " << rooms << std::endl;
    std::cout << "Total Number of Occupied Rooms: " << occupied << std::endl;
    std::cout << "Total Number of Unoccupied Rooms: " << unoccupied << std::endl;
    std::cout << "Percantage of Occupied Rooms: " << unoccupiedPercentage << "%" << std::endl;

    return 0;
}