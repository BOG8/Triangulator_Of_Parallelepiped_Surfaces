#include "TriangulationManager.h"

TriangulationManager::TriangulationManager() {

}

TriangulationManager ::~TriangulationManager() {

}

void TriangulationManager::run() {
	nodeCreator.loadInitialData("InitialData.txt");

	if (nodeCreator.checkData()) {
		nodeCreator.correctAllSteps();
		nodeCreator.printInitialData();
		nodeCreator.createNodes();
		nodeCreator.printNodes();
		nodeCreator.writeNodesInFile("Result.txt");
	}
}