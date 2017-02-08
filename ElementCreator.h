#include "Node.h"
#include "Element.h"
#include <vector>

const int NUMBER_OF_NODES = 4;

class ElementCreator {
	int xStepsNumber, yStepsNumber, zStepsNumber;
	char axe;
	double minAxeValue, maxAxeValue, centerCoordinateOne, centerCoordinateTwo, radius;
	Node ***arrayOfNodes;
	vector<Element> elements;

public:
	ElementCreator();
	~ElementCreator();

	void setStepsNumbers(int xStepsNumber, int yStepsNumbers, int zStepsNumbers);
	void setArrayOfNodes(Node ***tempArrayOfNodes);
	void loadCylinderProperties(string fileName);
	void createElements();
	void printElements();
	void writeElementsInFile(string fileName);
	
private:
	void templateNumberOne(int xStep, int yStep, int zStep);
	void templateNumberTwo(int xStep, int yStep, int zStep);
};