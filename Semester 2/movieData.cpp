/*
Movie Data

Write a program that uses a structure named MovieData to store the following information
about a movie:
Title
Director
Year Released
Running Time (in minutes)

The program should create two MovieData variables, store values in their members,
and pass each one, in turn, to a function that displays the information about the
movie in a clearly formatted manner.
*/

#include <iostream>
#include <string>

struct MovieData
{
    std::string title;
    std::string director;
    int year;
    int time;
};

void display(const MovieData &movie)
{
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Year Released: " << movie.year << std::endl;
    std::cout << "Running Time (minutes): " << movie.time << std::endl
              << std::endl;
}

int main()
{
    MovieData movie1 = {"Movie1", "Director1", 1, 60};
    MovieData movie2 = {"Movie2", "Director2", 2, 120};

    std::cout << "Movie 1:" << std::endl;
    display(movie1);
    std::cout << "Movie 2:" << std::endl;
    display(movie2);
}