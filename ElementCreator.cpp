#include "ElementCreator.h"
#include <iostream>
#include <fstream>

using namespace std;

ElementCreator::ElementCreator() {
	xStepsNumber = 0;
	yStepsNumber = 0;
	zStepsNumber = 0;

	axe = ' ';
	minAxeValue = 0;
	maxAxeValue = 0;

	centerCoordinateOne = 0;
	centerCoordinateTwo = 0;
	radius = 0;

	arrayOfNodes = 0;
	arrayOfMaterials = 0;
}

ElementCreator::~ElementCreator() {

}

void ElementCreator::setStepsNumbers(int xStepsNumber, int yStepsNumber, int zStepsNumber) {
	this->xStepsNumber = xStepsNumber;
	this->yStepsNumber = yStepsNumber;
	this->zStepsNumber = zStepsNumber;
}

void ElementCreator::setArrayOfNodes(Node ***tempArrayOfNodes) {
	arrayOfNodes = new Node**[xStepsNumber + 1];
	for (int i = 0; i <= xStepsNumber; i++) {
		arrayOfNodes[i] = new Node*[yStepsNumber + 1];
		for (int j = 0; j <= yStepsNumber; j++) {
			arrayOfNodes[i][j] = new Node[zStepsNumber + 1];
		}
	}

	for (int k = 0; k <= zStepsNumber; k++) {
		for (int j = 0; j <= yStepsNumber; j++) {
			for (int i = 0; i <= xStepsNumber; i++) {
				arrayOfNodes[i][j][k] = tempArrayOfNodes[i][j][k];
			}
		}
	}
}

void ElementCreator::loadCylinderProperties(string fileName) {
	ifstream file(fileName);

	if (!file) {
		cout << "File couldn't be open";
	}
	else {
		file >> axe >> minAxeValue >> maxAxeValue;
		file >> centerCoordinateOne >> centerCoordinateTwo >> radius;
	}

	file.close();
}

void ElementCreator::determineMaterialByXAxe(int i, int j, int k) {
	bool isMaterialDefected = false;

	if (arrayOfNodes[i][j][k].x >= minAxeValue && arrayOfNodes[i][j][k].x <= maxAxeValue) {
		double axeOne = fabs(arrayOfNodes[i][j][k].y - centerCoordinateOne);
		double axeTwo = fabs(arrayOfNodes[i][j][k].z - centerCoordinateTwo);
		double distance = sqrt(pow(axeOne, SECOND_DEGREE) + pow(axeTwo, SECOND_DEGREE));

		if (distance <= radius) {
			isMaterialDefected = true;
		}
	}

	determineMaterial(isMaterialDefected, i, j, k);
}

void ElementCreator::determineMaterialByYAxe(int i, int j, int k) {
	bool isMaterialDefected = false;

	if (arrayOfNodes[i][j][k].y >= minAxeValue && arrayOfNodes[i][j][k].y <= maxAxeValue) {
		double axeOne = fabs(arrayOfNodes[i][j][k].x - centerCoordinateOne);
		double axeTwo = fabs(arrayOfNodes[i][j][k].z - centerCoordinateTwo);
		double distance = sqrt(pow(axeOne, SECOND_DEGREE) + pow(axeTwo, SECOND_DEGREE));

		if (distance <= radius) {
			isMaterialDefected = true;
		}
	}

	determineMaterial(isMaterialDefected, i, j, k);
}

void ElementCreator::determineMaterialByZAxe(int i, int j, int k) {
	bool isMaterialDefected = false;

	if (arrayOfNodes[i][j][k].z >= minAxeValue && arrayOfNodes[i][j][k].z <= maxAxeValue) {
		double axeOne = fabs(arrayOfNodes[i][j][k].x - centerCoordinateOne);
		double axeTwo = fabs(arrayOfNodes[i][j][k].y - centerCoordinateTwo);
		double distance = sqrt(pow(axeOne, SECOND_DEGREE) + pow(axeTwo, SECOND_DEGREE));

		if (distance <= radius) {
			isMaterialDefected = true;
		}
	}

	determineMaterial(isMaterialDefected, i, j, k);
}

void ElementCreator::determineMaterial(bool isMaterialDefected, int i, int j, int k) {
	if (isMaterialDefected) {
		arrayOfMaterials[i][j][k] = 2;
	} else {
		arrayOfMaterials[i][j][k] = 1;
	}
}

