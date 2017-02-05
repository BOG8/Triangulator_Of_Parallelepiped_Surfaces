#include "TriangulationManager.h"

using namespace std;

int main(int argc, char *argv[])
{
	//NodeCreator nodeCreator;
	//nodeCreator.loadInitialData("InitialData.txt");

	//if (nodeCreator.checkData()) {
	//	nodeCreator.correctAllSteps();
	//	nodeCreator.printInitialData();
	//	nodeCreator.createNodes();
	//	nodeCreator.printNodes();
	//	nodeCreator.writeNodesInFile("Result.txt");
	//}

	TriangulationManager triangulationManager;
	triangulationManager.run();

	system("pause");

	return 0;
}