/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:36:55 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 10:42:22 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cstdlib>

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
        static bool convertChar(std::string arg);
        static bool convertInt(std::string arg);
        static bool convertFloat(std::string arg);
        static bool convertDouble(std::string arg);
        static bool checkPseudoLiteralsFloat(std::string arg);
        static bool checkPseudoLiteralsDouble(std::string arg);
        static bool isDot(std::string arg);
};

# endif
