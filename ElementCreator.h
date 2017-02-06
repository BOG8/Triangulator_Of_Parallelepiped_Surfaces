#include "Node.h"

class ElementCreator {
	int xStepsNumber, yStepsNumber, zStepsNumber;
	Node ***arrayOfNodes;

public:
	ElementCreator();
	~ElementCreator();

	void setStepsNumbers(int xStepsNumber, int yStepsNumbers, int zStepsNumbers);
	void setArrayOfNodes(Node ***tempArrayOfNodes);

private:

};