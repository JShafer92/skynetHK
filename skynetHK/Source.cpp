#include <cstdlib> 
#include <ctime> 
#include <string>
#include <iostream>

using namespace std;

int main()
{

	// reset seed each time program is launched
	srand((unsigned)time(0));
	// Set the searchGridLowNumber as an integer so that it may be used later
	int searchGridLowNumber = 1;
	// Set the searchGridHighNumber as an integer so that it may be used later
	int searchGridHighNumber = 64;
	//set initial ping number
	int pingNumber = 0;
	//pick random target location
	int targetLocation = (rand() % 64) + 1;

	cout << "setting targets random location on an 8x8 grid" << endl;
	cout << "target located at " << targetLocation << endl;

	//Loop to find targets location

	while (true) {
		//math logic to find the target location
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		pingNumber++;
		// checks if initial guess is correct
		if (targetLocationPrediction == targetLocation) {
			cout << "Skynet HK-Aerial Radar sending out ping #" << pingNumber << endl;
			cout << "Target was hiding at location " << targetLocation << endl;
			cout << "Target was found at location " << targetLocationPrediction << endl;
			cout << "SkynetHK took " << pingNumber << " predictions to find the target location on a grid size of 8x8." << endl;
			break;
		}
		// checks if the target is lower than the prediction
		else if (targetLocationPrediction > targetLocation) {
			cout << "Skynet HK-Aerial Radar sending out ping #" << pingNumber << endl;

			cout << "The target location prediction of " << targetLocationPrediction << " was higher than the actual target location of " << targetLocation << "." << endl;
			searchGridHighNumber = targetLocationPrediction - 1;
			cout << "The new searchGridHighNumber = " << searchGridHighNumber << endl;

		}
		// checks if the targetloction is higher than prediction 
		else if (targetLocationPrediction < targetLocation) {
			cout << "Skynet HK-Aerial Radar sending out ping #" << pingNumber << endl;
			cout << "The target location prediction of " << targetLocationPrediction << " was lower than the actual target location of " << targetLocation << "." << endl;

			searchGridLowNumber = targetLocationPrediction + 1;
			cout << "The new searchGridLowNumber = " << searchGridLowNumber << endl;

		}

	}
	return system("pause");
}