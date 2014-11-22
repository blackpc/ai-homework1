/**
 * Filename: FileReader.cpp
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

#include <homework1/FileReader.h>

FileReader::FileReader(const string& filename)
	: mapSize_(0)
{
	ifstream fileStream(filename.c_str());
	string line;

	fileStream >> algorithmName_;
	fileStream >> mapSize_;

	map_ = boost::shared_ptr<Map>(new Map(mapSize_, mapSize_));

	for (int row = 0; row < mapSize_; ++row) {
		fileStream >> line;

		for (int column = 0; column < line.size(); ++column) {
			string value = boost::lexical_cast<string>(line[column]);

			if (value == "G") {
				goal_ = Point(column, row);
				value = "R";
			}

			if (value == "S") {
				start_ = Point(column, row);
				value = "R";
			}

			map_->at(column, row) = Cell(value);
		}
	}

}

string FileReader::getAlgorithmName() const {
	return algorithmName_;
}

size_t FileReader::getMapSize() const {
	return mapSize_;
}

Map::Ptr FileReader::getMap() const {
	return map_;
}

Point FileReader::getStartPosition() {
	return start_;
}

Point FileReader::getGoal() {
	return goal_;
}
