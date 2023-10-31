/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:53:51 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 12:27:34 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
# define DATA_HPP

# include "Serializator.hpp"

struct Data
{
    std::string stringMember;   
    int         intMember;
    double      doubleMember;
    bool        boolMember;
};

# endif
