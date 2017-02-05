#include "NodeCreator.h"

class TriangulationManager {
	NodeCreator nodeCreator;
	int xStepsNumber, yStepsNumber, zStepsNumber;
	int ***arrayOfNodesNumbers;

public:
	TriangulationManager ();
	~TriangulationManager ();

	bool runNodeCreator();
	void run();
private:

};