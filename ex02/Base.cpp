/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:50:53 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 17:04:33 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base()
{}

Base*   generate(void)
{
    std::srand(time(NULL));
    int i = rand() % 3;

    switch (i)
    {
        case 0 : return new A;
        case 1 : return new B;
        case 2 : return new C;
            break ;
        default: return NULL;
            break;
    }
}

void    identify(Base* p)
{
    std::cout << YELLOW << "---USING POINTERS---" << RESET << std::endl;
    A* ptrA = dynamic_cast<A*>(p);
    B* ptrB = dynamic_cast<B*>(p);
    C* ptrC = dynamic_cast<C*>(p);
    std::string type;
    
    std::cout << "ptrA = " << ptrA << std::endl;
    std::cout << "ptrB = " << ptrB << std::endl;
    std::cout << "ptrC = " << ptrC << std::endl;

    if (ptrA)
        type = "A";
    else if (ptrB)
        type = "B";
    else if (ptrC)
        type = "C";
    else
        type = "Unknown type";
    std::cout << "The type of the object is: " << type << std::endl;
}

void    identify(Base& p)
{
    std::cout << CYAN << "---USING REFERENCE---" << RESET << std::endl;
    try
    {
        A& refA = dynamic_cast<A&>(p);
        std::cout << "refA = " << &refA << std::endl;
        (void)refA;
        std::cout << "The type of the object is: A" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr <<  URED << "THE REASON WHY THE TYPE IS NOT A IS BECAUSE OF THE " << e.what() << RESET << std::endl;
    }
    try
    {
        B& refB = dynamic_cast<B&>(p);
        std::cout << "refB = " << &refB << std::endl;
        (void)refB;
        std::cout << "The type of the object is: B" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "THE REASON WHY THE TYPE IS NOT B IS BECAUSE OF THE " << e.what() << RESET << std::endl;
    }
    try
    {
        C& refC = dynamic_cast<C&>(p);
        std::cout << "refC = " << &refC << std::endl;
        (void)refC;
        std::cout << "The type of the object is: C" << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << URED << "THE REASON WHY THE TYPE IS NOT C IS BECAUSE OF THE " << e.what() << RESET << std::endl;
    }
}
