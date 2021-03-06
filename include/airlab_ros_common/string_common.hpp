#ifndef __AIRLAB_ROS_COMMON_STRING_COMMON_HPP__
#define __AIRLAB_ROS_COMMON_STRING_COMMON_HPP__

#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

template<typename T>
std::vector<T> extract_number_from_string(
    const std::string& s, 
    const int expected, 
    const std::string& delimiter=",") {

    if ( expected <= 0 ) {
        std::stringstream ss;
        ss << "Exprected number must be positive. expected = " << expected << ". ";
        throw std::runtime_error(ss.str());
    }

    // Split the string.
    std::vector<std::string> splitString;
    boost::split(splitString, s, boost::is_any_of(delimiter));

    if ( splitString.size() != expected ) {
        std::stringstream ss;
        ss << "Wrong number of split strings (" << splitString.size() << "). "
           << "Expecting " << expected << " from \"" << s << "\". ";
        throw std::runtime_error(ss.str());
    }

    // Convert the strings into numbers.
    T number;
    std::stringstream ss;
    std::vector<T> numbers;

    for ( auto& fs : splitString ) {
        ss.str(""); ss.clear(); ss << fs;
        ss >> number;
        numbers.push_back(number);
    }

    return numbers;
}

#endif // __AIRLAB_ROS_COMMON_STRING_COMMON_HPP__