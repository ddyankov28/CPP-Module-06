/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:39 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/27 15:53:18 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string arg)
{
    convertToChar(arg);
    convertToInt(arg);
}

void    ScalarConverter::convertToChar(std::string arg)
{
    std::cout << "char: ";
    
    if (!isdigit(arg[0]) && isprint(arg[0]) && arg.size() == 1)
    {
        std::cout << "'" << arg[0] << "'" << std::endl;
        return ;
    }
    if (ScalarConverter::checkPseudoLiterals(arg) || ScalarConverter::checkForString(arg))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::stringstream   convertToAscii;
    int asciiVal;

    convertToAscii << arg;
    convertToAscii >> asciiVal;
    if (asciiVal >= 0 && asciiVal <= 127)
    {
        if (asciiVal >= 32 && asciiVal <= 126)
            std::cout << "'" << static_cast<char>(asciiVal) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void    ScalarConverter::convertToInt(std::string arg)
{
    std::cout << "int: ";
    if (ScalarConverter::checkPseudoLiterals(arg) || ScalarConverter::checkForString(arg))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::stringstream convertToAscii;
    int asciiVal;
    
    convertToAscii << arg;
    convertToAscii >> asciiVal;
    
}

bool    ScalarConverter::checkPseudoLiterals(std::string arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "nanf" || arg == "-inf" || arg == "+inf" || arg == "nan")
        return true;
    return false;
}

bool    ScalarConverter::checkForString(std::string arg)
{
    if (isalpha(arg[0]) && isalpha(arg[1]))
        return true;
    return false;
}
