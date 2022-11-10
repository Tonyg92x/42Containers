/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:35:49 by aguay             #+#    #+#             */
/*   Updated: 2022/11/10 11:36:45 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

namespace ft{

template<typename T>
class const_reverse_iterator
{
    public :

    //  =============== CONSTRUCTOR             ==============  //
        const_reverse_iterator(void){};
        const_reverse_iterator(T  *ptr) : _ptr(ptr){}
        const_reverse_iterator(const_reverse_iterator const & rhs) {*this = rhs;}

    //  =============== DESTRUCTOR              =============== //
        ~const_reverse_iterator(void){};

    //  =============== OPERATION OVERLOAD'S    =============== //

        //  Assignation operator overload
        const_reverse_iterator &  operator=(const_reverse_iterator const & rhs)        {
            if (this != &rhs)
                this->_ptr = rhs.getPtr();
            return (*this);
        }

        //  Postfix incrementation
        const_reverse_iterator  operator++(int)
        {
            const_reverse_iterator    temp = *this;

            ++(*this);
            return (temp);
        }

        //  Prefix incrementation
        const_reverse_iterator & operator++(){_ptr--;return (*this);}

        //  Postfix decrementation
        const_reverse_iterator operator--(int)
        {
            const_reverse_iterator temp = *this;

            --(*this);
            return (temp);
        }
        
        //  Prefix decrementation
        const_reverse_iterator & operator--(){_ptr++;return (*this);}
        
        //  Deference operator overload
        T &     operator*(void) const{return (*_ptr);}

        //  Deference operator overload
        T &     operator->(void) const{return (*_ptr);}

        //  Boolean algeabra equal operator overload
        bool    operator==(const_reverse_iterator const & rhs) const { return (_ptr == rhs.getPtr());}

        //  Boolean algebra not equal operator overload
        bool    operator!=(const_reverse_iterator const & rhs) const { return (_ptr != rhs.getPtr());}
        
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
