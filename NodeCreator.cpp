#include "NodeCreator.h"
#include <iostream>
#include <fstream>

NodeCreator::NodeCreator() {
	x = 0;
	y = 0;
	z = 0;

	xStep = 0;
	yStep = 0;
	zStep = 0;

	xStepsNumber = 0;
	yStepsNumber = 0;
	zStepsNumber = 0;

	arrayOfNodes = NULL;
}

void NodeCreator::loadInitialData(string fileName) {
	ifstream file(fileName);

	if (!file) {
		cout << "File couldn't be open";
	} else {
		file >> x >> y >> z;
		file >> xStep >> yStep >> zStep;
	}

	file.close();
}

bool NodeCreator::isMoreThanZero(double number) {
	return number > 0;
}

bool NodeCreator::checkData() {
	if (!isMoreThanZero(x) || !isMoreThanZero(y) || !isMoreThanZero(z)) {
		cout << "Please, check lengths of the sides! Lengths of the sides must be more than zero.\n\n";

		return false;
	}

	if (!isMoreThanZero(xStep) || !isMoreThanZero(yStep) || !isMoreThanZero(zStep)) {
		cout << "Please, check steps! The steps must be more than zero.\n\n";

		return false;
	}

	if (x < xStep || y < yStep || z < zStep) {
		cout << "Please, check data! The steps can't be more than length of the side.\n\n";

		return false;
	}

	return true;
}

void NodeCreator::correctStep(double &x, double &xStep, int &xStepsNumber) {

	double quotient = 0;
	quotient = x / xStep;
	xStepsNumber = rint(quotient);
	xStep = x / xStepsNumber;
}

void NodeCreator::correctAllSteps() {
	correctStep(x, xStep, xStepsNumber);
	correctStep(y, yStep, yStepsNumber);
	correctStep(z, zStep, zStepsNumber);
}

void NodeCreator::createNodes() {
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
				Node node;
				node.number = (i + 1) + j * (xStepsNumber + 1) + k * (xStepsNumber + 1) * (yStepsNumber + 1);
				node.x = i * xStep;
				node.y = j * yStep;
				node.z = k * zStep;
				arrayOfNodes[i][j][k] = node;
			}
		}
	}
}

void NodeCreator::printInitialData() {
	cout << "Lengths of the sides by coordinate axis:\n";
	cout << "x = " << x << '\n';
	cout << "y = " << y << '\n';
	cout << "z = " << z << "\n\n";

	cout << "Steps by coordinate axis:\n";
	cout << "x = " << xStep << '\n';
	cout << "y = " << yStep << '\n';
	cout << "z = " << zStep << "\n\n";
}

void NodeCreator::printNodes() {
	cout << "Nodes (Number, x, y, z):\n";
	for (int k = 0; k <= zStepsNumber; k++) {
		for (int j = 0; j <= yStepsNumber; j++) {
			for (int i = 0; i <= xStepsNumber; i++) {
				Node node = arrayOfNodes[i][j][k];
				cout << node.number << ' ' << node.x << ' ' << node.y << ' ' << node.z << '\n';
			}
		}
	}

	cout << '\n';
}

void NodeCreator::writeNodesInFile(string fileName) {
	ofstream file(fileName);

	int numberOfNodes = (xStepsNumber + 1) * (yStepsNumber + 1) * (zStepsNumber + 1);
	file << numberOfNodes << ' ' << dimension << '\n';
	for (int k = 0; k <= zStepsNumber; k++) {
		for (int j = 0; j <= yStepsNumber; j++) {
			for (int i = 0; i <= xStepsNumber; i++) {
				Node node = arrayOfNodes[i][j][k];
				file << node.x << ' ' << node.y << ' ' << node.z << '\n';
			}
		}
	}

	file << '\n';

	file.close();
}