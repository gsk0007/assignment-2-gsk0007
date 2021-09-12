#include <iostream>
#include <iomanip>

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
	// initialize variabled for calculations
	int minutes,
	    seconds;
	double kph;

	// Get pace in min and sec then calc mph
	cout << "Input your pace in minutes and seconds\n" << "Minutes: ";
	cin >> minutes;
	cout << "Seconds: ";
	cin >> seconds;
	cout << "Your pace in miles per hour: " << convertToMPH(minutes,seconds) << endl;

	// Get pace in kph and calc mph
	cout << "Input your pace in kilometers per hour\n" << "kph: ";
	cin >> kph;
	cout << "Your pace in miles per hour: " << convertToMPH(kph) << endl;

	return 0;
}

double convertToMPH(int minutes, int seconds) {
	// Convert a pace in min and sec to mph
	return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
	// Convert a pace in kph to mph
	return (kph / 1.61);
}
