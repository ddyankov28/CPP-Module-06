/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:37:03 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 16:56:10 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializator.hpp"
# include "Data.hpp"

int main()
{
    Data        data;
    Data*       ptr;
    uintptr_t   raw;
    
    ptr = &data;
    data.intMember = 42;
    data.doubleMember = 42.53;
    data.stringMember = "42 Vienna";
    data.boolMember = true;

    raw = Serializer::serialize(ptr);
    
    Data* ptr1;
    ptr1 = Serializer::deserialize(raw);
    
    std::cout << GREEN << "AFTER SERIALIZE AND DESERIALIZE" << RESET << std::endl;
    std::cout << ptr1->intMember << std::endl;LINE
    std::cout << ptr1->doubleMember << std::endl;LINE  
    std::cout << ptr1->stringMember << std::endl;LINE   
    std::cout << std::boolalpha << ptr1->boolMember << std::endl;LINE
    std::cout << ptr1 << std::endl;

    std::cout << RED << "ORIGINAL POINTER" << RESET << std::endl;
    std::cout << ptr->intMember << std::endl;LINE
    std::cout << ptr->doubleMember << std::endl;LINE  
    std::cout << ptr->stringMember << std::endl;LINE   
    std::cout << std::boolalpha << ptr->boolMember << std::endl;LINE
    std::cout << ptr << std::endl;

    return 0;
}
