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
	~NodeCreator();

	void loadInitialData(string fileName);
	bool checkData();
	void run();
	void writeNodesInFile(string fileName);
	void clearMemory();

	int getXStepsNumber();
	int getYStepsNumber();
	int getZStepsNumber();
	Node ***getArrayOfNodes();

private:
	bool isMoreThanZero(double number);
	void correctStep(double &x, double &xStep, int &xStepsNumber);
	void correctAllSteps();	
	void createNodes();
	void printInitialData();
	void printNodes();
};