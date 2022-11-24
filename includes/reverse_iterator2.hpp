/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator2.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:18:49 by aguay             #+#    #+#             */
/*   Updated: 2022/11/24 09:35:01 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include <iterator>

//  https://cplusplus.com/reference/iterator/reverse_iterator/

namespace ft
{
    template <class Iterator>
    class   reverse_iterator : public std::iterator<std::reverse_iterator,
        Iterator::value_type, Iterator::difference_type, Iterator::pointer,
        Iterator::reference>
    {
        public :

            typedef typename    Iterator                                            iterator_type;
            typedef typename    std::iterator_traits<Iterator>::iterator_category   iterator_category;
            typedef typename    std::iterator_traits<Iterator>::value_type          value_type;
            typedef typename    std::iterator_traits<Iterator>::diference_type      difference_type;
            typedef typename    std::iterator_traits<Iterator>::pointer             pointer;
            typedef typename    std::iterator_traits<Iterator>::reference           reference;

        public :

        //  =============== CONSTRUCTOR                     =============== //
        //  https://cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/

        //  Default constructor
        reverse_iterator(void){};

        //  Initialisation constructor
        explicit    reverse_iterator(iterator_type  it){};

        //  Copy constructor
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iterator>& rev_it){};

    };
};