void ElementCreator::createMapOfMaterials() {
	arrayOfMaterials = new int**[xStepsNumber + 1];
	for (int i = 0; i <= xStepsNumber; i++) {
		arrayOfMaterials[i] = new int*[yStepsNumber + 1];
		for (int j = 0; j <= yStepsNumber; j++) {
			arrayOfMaterials[i][j] = new int[zStepsNumber + 1];
		}
	}

	if (axe == 'X') {
		for (int i = 0; i <= xStepsNumber; i++)
			for (int j = 0; j <= yStepsNumber; j++)
				for (int k = 0; k <= zStepsNumber; k++)
					determineMaterialByXAxe(i, j, k);
	}
	else if (axe == 'Y') {
		for (int i = 0; i <= xStepsNumber; i++)
			for (int j = 0; j <= yStepsNumber; j++)
				for (int k = 0; k <= zStepsNumber; k++)
					determineMaterialByYAxe(i, j, k);
	}
	else if (axe == 'Z') {
		for (int i = 0; i <= xStepsNumber; i++)
			for (int j = 0; j <= yStepsNumber; j++)
				for (int k = 0; k <= zStepsNumber; k++)
					determineMaterialByZAxe(i, j, k);
	}
}

void ElementCreator::templateNumberOne(int xStep, int yStep, int zStep) {
	Element elementOne;
	if (arrayOfMaterials[xStep][yStep][zStep] == arrayOfMaterials[xStep + 1][yStep][zStep] &&
		arrayOfMaterials[xStep + 1][yStep][zStep] == arrayOfMaterials[xStep + 1][yStep + 1][zStep] &&
		arrayOfMaterials[xStep + 1][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep][zStep + 1]) {
		elementOne.k = arrayOfMaterials[xStep][yStep][zStep];
	} else {
		elementOne.k = DIFFUSION_MATERIAL;
	}
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elements.push_back(elementOne);
	elementOne.nodesNumbers.clear();

	Element elementTwo;
	if (arrayOfMaterials[xStep][yStep][zStep] == arrayOfMaterials[xStep][yStep + 1][zStep] &&
		arrayOfMaterials[xStep][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep + 1][zStep] &&
		arrayOfMaterials[xStep + 1][yStep + 1][zStep] == arrayOfMaterials[xStep][yStep + 1][zStep + 1]) {
		elementTwo.k = arrayOfMaterials[xStep][yStep][zStep];
	} else {
		elementTwo.k = DIFFUSION_MATERIAL;
	}
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementTwo);
	elementTwo.nodesNumbers.clear();

	Element elementThree;
	if (arrayOfMaterials[xStep][yStep][zStep] == arrayOfMaterials[xStep][yStep][zStep + 1] &&
		arrayOfMaterials[xStep][yStep][zStep + 1] == arrayOfMaterials[xStep + 1][yStep][zStep + 1] &&
		arrayOfMaterials[xStep + 1][yStep][zStep + 1] == arrayOfMaterials[xStep][yStep + 1][zStep + 1]) {
		elementThree.k = arrayOfMaterials[xStep][yStep][zStep];
	} else {
		elementThree.k = DIFFUSION_MATERIAL;
	}
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementThree);
	elementThree.nodesNumbers.clear();

	Element elementFour;
	if (arrayOfMaterials[xStep + 1][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep][zStep + 1] &&
		arrayOfMaterials[xStep + 1][yStep][zStep + 1] == arrayOfMaterials[xStep][yStep + 1][zStep + 1] &&
		arrayOfMaterials[xStep][yStep + 1][zStep + 1] == arrayOfMaterials[xStep + 1][yStep + 1][zStep + 1]) {
		elementFour.k = arrayOfMaterials[xStep + 1][yStep + 1][zStep];
	} else {
		elementFour.k = DIFFUSION_MATERIAL;
	}
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementFour);
	elementFour.nodesNumbers.clear();

	Element elementFive;
	if (arrayOfMaterials[xStep][yStep][zStep] == arrayOfMaterials[xStep + 1][yStep + 1][zStep] &&
		arrayOfMaterials[xStep + 1][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep][zStep + 1] &&
		arrayOfMaterials[xStep + 1][yStep][zStep + 1] == arrayOfMaterials[xStep][yStep + 1][zStep + 1]) {
		elementFive.k = arrayOfMaterials[xStep][yStep][zStep];
	} else {
		elementFive.k = DIFFUSION_MATERIAL;
	}
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementFive);
	elementFive.nodesNumbers.clear();
}

