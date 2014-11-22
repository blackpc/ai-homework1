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
	static vector<Move> getAllMoves();


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
	void setCost(int cost);

	/**
	 * Returns the cost of this move
	 * @return
	 */
	int getCost() const;

	/**
	 * Checks if it is an initialized move or not
	 * @return
	 */
	bool isNull() const;

	/**
	 * Return reversed move
	 * @return
	 */
	Move reverse() const;

	bool operator ==(const Move& other) const;

	bool operator <(const Move& other) const;

private:

	int value_;
	int cost_;

};



#endif /* MOVE_H_ */
