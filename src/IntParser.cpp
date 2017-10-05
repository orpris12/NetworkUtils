/*
 * IntParser.cpp
 *
 *  Created on: Jun 5, 2017
 *      Author: user
 */

#include "IntParser.h"

namespace Lab {


string IntParser::parse(int num) {
	std::ostringstream ss;
	ss << num;
	return ss.str();
}

} /* namespace Lab */
