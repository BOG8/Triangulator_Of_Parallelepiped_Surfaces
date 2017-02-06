#include "NodeCreator.h"

class TriangulationManager {
	NodeCreator nodeCreator;
	int xStepsNumber, yStepsNumber, zStepsNumber;
	Node ***arrayOfNodes;

public:
	TriangulationManager ();
	~TriangulationManager ();

	bool runNodeCreator();
	void run();

private:

};