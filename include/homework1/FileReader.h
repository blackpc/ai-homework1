/**
 * Filename: FileReader.h
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

#ifndef FILEREADER_H_
#define FILEREADER_H_

#include <iostream>
#include <fstream>
#include <sstream>

#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>

#include <homework1/Map.h>
#include <homework1/Point.h>


using namespace std;


/*
 * Reads input file
 */
class FileReader {

public:

	/**
	 * Reads the input file and parses all parameters
	 * @param filename
	 */
	FileReader(const string& filename);

public:

	/**
	 * Returns the search algorithm name
	 * @return
	 */
	string getAlgorithmName() const;

	/**
	 * Returns map widh and height
	 * @return
	 */
	size_t getMapSize() const;

	/**
	 * Returns the map
	 * @return
	 */
	Map::Ptr getMap() const;

	/**
	 * The starting point
	 * @return
	 */
	Point getStartPosition();

	/**
	 * The finish point
	 * @return
	 */
	Point getGoal();

private:

	string algorithmName_;
	size_t mapSize_;
	Map::Ptr map_;
	Point start_;
	Point goal_;

};

#endif /* FILEREADER_H_ */
