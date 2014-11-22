/**
 * Filename: Path.cpp
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

#include <homework1/Path.h>

/**
 * Returns all moves
 * @return
 */
vector<Move> Path::getMoves() const {
	return moves_;
}

/**
 * Adds a new move to the end
 * @param move
 */
void Path::addMove(const Move& move) {
	moves_.push_back(move);
}

/**
 * Returns string representation of the path including the total cost
 * @return
 */
string Path::toString() const {

	if (moves_.size() == 0)
		return "no path";

	stringstream output;
	int totalCost = 0;

	for (int i = 0; i < moves_.size(); ++i) {
		output << moves_[i].toString();

		if (i < moves_.size() - 1)
			output << "-";

		totalCost += moves_[i].getCost();
	}

	output << " " << totalCost;

	return output.str();
}

/**
 * Returns reversed path
 * @return
 */
Path Path::reverse() const {
	Path reversedPath;

	for (int i = 0; i < moves_.size(); ++i)
		reversedPath.addMove(moves_[moves_.size() - i - 1]);

	return reversedPath;
}
