/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:17:50 by aguay             #+#    #+#             */
/*   Updated: 2022/11/23 14:06:05 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"

namespace ft
{
    template<typename T>
    class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
        public :

        //  =============== CONSTRUCTOR             ==============  //
            vector_iterator(void){};
            vector_iterator(T  *ptr) : _ptr(ptr){}
            vector_iterator(vector_iterator const & rhs) {*this = rhs;}

        //  =============== DESTRUCTOR              =============== //
            ~vector_iterator(void){};

        //  =============== OPERATION OVERLOAD'S    =============== //

            //  Assignation operator overload
            vector_iterator &  operator=(vector_iterator const & rhs)
            {
                if (this != &rhs)
                    this->_ptr = rhs.getPtr();
                return (*this);
            }

            vector_iterator & operator=(int i)
            {
                for (int x = 0; x < i; i++)
                    _ptr++;
                return (*this);
            }

            //  Postfix incrementation
            vector_iterator  operator++(int)
            {
                vector_iterator    temp = *this;

                ++(*this);
                return (temp);
            }

            //  Prefix incrementation
            vector_iterator & operator++(){_ptr++;return (*this);}

            //  Postfix decrementation
            vector_iterator operator--(int)
            {
                vector_iterator temp = *this;

                --(*this);
                return (temp);
            }
            
            //  Prefix decrementation
            vector_iterator & operator--(){_ptr--;return (*this);}
            
            //  Deference lvalue operator overload
            T &     operator*(void) const{return (*_ptr);}

            //  Deference rvalue operator overload
            T       *operator->(void) const{return &(operator*());}

            //  Arithmetic expression It + n
            vector_iterator    operator+(int i)
            {
                _ptr += i;
                return (*this);
            }

            //  Arithmetic espression It - n
            vector_iterator    operator-(int i)
            {
                _ptr -= i;
                return (*this);
            }

            //  Arithmetic expression It += n
            vector_iterator    operator+=(int i)
            {
                _ptr += i;
                return (*this);
            }

            //  Arithmetic expression It -= n
            vector_iterator    operator-=(int i)
            {
                _ptr -= i;
                return (*this);
            }

            //  Boolean algebra It < x
            bool    operator<(vector_iterator const & rhs){return (_ptr < rhs.getPtr());}

            //  Boolean algebra It > x
            bool    operator>(vector_iterator const & rhs){return (_ptr > rhs.getPtr());}

            //  Boolean algebra It <= x
            bool    operator<=(vector_iterator const & rhs){return (_ptr <= rhs.getPtr());}

            //  Boolean algebra IT >= x
            bool    operator>=(vector_iterator const & rhs){return (_ptr >= rhs.getPtr());}

            //  Boolean algeabra equal operator overload
            bool    operator==(vector_iterator const & rhs) const { return (_ptr == rhs.getPtr());}

            //  Boolean algebra not equal operator overload
            bool    operator!=(vector_iterator const & rhs) const { return (_ptr != rhs.getPtr());}
            
            //  Boolean algebra is not operator overload
            bool    operator!() const 
            {
                if (_ptr)
                    return (true);
                return (false);
            }

            //  Accessor x[]
            T&   operator[](std::size_t  x) const {return (_ptr + x);}

            
        //  =============== PUBLIC METHOD'S         =============== //

            T   *getPtr(void) const {return (_ptr);}     

        //  =============== PRIVATE METHOD'S        =============== //
        private:
            

        //  =============== PRIVATE ATTRIBUTES      =============== //
        private :
            T   *_ptr;
    };
}
