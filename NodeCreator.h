#include <string>

using namespace std;

class NodeCreator {
	double x, y, z;
	double xStep, yStep, zStep;
	int xStepsNumber, yStepsNumber, zStepsNumber;

public:
	NodeCreator();
	void loadInitialData(string fileName);
	bool checkData();
	void correctAllSteps();
	void printInitialData();

private:
	bool isMoreThanZero(double number);
	void correctStep(double &x, double &xStep, int &xStepsNumber);
};