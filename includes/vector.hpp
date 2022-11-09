/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:56:38 by aguay             #+#    #+#             */
/*   Updated: 2022/11/09 08:39:49 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>

namespace ft
{
    template <typename T, typename alloc = std::allocator<T> >
    class vector
    {
        typedef unsigned long long  size_type;
        typedef T                   value_type;
        typedef std::allocator<T>   allocator_type;
        
        public :

        //  =============== CONTRUCTOR          =============== //

            //  Default constructor -> everything empty
            vector(void) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(createAllocator()){}

            //  Fill constructor -> create N element with val as value
            vector(size_type n, value_type & val) : _nbElement(n), _maxElement(n), _allocator(createAllocator())
            {
                fillVector(n, val);
            }

            //  Range constructor -> create elements from iterrator begin to iterrator end

            //  Copy constructor -> Create the vector as a copy or the vector passed as parameter
        
        //  =============== DESTRUCTOR          =============== //
            ~vector(void)
            {
                if (_ptr)
                    _allocator.deallocate(_ptr, _nbElement);
            };

        //  =============== OPERATOR OVERLOAD   =============== //

            //  Assignation operator overload -> change values to the same value of the vector on the right

            //  Index [ ] operator overload. objectName[x] will get the value of the vector at the position x
        

        //  =============== UTILS METHODES      =============== //
        private :

            //  Only use on fill constructor because it allocate all the memory needed
            void    fillVector(size_type n, value_type val)
            {
                //  Note: allocate x2 might be a problem
                addMemory();
                for (size_type x = 0; x <= n; x++)
                    _ptr[x] = val;
            }
        
            void    addObject(value_type val)
            {
                if (_nbElement + 1 > _maxElement)
                    addMemory();
                _nbElement++;
                std::cout << "Need to add " << val << " here" << std::endl;
            }

            void    addMemory(void)
            {
                value_type   *newData;

                if (_maxElement != 0)
                    newData = _allocator.allocate(_maxElement * 2, 0);
                else
                    newData = _allocator.allocate(4, _ptr);
                //  Copy elements here
                if (_maxElement > 0)
                    _allocator.deallocate(_ptr, _maxElement);
                _maxElement = _maxElement * 2;
                _ptr = newData;
            }

           allocator_type   createAllocator(void){allocator_type   x;return (x);}

        //  =============== PRIVATE ATTRIBUTES  =============== //
        private :
            // std::iterator<T>    _begin;
            // std::iterator<T>    _end;
            size_type               _nbElement;
            size_type               _maxElement;
            value_type              *_ptr;
            allocator_type          _allocator;
            
    };
     
}
