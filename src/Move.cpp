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

int Move::value() const {
	 return value_;
}

string Move::toString() const {
	switch (value_) {
		case 1:
			return "R ";
		case 2:
			return "RD";
		case 3:
			return "D ";
		case 4:
			return "LD";
		case 5:
			return "L ";
		case 6:
			return "LU";
		case 7:
			return "U ";
		case 8:
			return "RU";
		default:
			throw new string("Invalid move");
	}
}
