/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:39 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 10:30:28 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <cfloat>

void    ScalarConverter::convert(std::string arg)
{
    if (checkPseudoLiteralsFloat(arg) || checkPseudoLiteralsDouble(arg))
        return ;
    if (convertChar(arg) || convertInt(arg) || convertFloat(arg) || convertDouble(arg))
        return ;
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

bool    ScalarConverter::convertChar(std::string arg)
{
    if (arg.size() == 1 && !isdigit(arg[0]) && isprint(arg[0]))
    {
        /*          char        */
        std::cout << "char: ";
    
        std::cout << "'" << arg[0] << "'" << std::endl;
        /*          int         */
        std::cout << "int: ";
        std::cout << static_cast<int>(arg[0]) << std::endl;
        /*          float       */
        std::cout << "float: ";
        std::cout << static_cast<float>(arg[0]) << ".0f" << std::endl;
        /*          double      */
        std::cout << "double: ";
        std::cout << static_cast<double>(arg[0]) << ".0" << std::endl;
        return true;
    }
    return false;
}

bool   ScalarConverter::convertInt(std::string arg)
{
    std::stringstream stream_arg;
    std::stringstream check;
    int i;
    
    stream_arg << arg;
    stream_arg >> i;
    check << i;
    if (arg != check.str())
        return false;
    std::cout << "char: ";
    if (isascii(i))
    {
        if (isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    return true;
}

bool    ScalarConverter::convertFloat(std::string arg)
{
    std::stringstream stream_arg;
    float f;
    
    if (arg[arg.size() -1] != 'f')
        return false ;
    stream_arg << arg;
    stream_arg >> f;
    
    std::cout << "char: ";
    if (isascii(f))
    {
        if (isprint(f))
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(f) <<  std::endl;
    if (arg[arg.size() - 1] == 'f' && arg[arg.size() - 2] == '0' && arg[arg.size() - 3] == '.')
    {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << ".0"<< std::endl;
    }
    else
    {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    return true;
}

bool    ScalarConverter::convertDouble(std::string arg)
{
    std::stringstream stream_arg;
    double d;

    if (!isdigit(arg[arg.size() -1]) || !isDot(arg))
        return false ;
    stream_arg << arg;
    stream_arg >> d;
    std::cout << "char: ";
    if (isascii(d))
    {
        if (isprint(d))
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
    std::cout << "int: " << static_cast<int>(d) <<  std::endl;
    if (arg[arg.size() - 1] == '0' && arg[arg.size() - 2] == '.')
    {
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0"<< std::endl;
    }
    else
    {
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    return true;
}

bool   ScalarConverter::checkPseudoLiteralsFloat(std::string arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << arg << std::endl;
        std::cout << "double: " << arg.substr(0, arg.size() - 1) << std::endl;
        return true;
    }
    return false;
}

bool   ScalarConverter::checkPseudoLiteralsDouble(std::string arg)
{
    if (arg == "-inf" || arg == "+inf" || arg == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << arg + "f" << std::endl;
        std::cout << "double: " << arg << std::endl;
        return true;
    }
    return false;
}

bool ScalarConverter::isDot(std::string arg)
{
    int i = 0;
    while (arg[i])
    {
        if (arg[i] == '.')
            return true;
        i++;
    }
    return false;  
}
