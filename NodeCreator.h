#include "Node.h"
#include <string>

const int dimension = 3;

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
	void writeNodesInFile(string fileName);

private:
	bool isMoreThanZero(double number);
	void correctStep(double &x, double &xStep, int &xStepsNumber);
};