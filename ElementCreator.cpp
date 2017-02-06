#include "ElementCreator.h"


ElementCreator::ElementCreator() {
	xStepsNumber = 0;
	yStepsNumber = 0;
	zStepsNumber = 0;

	arrayOfNodes = 0;
}

ElementCreator::~ElementCreator() {

}

void ElementCreator::setStepsNumbers(int xStepsNumber, int yStepsNumber, int zStepsNumber) {
	this->xStepsNumber = xStepsNumber;
	this->yStepsNumber = yStepsNumber;
	this->zStepsNumber = zStepsNumber;
}

void ElementCreator::setArrayOfNodes(Node ***tempArrayOfNodes) {
	arrayOfNodes = new Node**[xStepsNumber + 1];
	for (int i = 0; i <= xStepsNumber; i++) {
		arrayOfNodes[i] = new Node*[yStepsNumber + 1];
		for (int j = 0; j <= yStepsNumber; j++) {
			arrayOfNodes[i][j] = new Node[zStepsNumber + 1];
		}
	}

	for (int k = 0; k <= zStepsNumber; k++) {
		for (int j = 0; j <= yStepsNumber; j++) {
			for (int i = 0; i <= xStepsNumber; i++) {
				arrayOfNodes[i][j][k] = tempArrayOfNodes[i][j][k];
			}
		}
	}
}