void ElementCreator::templateNumberTwo(int xStep, int yStep, int zStep) {
	Element elementOne;
	if (arrayOfMaterials[xStep][yStep][zStep] == arrayOfMaterials[xStep + 1][yStep][zStep] &&
		arrayOfMaterials[xStep + 1][yStep][zStep] == arrayOfMaterials[xStep][yStep + 1][zStep] &&
		arrayOfMaterials[xStep][yStep + 1][zStep] == arrayOfMaterials[xStep][yStep][zStep + 1]) {
		elementOne.k = arrayOfMaterials[xStep][yStep][zStep];
	} else {
		elementOne.k = DIFFUSION_MATERIAL;
	}
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elements.push_back(elementOne);
	elementOne.nodesNumbers.clear();

	Element elementTwo;
	if (arrayOfMaterials[xStep + 1][yStep][zStep] == arrayOfMaterials[xStep][yStep + 1][zStep] &&
		arrayOfMaterials[xStep][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep + 1][zStep] &&
		arrayOfMaterials[xStep + 1][yStep + 1][zStep] == arrayOfMaterials[xStep + 1][yStep + 1][zStep + 1]) {
		elementTwo.k = arrayOfMaterials[xStep + 1][yStep][zStep];
	} else {
		elementTwo.k = DIFFUSION_MATERIAL;
	}
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementTwo);
	elementTwo.nodesNumbers.clear();

	Element elementThree;
	if (arrayOfMaterials[xStep + 1][yStep][zStep] == arrayOfMaterials[xStep][yStep][zStep + 1] &&
		arrayOfMaterials[xStep][yStep][zStep + 1] == arrayOfMaterials[xStep + 1][yStep][zStep + 1] &&
		arrayOfMaterials[xStep + 1][yStep][zStep + 1] == arrayOfMaterials[xStep + 1][yStep + 1][zStep + 1]) {
		elementThree.k = arrayOfMaterials[xStep + 1][yStep][zStep];
	} else {
		elementThree.k = DIFFUSION_MATERIAL;
	}
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementThree);
	elementThree.nodesNumbers.clear();

	Element elementFour;
	if (arrayOfMaterials[xStep][yStep + 1][zStep] == arrayOfMaterials[xStep][yStep][zStep + 1] &&
		arrayOfMaterials[xStep][yStep][zStep + 1] == arrayOfMaterials[xStep][yStep + 1][zStep + 1] &&
		arrayOfMaterials[xStep][yStep + 1][zStep + 1] == arrayOfMaterials[xStep + 1][yStep + 1][zStep + 1]) {
		elementFour.k = arrayOfMaterials[xStep][yStep + 1][zStep];
	} else {
		elementFour.k = DIFFUSION_MATERIAL;
	}
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementFour);
	elementFour.nodesNumbers.clear();

	Element elementFive;
	if (arrayOfMaterials[xStep + 1][yStep][zStep] == arrayOfMaterials[xStep][yStep + 1][zStep] &&
		arrayOfMaterials[xStep][yStep + 1][zStep] == arrayOfMaterials[xStep][yStep][zStep + 1] &&
		arrayOfMaterials[xStep][yStep][zStep + 1] == arrayOfMaterials[xStep + 1][yStep + 1][zStep + 1]) {
		elementFive.k = arrayOfMaterials[xStep + 1][yStep][zStep];
	} else {
		elementFive.k = DIFFUSION_MATERIAL;
	}
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementFive);
	elementFive.nodesNumbers.clear();
}

void ElementCreator::createElements() {
	for (int i = 0; i < xStepsNumber; i++) {
		for (int j = 0; j < yStepsNumber; j++) {
			for (int k = 0; k < zStepsNumber; k++) {
				int coefficient = i + j + k + 1;

				if (coefficient % 2 == 1) {
					templateNumberOne(i, j, k);
				}
				else {
					templateNumberTwo(i, j, k);
				}
			}
		}
	}
}

void ElementCreator::printElements() {
	cout << elements.size() << ' ' << NUMBER_OF_NODES << "\n";
	for (int i = 0; i < elements.size(); i++) {
		cout << elements[i].k;

		for (int j = 0; j < NUMBER_OF_NODES; j++) {
			cout << ' ' << elements[i].nodesNumbers[j];
		}

		cout << "\n";
	}
}

void ElementCreator::writeElementsInFile(string fileName) {
	ofstream file(fileName, ios_base::app);

	file << elements.size() << ' ' << NUMBER_OF_NODES << "\n";
	for (int i = 0; i < elements.size(); i++) {
		file << elements[i].k;

		for (int j = 0; j < NUMBER_OF_NODES; j++) {
			file << ' ' << elements[i].nodesNumbers[j];
		}

		file << "\n";
	}

	file << '\n';

	file.close();
}