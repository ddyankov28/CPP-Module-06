/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:06:45 by ddyankov          #+#    #+#             */
/*   Updated: 2023/10/31 12:33:26 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializator.hpp"

uintptr_t   Serializer::serialize(Data* ptr)
{
    uintptr_t raw;
    raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    Data*   ptr;
    ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}
