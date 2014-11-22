/**
 * Filename: main.cpp
 *   Author: Igor Makhtes
 *     Date: Nov 21, 2014
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include <fstream>
#include <string>
#include <iostream>

#include <homework1/FileReader.h>
#include <homework1/BfsPathFinder.h>
#include <homework1/UcsPathFinder.h>


using namespace std;


void test() {
	multiset<WeightedPoint> s;

	s.insert(WeightedPoint(Point(0, 0), 1));
	s.insert(WeightedPoint(Point(0, 1), 1));
	s.insert(WeightedPoint(Point(0, 2), 1));

	cout << s.size() << endl;
}


int main(int argc, char **argv) {

	FileReader* reader;
	try {
		reader = new FileReader("input.txt");
	} catch (...) {
		cerr << "Failed to open intput.txt file" << endl;
	}

	std::ofstream fileWriter("output.txt");


	IPathFinder* finder = NULL;

	if (reader->getAlgorithmName() == "BFS")
		finder = new BfsPathFinder();

	if (reader->getAlgorithmName() == "UCS")
		finder = new UcsPathFinder();

	Path path = finder->findPath(reader->getStartPosition(), reader->getGoal(), reader->getMap());

	cout << path.toString() << endl;
	fileWriter << path.toString() << endl;

	delete reader;
	return 0;
}


