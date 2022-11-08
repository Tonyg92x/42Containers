/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:56:38 by aguay             #+#    #+#             */
/*   Updated: 2022/11/08 15:06:06 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>
#include <iostream>

namespace ft
{
    template <typename T, typename alloc = std::allocator<T> >
    class vector
    {
        public :

        //  =============== CONTRUCTOR          =============== //
            vector(void) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(createAllocator()){}

        
        //  =============== DESTRUCTOR          =============== //
            ~vector(void)
            {
                if (_ptr)
                    _allocator.deallocate(_ptr, _nbElement);
            };

        //  =============== OPERATOR OVERLOAD   =============== //
        

        //  =============== UTILS METHODES      =============== //
        public :
            void    addObject(T obj)
            {
                if (_nbElement + 1 > _maxElement)
                    addMemory();
                _nbElement++;
                std::cout << "Need to add " << obj << " here" << std::endl;
            }

            void    addMemory(void)
            {
                T   *newData;

                if (_maxElement != 0)
                    newData = _allocator.allocate(_maxElement * 2, 0);
                else
                    newData = _allocator.allocate(4, 0);
                //  Copy elements here
                if (_maxElement > 0)
                    _allocator.deallocate(_ptr, _maxElement);
                _maxElement = _maxElement * 2;
                _ptr = newData;
            }

            std::allocator<T>   createAllocator(void){std::allocator<T>   x;return (x);}

        //  =============== PRIVATE ATTRIBUTES  =============== //
        private :
            // std::iterator<T>    _begin;
            // std::iterator<T>    _end;
            unsigned long long      _nbElement;
            unsigned long long      _maxElement;
            T                       *_ptr;
            std::allocator<T>       _allocator;
    };
     
}
