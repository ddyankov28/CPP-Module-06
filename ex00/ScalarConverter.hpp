/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:36:55 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/27 15:16:37 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

// inf  -> positive infinity
// -inf -> negative infinity
// nan  -> not a number
// +f is for the floats

class ScalarConverter
{
    private:
        ScalarConverter();                                          //  constructor
        ScalarConverter(const ScalarConverter& inst);               //  copy constructor
        ScalarConverter&  operator=(const ScalarConverter& inst);   //  copy assign
        ~ScalarConverter();                                         //  destructor
    public:
        static void convert(std::string arg);
        static bool isChar(std::string arg);
        static void convertChar(std::string arg);
        static void convertToInt(std::string arg);
        static bool checkPseudoLiterals(std::string arg);
        static bool checkForString(std::string arg);
};

# endif
