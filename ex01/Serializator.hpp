/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:35:56 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 12:32:48 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZATOR_HPP
# define SERIALIZATOR_HPP

# include <iostream>
# include "Data.hpp"
# include <stdint.h>


# define URED "\033[4;31m"
# define RED "\033[1;91m"
# define GREEN "\033[1;92m"
# define YELLOW "\033[1;93m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define LINE  std::cout << "-------------------------" << std::endl;

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& inst);
        Serializer& operator=(const Serializer& inst);
        ~Serializer();
    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*   deserialize(uintptr_t raw);
};

# endif
