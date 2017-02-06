#include "NodeCreator.h"
#include "ElementCreator.h"

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