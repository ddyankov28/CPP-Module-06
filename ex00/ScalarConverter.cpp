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
    if (isChar(arg))
        convertChar(arg);
}

bool    ScalarConverter::isChar(std::string arg)
{
    if (!isdigit(arg[0]) && isprint(arg[0]) && arg.size() == 1)
        return true;
    return false;
}

void    ScalarConverter::convertChar(std::string arg)
{
    std::stringstream   stream;
    int i;

    stream << arg;
    stream >> i;
    if (i >= 0 && i <= 127)
    {
        if (i < 32 || i > 126)
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

void    ScalarConverter::convertToInt(std::string arg)
{
    if (ScalarConverter::checkPseudoLiterals(arg) || ScalarConverter::checkForString(arg))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    std::stringstream stream;
    int i;
    
    stream << arg;
    stream >> i;
    
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
