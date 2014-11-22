/**
 * Filename: Cell.cpp
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

#include <homework1/Cell.h>

Cell::Cell(uint8_t value) : value_(value) {
	if (value < 1 || value > 4)
		throw new string("Unknown cell type");
}

Cell::Cell(const string& value) {
	if (value == "R")
		value_ = 1;
	else if (value == "D")
		value_ = 2;
	else if (value == "H")
		value_ = 3;
	else if (value == "W")
		value_ = 4;
	else
		throw new string("Unknown cell type");
}

/**
 * Returns string representation of cell
 * @return
 */
string Cell::toString() const {
	switch (value_) {
		case 1:
			return "R";
		case 2:
			return "D";
		case 3:
			return "H";
		case 4:
			return "W";

		default:
			return "X";
	}
}

/**
 * Returns integer value of cell
 * @return
 */
uint8_t Cell::value() const {
	return value_;
}

/**
 * Returns the cost for traveling to this type of cell
 * @return
 */
int Cell::getCost() const {
	if (value_ == 1)
		return 1;

	if (value_ == 2)
		return 3;

	if (value_ == 3)
		return 10;

	return numeric_limits<int>::infinity();
}

/**
 * True if cell is traversable
 * @return
 */
bool Cell::isTraversable() const {

	// Only Water (4) is not traversable
	if (value_ == 4)
		return false;

	return true;
}

/**
 * Sets came from field
 * @param move
 */
void Cell::setCameFrom(const Move& move) {
	cameFrom_ = move;
}

/**
 * Gets the came from field
 * @return
 */
Move Cell::getCameFrom() const {
	return cameFrom_;
}
