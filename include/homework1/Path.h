/**
 * Filename: Path.h
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

#ifndef PATH_H_
#define PATH_H_


#include <vector>
#include <sstream>

#include <homework1/Move.h>
#include <homework1/Point.h>


using namespace std;


/*
 * Path represented by a series of moves
 */
class Path {

public:

	/**
	 * Returns all moves
	 * @return
	 */
	vector<Move> getMoves() const;

	/**
	 * Adds a new move to the end
	 * @param Move
	 */
	void addMove(const Move&);

	/**
	 * Returns string representation of the path including the total cost
	 * @return
	 */
	string toString() const;

	/**
	 * Returns reversed path
	 * @return
	 */
	Path reverse() const;

private:

	vector<Move> moves_;

};

#endif /* PATH_H_ */
