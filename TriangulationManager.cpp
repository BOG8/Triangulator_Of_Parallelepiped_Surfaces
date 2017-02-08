#include "TriangulationManager.h"
#include <iostream>

TriangulationManager::TriangulationManager() {
	xStepsNumber = 0;
	yStepsNumber = 0;
	zStepsNumber = 0;
}

TriangulationManager ::~TriangulationManager() {

}

// Работа с классом NodeCreator
bool TriangulationManager::runNodeCreator() {
	nodeCreator.loadInitialData(INITIAL_DATA_FILE);

	if (nodeCreator.checkData()) {
		nodeCreator.run();
		nodeCreator.writeNodesInFile(RESULT_FILE);
		xStepsNumber = nodeCreator.getXStepsNumber();
		yStepsNumber = nodeCreator.getYStepsNumber();
		zStepsNumber = nodeCreator.getZStepsNumber();
		Node ***tempArrayOfNodes = nodeCreator.getArrayOfNodes();
		
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

		tempArrayOfNodes = 0;
		nodeCreator.clearMemory();

		return true;
	}

	return false;
}

// Работа с классом runElementCreator
void TriangulationManager::runElementCreator() {
	elementCreator.setStepsNumbers(xStepsNumber, yStepsNumber, zStepsNumber);
	elementCreator.setArrayOfNodes(arrayOfNodes);
	elementCreator.loadCylinderProperties(CYLINDER_PROPERTIES);
	elementCreator.createElements();
	elementCreator.printElements();
	elementCreator.writeElementsInFile(RESULT_FILE);
}

// Триангулирование
void TriangulationManager::run() {
	if (runNodeCreator()) {
		runElementCreator();
	}
}