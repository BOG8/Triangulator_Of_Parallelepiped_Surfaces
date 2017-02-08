#include "ElementCreator.h"
#include <iostream>
#include <fstream>

using namespace std;

ElementCreator::ElementCreator() {
	xStepsNumber = 0;
	yStepsNumber = 0;
	zStepsNumber = 0;

	arrayOfNodes = 0;
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

void ElementCreator::templateNumberOne(int xStep, int yStep, int zStep) {
	Element elementOne;
	elementOne.k = 0;	// Заглушка
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elements.push_back(elementOne);
	elementOne.nodesNumbers.clear();

	Element elementTwo;
	elementTwo.k = 0;	// Заглушка
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementTwo);
	elementTwo.nodesNumbers.clear();

	Element elementThree;
	elementThree.k = 0;	// Заглушка
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementThree);
	elementThree.nodesNumbers.clear();

	Element elementFour;
	elementFour.k = 0;	// Заглушка
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementFour);
	elementFour.nodesNumbers.clear();

	Element elementFive;
	elementFive.k = 0;	// Заглушка
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementFive.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elements.push_back(elementFive);
	elementFive.nodesNumbers.clear();
}

void ElementCreator::templateNumberTwo(int xStep, int yStep, int zStep) {
	Element elementOne;
	elementOne.k = 0;	// Заглушка
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementOne.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elements.push_back(elementOne);
	elementOne.nodesNumbers.clear();

	Element elementTwo;
	elementTwo.k = 0;	// Заглушка
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep].number);
	elementTwo.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementTwo);
	elementTwo.nodesNumbers.clear();

	Element elementThree;
	elementThree.k = 0;	// Заглушка
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep][zStep + 1].number);
	elementThree.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementThree);
	elementThree.nodesNumbers.clear();

	Element elementFour;
	elementFour.k = 0;	// Заглушка
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep][yStep + 1][zStep + 1].number);
	elementFour.nodesNumbers.push_back(arrayOfNodes[xStep + 1][yStep + 1][zStep + 1].number);
	elements.push_back(elementFour);
	elementFour.nodesNumbers.clear();

	Element elementFive;
	elementFive.k = 0;	// Заглушка
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