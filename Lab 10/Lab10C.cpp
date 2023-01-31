/*
Author: Lubna Asha
Course: CSCI-136
Instructor: Tong Yi
Assignment: Lab 10 A

This code implements two functions:
- first function reports number of minutes
away from midnight
- second function recieves two time arguements
and reports how many minutes they are away from 
each other
*/

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Time { 
    public:
        int h;
        int m;
};
class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};
class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

//int minutesSinceMidnight(Time time);
//int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
void printTimeSlot(TimeSlot ts);
void printMovie(Movie mv);

/*
int minutesSinceMidnight(Time time) //calculates the amount of minutes the inputted time is after midnight (00:00)
{
    int minutes = (time.h * 60) + time.m;
    return minutes;
}
int minutesUntil(Time earlier, Time later) //calculates the difference between the two times in minutes
{
    int minutes = (later.h - earlier.h) * 60;
    minutes = minutes +  (later.m - earlier.m);
    return minutes;
}
*/
Time addMinutes(Time time0, int min)
{
    int minutes = time0.m + min;
    int new_minutes = minutes % 60;
    int new_hour = time0.h + minutes/60;
    Time newtime = {new_hour, new_minutes};
    return newtime;
}


void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
    Time endingTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);

    cout << "[starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endingTime.h << ":" << endingTime.m << "]" << endl;
}

int main()
{
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    Movie movie3 = {"Om Shanti Om", DRAMA, 162};
    Movie movie4 = {"Bulbbul", THRILLER, 94};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}}; 
    TimeSlot afternoon = {movie3, {19, 45}};
    TimeSlot nighttime = {movie4, {10, 00}};

    printMovie(movie1); printTimeSlot(morning);
    printMovie(movie2); printTimeSlot(daytime);
    printMovie(movie2); printTimeSlot(evening);
    printMovie(movie3); printTimeSlot(afternoon);
    printMovie(movie4); printTimeSlot(nighttime);
}