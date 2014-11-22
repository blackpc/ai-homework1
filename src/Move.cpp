/**
 * Filename: Move.cpp
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

#include <homework1/Move.h>

const Move Move::R(1);
const Move Move::RD(2);
const Move Move::D(3);
const Move Move::LD(4);
const Move Move::L(5);
const Move Move::LU(6);
const Move Move::U(7);
const Move Move::RU(8);

/**
 * Returns all possible moves
 * @return
 */
vector<Move> Move::getAllMoves() {
	vector<Move> moves;

	moves.push_back(Move::R);
	moves.push_back(Move::RD);
	moves.push_back(Move::D);
	moves.push_back(Move::LD);
	moves.push_back(Move::L);
	moves.push_back(Move::LU);
	moves.push_back(Move::U);
	moves.push_back(Move::RU);

	return moves;
}

/**
 * Returns integer value of move
 * @return
 */
int Move::value() const {
	 return value_;
}

/**
 * Returns string representation of this move
 * @return
 */
string Move::toString() const {
	switch (value_) {
		case 1:
			return "R";
		case 2:
			return "RD";
		case 3:
			return "D";
		case 4:
			return "LD";
		case 5:
			return "L";
		case 6:
			return "LU";
		case 7:
			return "U";
		case 8:
			return "RU";
		default:
			throw new string("Invalid move");
	}
}

/**
 * Return reversed move
 * @return
 */
Move Move::reverse() const {
	if (*this == Move::R)
		return Move::L;

	if (*this == Move::RD)
		return Move::LU;

	if (*this == Move::D)
		return Move::U;

	if (*this == Move::LD)
		return Move::RU;

	if (*this == Move::L)
		return Move::R;

	if (*this == Move::LU)
		return Move::RD;

	if (*this == Move::U)
		return Move::D;

	if (*this == Move::RU)
		return Move::LD;

	throw new string("Invalid move");
}

/**
 * Sets costs of the move
 * @param cost
 */
void Move::setCost(int cost) {
	cost_ = cost;
}

/**
 * Returns the cost of this move
 * @return
 */
int Move::getCost() const {
	return cost_;
}

/**
 * Checks if it is an initialized move or not
 * @return
 */
bool Move::isNull() const {
	return value_ == 0;
}

bool Move::operator ==(const Move& other) const {
	return this->value_ == other.value_;
}

bool Move::operator <(const Move& other) const {
	return this->value_ < other.value_;
}

