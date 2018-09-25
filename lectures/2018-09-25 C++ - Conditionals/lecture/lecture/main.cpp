#include <iostream> //print to console, read from keyboard
#include <string>   //gives us string variable type
#include <fstream>  //allows us to write to a file
#include <iomanip>
using namespace std;
int main()
{
    /*
	Agenda: 
		PA #3 Tips
			1. Writing logic to match input
			2. Making sure output window is correct
		Exploring logic through C++ programming challengs:
			*. Check for division by zero
			*. Determining if a number is a 3 digit number
			*. Convert a 12hr time (e.g. 3:00 AM) into 24 hour time
			*. Convert a 24hr time (e.g. 18:35) into 12 hour time
			*. Determining if a character is also a number
			*. Using an array, input 3 numbers from the user, output in sorted order
	*/

    //In comparison to JavaScript, C++ is mostly the same except that it doesn't have
    // the ===.  Instead, we always use ==.  


    //Task 1: prompt user for 2 numbers, divide
    /*int first;
    int second;
    cout << "Enter first number: ";
    cin >> first;
    cout << "Enter second number: ";
    cin >> second;
    if (second == 0)
    {
        cout << "Division by 0 is not allowed." << endl;
    }
    else
    {
        cout << first << " / " << second << " = " << first / second << endl;
    }*/

    //Task: Determining if a number is a 3 digit number or 0
    /*int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num == 0)
    {
        cout << "You entered 0" << endl;
    }
    else if (num / 100 > 0 && num / 100 < 10)
    {
        cout << "You entered a 3 digit number" << endl;
    }*/

    //Task: Convert a 12hr time (e.g. 3:00 AM) into 24 hour time
    //int hour;
    //int minute;
    //string meridian;
    //cout << "Enter an hour: ";
    //cin >> hour;
    //cout << "Enter a minute: ";
    //cin >> minute;
    //cout << "Enter meridian (AM/PM): ";
    //cin >> meridian;
    //if (hour == 12)
    //{
    //    hour = 0;
    //}
    //if (meridian == "PM")
    //{
    //    hour += 12;
    //}

    ////this will give us "pretty" output.  E.g. instead of 1:5 for 1:05, we get
    ////01:05
    //cout << setfill('0') << setw(2) << hour << ":" 
    //    << setfill('0') << setw(2) << minute << endl;

    //Task: go from 24hr time to 12hr time
    /*int hour;
    int minute;
    string meridian = "AM";
    cout << "Enter an hour: ";
    cin >> hour;
    cout << "Enter a minute: ";
    cin >> minute;
    if (hour == 24)
    {
        hour = 12;
    }
    else if (hour >= 12)
    {
        hour -= 12;
        meridian = "PM";
    }
    if (hour == 0)
    {
        hour = 12;
    }
    cout << setfill('0') << setw(2) << hour << ":" 
        << setfill('0') << setw(2) << minute << " " << meridian << endl;*/

    //Given a start time in 12h clock.  Take N minutes, add to time, show 
    //that time.  E.g. 1:00PM + 60 minutes = 2:00PM
    int hour;
    int minute;
    string meridian;
    int duration;
    cout << "Enter an hour: ";
    cin >> hour;
    cout << "Enter a minute: ";
    cin >> minute;
    cout << "Enter meridian (AM/PM): ";
    cin >> meridian;
    cout << "Enter duration in minutes: ";
    cin >> duration;
    if (duration + minute < 60)
    {
        cout << setfill('0') << setw(2) << hour 
            << " : " 
            << setfill('0') << setw(2) << minute + duration 
            << " " << meridian << endl;
    }
    else
    {
        hour += (duration + minute) / 60;
        if (hour >= 12)
        {
            if (hour / 12 % 2 == 1)
            {
                if (meridian == "AM")
                {
                    meridian = "PM";
                }
                else
                {
                    meridian = "AM";
                }
            }
            
            hour = hour % 12;
            if (hour == 0)
            {
                hour = 12;
            }
        }
        minute = (duration + minute) % 60;
        cout << setfill('0') << setw(2) << hour
            << ":"
            << setfill('0') << setw(2) << minute
            << " " << meridian << endl;
    }
}