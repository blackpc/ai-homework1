/**
 * Filename: Move.h
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

#ifndef MOVE_H_
#define MOVE_H_


#include <string>
#include <vector>


using namespace std;

/**
 * Represents a move on the map
 */
class Move {

public:

	/**
	 * Right move
	 */
	static const Move R;

	/**
	 * Right-down move
	 */
	static const Move RD;

	/**
	 * Down move
	 */
	static const Move D;

	/**
	 * Left-down move
	 */
	static const Move LD;

	/**
	 * Left move
	 */
	static const Move L;

	/**
	 * Left-up move
	 */
	static const Move LU;

	/**
	 * Up move
	 */
	static const Move U;

	/**
	 * Right-up move
	 */
	static const Move RU;

	/**
	 * Returns all possible moves
	 * @return
	 */
	static vector<Move> getAllMoves() {
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


	Move() : value_(0), cost_(0) { }

	Move(int value, int cost = 0) : value_(value), cost_(cost) { }

	Move(Move move, int cost) : value_(move.value_), cost_(cost) { }

	/**
	 * Returns integer value of move
	 * @return
	 */
	int value() const;

	/**
	 * Returns string representation of this move
	 * @return
	 */
	string toString() const;

	/**
	 * Sets costs of the move
	 * @param cost
	 */
	void setCost(int cost) {
		cost_ = cost;
	}

	/**
	 * Returns the cost of this move
	 * @return
	 */
	int getCost() const {
		return cost_;
	}

	bool isNull() const {
		return value_ == 0;
	}

	/**
	 * Return reversed move
	 * @return
	 */
	Move reverse() const {
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

	bool operator ==(const Move& other) const {
		return this->value_ == other.value_;
	}

	bool operator <(const Move& other) const {
		return this->value_ < other.value_;
	}

private:

	int value_;
	int cost_;

};



#endif /* MOVE_H_ */
