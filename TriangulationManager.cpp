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
	nodeCreator.loadInitialData("InitialData.txt");

	if (nodeCreator.checkData()) {
		nodeCreator.run();
		nodeCreator.writeNodesInFile("Result.txt");
		xStepsNumber = nodeCreator.getXStepsNumber();
		yStepsNumber = nodeCreator.getYStepsNumber();
		zStepsNumber = nodeCreator.getZStepsNumber();
		Node ***arrayOfNodes = nodeCreator.getArrayOfNodes();

		arrayOfNodesNumbers = new int**[xStepsNumber + 1];
		for (int i = 0; i <= xStepsNumber; i++) {
			arrayOfNodesNumbers[i] = new int*[yStepsNumber + 1];
			for (int j = 0; j <= yStepsNumber; j++) {
				arrayOfNodesNumbers[i][j] = new int[zStepsNumber + 1];
			}
		}

		for (int k = 0; k <= zStepsNumber; k++) {
			for (int j = 0; j <= yStepsNumber; j++) {
				for (int i = 0; i <= xStepsNumber; i++) {
					arrayOfNodesNumbers[i][j][k] = arrayOfNodes[i][j][k].number;
				}
			}
		}

		arrayOfNodes = NULL;
		nodeCreator.clearMemory();

		return true;
	}

	return false;
}

// Триангулирование
void TriangulationManager::run() {
	if (runNodeCreator()) {

	}
}