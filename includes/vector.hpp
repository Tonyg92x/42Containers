/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:56:38 by aguay             #+#    #+#             */
/*   Updated: 2022/11/09 11:28:31 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        typedef ft::iterator<value_type>                                    iterator;
        //  Add difference type here
        typedef unsigned long long                                          size_type;
        
        public :

        //  =============== CONTRUCTOR          =============== //

            //  Default constructor -> everything empty
            vector(void) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(init()){}

            //  Fill constructor -> create N element with val as value
            vector(size_type n, value_type & val) : _nbElement(n), _maxElement(n), _allocator(init(n))
            {
                for (size_type x = 0; x < n; x++)
                    _ptr[x] = addVal(val);
            }

            //  Range constructor -> create elements from iterrator begin to iterrator end

            //  Copy constructor -> Create the vector as a copy or the vector passed as parameter
        
        //  =============== DESTRUCTOR          =============== //
            ~vector(void)
            {
                if (_ptr)
                    delete [] _ptr;
            };

        //  =============== OPERATOR OVERLOAD   =============== //

            //  Assignation operator overload -> change values to the same value of the vector on the right

            //  Index [ ] operator overload. objectName[x] will get the value of the vector at the position x
            value_type &  operator[](std::size_t i)
            {
                // Protection here for overload
                return (_ptr[i]);
            }
        
        //  =============== PRIVATE METHOD'S    =============== //
        iterator    begin(void) const {return (_begin);}

        iterator    end(void) const {return (_end);}
        
        //  =============== PRIVATE METHOD'S    =============== //
        private :

            //  Add the value to the container
            void    addVal(value_type & val)
            {
                if (_nbElement + 1 > _maxElement)
                    addMemoryXTwo();
                _ptr[_nbElement++] = val;
                _end++;
            }

            //  Multiplicate the memory by two
            void    addMemoryXTwo(void)
            {
                value_type   *newData;

                //  Allocate the new memory
                newData = _allocator.allocate(_maxElement * 2, _ptr);
                
                //  Update begin and end iterator
                iterator    b(newData);
                _begin      = b;

                iterator    e(newData + _nbElement);
                _end        = e;

                //  Copy data to new address
                for (size_type x = 0; x < _nbElement; x++)
                    newData[x] = _ptr[x];

                //  Deallocate previous pointer
                if (_maxElement > 0)
                    _allocator.deallocate(_ptr, _maxElement);

                //  Save change
                _maxElement = _maxElement * 2;
                _ptr = newData;
            }
            
            //  Initialise an empty container
            allocator_type   init(void)
            {
                allocator_type  x;
                value_type      *ptr;

                //  Allocating end of vector memory
                ptr = x.allocate(1, 0);
                _ptr = ptr;

                //  Creating the iterator's
                iterator    begin(ptr);
                iterator    end(ptr);
                _begin = begin;
                _end = end;
                return (x);
            }

            //  Initialise a container with n elements
            allocator_type   init(size_type n)
            {
                allocator_type  x;
                value_type      *ptr;

                //  Allocating end of vector memory
                ptr = x.allocate(n + 1, 0);
                _ptr = ptr;

                //  Creating the iterator's
                iterator    begin(ptr);
                iterator    end(ptr);
                _begin = begin;
                _end = end;
                return (x);
            }

        //  =============== PRIVATE ATTRIBUTES  =============== //
        private :
            size_type                   _nbElement;
            size_type                   _maxElement;
            value_type                  *_ptr;
            allocator_type              _allocator;
            iterator                    _begin;
            iterator                    _end;
    };
     
}
