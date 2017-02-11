#include "Node.h"
#include "Element.h"
#include <vector>

const int NUMBER_OF_NODES = 4;
const int SECOND_DEGREE = 2;

class ElementCreator {
	int xStepsNumber, yStepsNumber, zStepsNumber;
	char axe;
	double minAxeValue, maxAxeValue, centerCoordinateOne, centerCoordinateTwo, radius;
	Node ***arrayOfNodes;
	int ***arrayOfMaterials;
	vector<Element> elements;

public:
	ElementCreator();
	~ElementCreator();

	void setStepsNumbers(int xStepsNumber, int yStepsNumbers, int zStepsNumbers);
	void setArrayOfNodes(Node ***tempArrayOfNodes);
	void loadCylinderProperties(string fileName);
	void determineMaterialByXAxe(int i, int j, int k);
	void determineMaterialByYAxe(int i, int j, int k);
	void determineMaterialByZAxe(int i, int j, int k);
	void determineMaterial(bool isMaterialDefected, int i, int j, int k);
	void createMapOfMaterials();
	void createElements();
	void printElements();
	void writeElementsInFile(string fileName);
	
private:
	void templateNumberOne(int xStep, int yStep, int zStep);
	void templateNumberTwo(int xStep, int yStep, int zStep);
};