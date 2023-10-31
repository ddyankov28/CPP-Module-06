/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:56:21 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 16:06:24 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main()
{
    Base*   base1;
    base1 = generate();
    Base&   ref = *base1;
    identify(base1);
    identify(ref);
    delete base1;
    
    return 0;
}
