#include "NodeCreator.h"
#include "ElementCreator.h"

const string INITIAL_DATA_FILE = "InitialData.txt";
const string RESULT_FILE = "Result.txt";

class TriangulationManager {
	NodeCreator nodeCreator;
	ElementCreator elementCreator;
	int xStepsNumber, yStepsNumber, zStepsNumber;
	Node ***arrayOfNodes;

public:
	TriangulationManager ();
	~TriangulationManager ();

	bool runNodeCreator();
	void runElementCreator();
	void run();

private:

};