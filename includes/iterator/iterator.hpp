/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:17:50 by aguay             #+#    #+#             */
/*   Updated: 2022/11/10 10:05:51 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft{

template<typename T>
class iterator
{
    public :

    //  =============== CONSTRUCTOR             ==============  //
        iterator(void){};
        iterator(T  *ptr) : _ptr(ptr){}
        iterator(iterator const & rhs) {*this = rhs;}

    //  =============== DESTRUCTOR              =============== //
        ~iterator(void){};

    //  =============== OPERATION OVERLOAD'S    =============== //

        //  Assignation operator overload
        iterator &  operator=(iterator const & rhs)        {
            if (this != &rhs)
                this->_ptr = rhs.getPtr();
            return (*this);
        }

        //  Postfix incrementation
        iterator  operator++(int)
        {
            iterator    temp = *this;

            ++(*this);
            return (temp);
        }

        //  Prefix incrementation
        iterator & operator++(){_ptr++;return (*this);}

        //  Postfix decrementation
        iterator operator--(int)
        {
            iterator temp = *this;

            --(*this);
            return (temp);
        }
        
        //  Prefix decrementation
        iterator & operator--(){_ptr--;return (*this);}
        
        //  Deference operator overload
        T &     operator*(void) const{return (*_ptr);}

        //  Deference operator overload
        T &     operator->(void) const{return (*_ptr);}

        //  Boolean algeabra equal operator overload
        bool    operator==(iterator const & rhs) const { return (_ptr == rhs.getPtr());}

        //  Boolean algebra not equal operator overload
        bool    operator!=(iterator const & rhs) const { return (_ptr != rhs.getPtr());}
        
        //  Boolean algebra is not operator overload
        bool    operator!() const 
        {
            if (_ptr)
                return (true);
            return (false);
        }

    //  =============== PUBLIC METHOD'S         =============== //

        T   *getPtr(void) const {return (_ptr);}     

    //  =============== PRIVATE METHOD'S        =============== //
    private:
        

    //  =============== PRIVATE ATTRIBUTES      =============== //
    private :

        T   *_ptr;
};
}