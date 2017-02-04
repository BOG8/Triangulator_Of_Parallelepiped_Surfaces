#include "NodeCreator.h"

using namespace std;

int main(int argc, char *argv[])
{
	NodeCreator nodeCreator;
	nodeCreator.loadInitialData("InitialData.txt");

	if (nodeCreator.checkData()) {
		nodeCreator.correctAllSteps();
		nodeCreator.printInitialData();
	}

	system("pause");

	return 0;
}