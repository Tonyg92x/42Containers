/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:17:50 by aguay             #+#    #+#             */
/*   Updated: 2022/11/09 11:25:58 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <assert.h>

namespace ft{

template<typename T>
class iterator
{
    public :

    //  =============== CONSTRUCTOR             ==============  //
        iterator(void);
        iterator(T  *ptr) : _ptr(isValid(ptr)){}
        iterator(T const & rhs) {*this = rhs;}

    //  =============== DESTRUCTOR              =============== //
        ~iterator(void){};

    //  =============== OPERATOR OVERLOAD'S     =============== //
        iterator &  operator=(T const & rhs)
        {
            if (this != &rhs)
                this->_ptr = rhs.getPtr();
            return (*this);
        }
        iterator &  operator++(void) {_ptr++;}

    //  =============== PUBLIC METHOD'S         =============== //
        T &     getPtr(void) const {return (_ptr);}        

    //  =============== PRIVATE METHOD'S        =============== //
    private:

        T   *isValid(T *ptr) {return (ptr);}
        

    //  =============== PRIVATE ATTRIBUTES      =============== //
    private :

        T   *_ptr;
};
}
