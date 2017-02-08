#include "Node.h"
#include "Element.h"
#include <vector>

const int numberOfNodesInElement = 4;

class ElementCreator {
	int xStepsNumber, yStepsNumber, zStepsNumber;
	Node ***arrayOfNodes;
	vector<Element> elements;

public:
	ElementCreator();
	~ElementCreator();

	void setStepsNumbers(int xStepsNumber, int yStepsNumbers, int zStepsNumbers);
	void setArrayOfNodes(Node ***tempArrayOfNodes);
	void createElements();
	void printElements();
	
private:
	void templateNumberOne(int xStep, int yStep, int zStep);
	void templateNumberTwo(int xStep, int yStep, int zStep);
};