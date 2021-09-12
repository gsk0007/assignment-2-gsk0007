#include <iostream>;
#include <iomanip>;

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
	int minutes = 0,
	    seconds = 0;
	double kph = 0.0;



	return 0;
}

double convertToMPH(int minutes, int seconds) {
	// There are 3600 seconds in an hour
	return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
	return (kph / 1.61);
}
