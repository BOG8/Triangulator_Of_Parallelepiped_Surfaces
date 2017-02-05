#include "NodeCreator.h"

using namespace std;

int main(int argc, char *argv[])
{
	NodeCreator nodeCreator;
	nodeCreator.loadInitialData("InitialData.txt");

	if (nodeCreator.checkData()) {
		nodeCreator.correctAllSteps();
		nodeCreator.printInitialData();
		nodeCreator.createNodes();
		nodeCreator.printNodes();
	}

	system("pause");

	return 0;
}