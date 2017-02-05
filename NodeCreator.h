#include "Node.h"
#include <string>

using namespace std;

class NodeCreator {
	double x, y, z;
	double xStep, yStep, zStep;
	int xStepsNumber, yStepsNumber, zStepsNumber;
	Node ***arrayOfNodes;

public:
	NodeCreator();
	void loadInitialData(string fileName);
	bool checkData();
	void correctAllSteps();
	void createNodes();
	void printInitialData();
	void printNodes();

private:
	bool isMoreThanZero(double number);
	void correctStep(double &x, double &xStep, int &xStepsNumber);
};