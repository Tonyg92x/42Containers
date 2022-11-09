/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:56:38 by aguay             #+#    #+#             */
/*   Updated: 2022/11/09 14:58:24 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <memory>
#include <iostream>
#include "iterator.hpp"

namespace ft
{
    template <typename T, typename alloc = std::allocator<T> >
    class vector
    {
        typedef T                                                           value_type;
        typedef typename    std::allocator<value_type>                      allocator_type;
        typedef typename    allocator_type::reference                       reference;
        typedef typename    allocator_type::const_reference                 const_reference;
        typedef typename    allocator_type::pointer                         pointer;
        typedef typename    allocator_type::const_pointer                   const_pointer;
        typedef typename    ft::iterator<value_type>                        iterator;
        //  Add difference type here
        typedef unsigned long long                                          size_type;
        
        public :

        //  =============== CONTRUCTOR          =============== //

            //  Default constructor -> everything empty
            vector(void) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(init()){}

            //  Fill constructor -> create N element with val as value
            vector(size_type n, value_type & val) : _nbElement(0), _maxElement(n), _allocator(init(n))
            {
                for (size_type x = 0; x < n; x++)
                   addVal(val);
            }

            //  Range constructor -> create elements from iterrator begin to iterrator end
            vector(iterator first, iterator last) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(init())
            {
                while (first != last)
                {
                     addVal(*first);
                    first++;
                }
            }
            
            //  Copy constructor -> Create the vector as a copy or the vector passed as parameter
            vector(vector const & rhs) {*this = rhs;}
        
        //  =============== DESTRUCTOR          =============== //
            ~vector(void)
            {
                if (_ptr)
                    _allocator.deallocate(_ptr, _maxElement);
            };

        //  =============== OPERATOR OVERLOAD   =============== //

            vector &    operator=(vector const & rhs)
            {
                if (this != &rhs)
                {
                    _nbElement = rhs.size();
                    _maxElement = rhs.capacity();
                    init(_nbElement);
                    size_type x = 0;
                    for (iterator ite = rhs.begin(); ite != rhs.end(); ite++)
                        _ptr[x++] = *ite;
                }
                return (*this);
            }
            
            value_type &  operator[](std::size_t i)
            {
                // Protection here for overload
                return (_ptr[i]);
            }
        
        //  =============== ITERATOR'S          =============== //
        iterator    begin(void) const {iterator    y(&(_ptr[0]));return (y);}

        iterator    end(void) const {iterator    x(&(_ptr[_nbElement]));return (x);}
    
        //  =============== CAPACITY            =============== //
        size_type   size(void) const {return (_nbElement);}

        size_type   capacity(void) const {return (_maxElement);};

        //  =============== MODIFIER            =============== //
        
        //  MODIFIER -> ASSIGN

        //  MODIFIER -> PUSH_BACK
        void    push_back(const value_type & val){addVal(val);}

        // //  MODIFIER -> POP_BACK
        void    pop_back(void)
        {
            if (_nbElement > 0)
            {
                _allocator.destroy(&_ptr[_nbElement - 1]);
                _nbElement--;
            }
        }

        //  MODIFIER -> INSERT

        //  MODIFIER -> ERASE

        //  MODIFIER -> SWAP

        //  MODIFIER -> CLEAR

        //  MODIFIER -> EMPLACE

        //  MODIFIER -> EMPLACE_BACK
    
        //  =============== PRIVATE METHOD'S    =============== //
        private :

            //  Add the value to the container
            void    addVal(value_type & val)
            {
                if (_nbElement + 1 > _maxElement)
                    addMemoryXTwo();
                _ptr[_nbElement++] = val;
            }

            //  Add the value to the container
            void    addVal(const value_type & val)
            {
                if (_nbElement + 1 > _maxElement)
                    addMemoryXTwo();
                _ptr[_nbElement++] = val;
            }

            //  Multiplicate the memory by two
            void    addMemoryXTwo(void)
            {
                value_type   *newData;

                //  Allocate the new memory
                newData = _allocator.allocate(_maxElement * 2, _ptr);

                //  Copy data to new address
                for (size_type x = 0; x < _nbElement; x++)
                    newData[x] = _ptr[x];

                //  Deallocate previous pointer
                _allocator.deallocate(_ptr, _maxElement);

                //  Save change
                _maxElement = _maxElement * 2;
                _ptr = newData;
            }
            
            //  Initialise an empty container
            allocator_type   init(void)
            {
                allocator_type  x;
                return (x);
            }

            //  Initialise a container with n elements
            allocator_type   init(size_type n)
            {
                allocator_type  x;
                value_type      *ptr;

                //  allocation sizeof(size_type) * n
                ptr = x.allocate(n, 0);
                _ptr = ptr;

                return (x);
            }

        //  =============== PRIVATE ATTRIBUTES  =============== //
        private :
            size_type                   _nbElement;
            size_type                   _maxElement;
            value_type                  *_ptr;
            allocator_type              _allocator;
    };
     
}
