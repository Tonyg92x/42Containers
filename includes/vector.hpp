/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:56:38 by aguay             #+#    #+#             */
/*   Updated: 2022/11/23 13:55:46 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <memory>
#include <iostream>
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "const_iterator.hpp"
#include "const_reverse_iterator.hpp"

namespace ft
{
    template <typename T, typename alloc = std::allocator<T> >
    class vector
    {
        public :
        
            typedef T                                                           value_type;
            typedef typename    std::allocator<value_type>                      allocator_type;
            typedef typename    allocator_type::reference                       reference;
            typedef typename    allocator_type::const_reference                 const_reference;
            typedef typename    allocator_type::pointer                         pointer;
            typedef typename    allocator_type::const_pointer                   const_pointer;
            typedef typename    ft::vector_iterator<value_type>                 iterator;
            typedef typename    ft::reverse_iterator<value_type>                reverse_iterator;
            typedef typename    ft::const_iterator<const value_type>            const_iterator;
            typedef typename    ft::const_reverse_iterator<const value_type>    const_reverse_iterator;
            typedef typename    ft::vector_iterator<value_type>                 InputIterator;

            //  Add difference type here
            typedef unsigned long long                                          size_type;
        
        public :

        //  =============== CONTRUCTOR          =============== //

            //  Default constructor -> everything empty
            vector(void) : _nbElement(0), _maxElement(0), _ptr(NULL), _allocator(init()){}

            //  Fill constructor -> create N element with val as value
            vector(size_type n, value_type & val) : _nbElement(0), _maxElement(n), _allocator(init(n))
            {
                ft_allocate(n);
                _nbElement = n;
                for (size_type i = 0; i < n; i++)
                    _ptr[i] = val;
            }

            //  Overload assignation construtor for non ref values ?
            
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
            ~vector(void){ft_deallocate();};

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

        //  Return a random acces iterator to the first element of the vector
        iterator    begin(void) const {iterator    y(&(_ptr[0]));return (y);}

        //  Return a random access iterator right after the last element of the vector
        iterator    end(void) const {iterator    y(&(_ptr[_nbElement]));return (y);}

        //  Return a random access reverse iterator pointing at the last element of the vector
        reverse_iterator    rbegin(void) const
        {
            if (_ptr && _nbElement > 0)
            {
                reverse_iterator y(&(_ptr[_nbElement - 1]));
                return (y);
            }
            reverse_iterator y;
            return (y);
        }
        
        //  Return a random access reverse iterator pointing at right before the first element of the vector
        reverse_iterator    rend(void) const
        {
            reverse_iterator    y(&(_ptr[-1]));
            
            return (y);    
        }
        
        //  Return a random access const iterator pointing at the first element in the vector
        const_iterator      cbegin(void) const {const_iterator    y(&(_ptr[0]));return (y);}
        
        //  Return a random acces const iterator pointing at right after the last element in the vector
        const_iterator      cend(void) const {const_iterator    y(&(_ptr[_nbElement]));return (y);}
        
        //  Return a random acces const reverse iterator pointing at the last element in the vector
        const_reverse_iterator  crbegin(void) const 
        {
            if (_ptr && _nbElement > 0)
            {
                const_reverse_iterator y(&(_ptr[_nbElement - 1]));
                return (y);
            }
            const_reverse_iterator y;
            return (y);
        }

        //  Return a random acces const reverse iterator pointing at right before the first element in the vector
        const_reverse_iterator crend(void) const 
        {
            const_reverse_iterator    y(&(_ptr[-1]));
            return (y);    
        }

        
        //  =============== CAPACITY            =============== //

        //  Size -> Return the number of element in the vector
        size_type   size(void) const {return (_nbElement);}

        //  Max_size -> Return the maximum number of element that the vector can hold
        size_type   max_size(void) const
        {
            size_t  size = sizeof(value_type) / 2;

            if (size == 0)
                size = 1;
            return (9223372036854775807 / size);
        }

        //  Resize -> Change the size of the container so it can hold n number of elements
        void        resize(size_t n)
        {
            if (n == _nbElement)
                return;
            else if (n > _nbElement)
            {
                while (n > _nbElement)
                    addVal(0);
            }
            else if (n < _nbElement)
            {
                while (n < _nbElement)
                    pop_back();
            }
        }

        void        resize(size_t n, value_type val)
        {
            if (n == _nbElement)
                return;
            else if (n > _nbElement)
            {
                while (n > _nbElement)
                    addVal(val);
            }
            else if (n < _nbElement)
            {
                while (n < _nbElement)
                    pop_back();
            }
        }

        //  Capacity -> Return the size of the storage currently allocated in the vector
        size_type   capacity(void) const {return (_maxElement);};

        //  Empty -> Return wheter the vector is empty or not
        

        //  Reserve -> Request that the vector capacity be at least enough to contain n elements

        //  =============== MODIFIER            =============== //
        
        //  Assign overload range -> Replace all memory in the vector for first to last
        void    assign(iterator first, iterator last)
        {

            ft_deallocate();
            for (iterator ite = first; ite != last; ite++)
                addVal(*ite);
        }

        //  Assign overload fill -> Replace all memory in the vector for n element of value val
        void    assign(size_type n, const value_type& val)
        {
            ft_deallocate();
            ft_allocate(n);
            _nbElement = n;
            for (size_type i = 0; i < n; i++)
                _ptr[i] = val;
        }

        //  Push_back -> add the value at the end of the vector
        void    push_back(const value_type & val){addVal(val);}

        //  Pop_back -> remove the value at the end of the vector
        void    pop_back(void)
        {
            if (_nbElement > 0)
            {
                _allocator.destroy(&_ptr[_nbElement - 1]);
                _nbElement--;
            }
        }

        //  Insert -> add element(s) at the position and shift the following values
        iterator    insert(iterator position, const value_type& val)
        {
            if (_nbElement + 1 > _maxElement)
            {
                size_t  it_pos = iterator_pos(position);
                addMemoryXTwo();
                iterator new_pos(&(_ptr[it_pos]));
                position = new_pos;
            }
            shift(position, 1);
            *position = val;
            _nbElement++;
            return (position);
        }

        //  Insert -> add element(s) at the position and shift the following values
        void    insert(iterator position, size_type n, const value_type& val)
        {
            _nbElement += n;
            size_t  it_pos = iterator_pos(position);

            while (_nbElement > _maxElement)
            {
                addMemoryXTwo();
                iterator new_pos(&(_ptr[it_pos]));
                position = new_pos;
            }
            shift(position, n);
            for (size_type i = 0; i < n; i++)
            {
                *position = val;
                position++;
            }
        }

        //  Insert -> add element(s) at the position and shift the following values
        void    insert(iterator position, InputIterator first, InputIterator last)
        {
            size_t  it_pos = iterator_pos(position);

            while (first != last)
            {
                if (_nbElement + 1 > _maxElement)
                {
                    addMemoryXTwo();
                    iterator new_pos(&(_ptr[it_pos]));
                    position = new_pos;
                }
                shift(position, 1);
                *position = *first;
                _nbElement++;
                position++;
                first++;
            }
        }

        //  Erase ->

        //  Swap ->

        //  Clear ->


        //  =============== GET METHOD'S        =============== //
        public:
            
            //  Get_allocator -> Return the vector allocator
            allocator_type  get_allocator(void) const {return (_allocator);}
    
        //  =============== PRIVATE METHOD'S    =============== //
        private :

            //  NOTE -> for every data allocation function, protect if there is no place left to do it

            size_type   iterator_pos(iterator const & it)
            {
                size_type   pos = 0;
                iterator    begin(&(_ptr[0]));

                for (iterator ite = begin; ite != it; ite++)
                    pos++;
                return (pos);
            }
            
            //  Shift every following element n time.
            void    shift(iterator const & it, size_type n)
            {
                size_type   following_elem = _nbElement - iterator_pos(it);
                size_type   index = _nbElement - 1;

                for (size_type x = 0; x < following_elem; x++)
                {
                    _ptr[index + n] = _ptr[index];
                    index--;
                }
            }
            
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
                if (_nbElement == _maxElement)
                    addMemoryXTwo();
                _ptr[_nbElement++] = val;
            }

            //  Multiplicate the memory by two
            void    addMemoryXTwo(void)
            {
                value_type   *newData;

                //  Allocate the new memory
                if (_maxElement != 0)
                    newData = _allocator.allocate(_maxElement * 2, _ptr);
                else
                    newData = _allocator.allocate(4, 0);

                //  Copy data to new address
                for (size_type x = 0; x < _nbElement; x++)
                    newData[x] = _ptr[x];

                //  Deallocate previous pointer
                if (_ptr)
                    _allocator.deallocate(_ptr, _maxElement);

                //  Save change
                if (_maxElement == 0)
                    _maxElement = 4;
                else
                    _maxElement = _maxElement * 2;
                _ptr = newData;
            }
            
            //  Allocate memory for n element
            void    ft_allocate(size_type n)
            {
                if (_ptr)
                    ft_deallocate();
                _ptr = _allocator.allocate(n, 0);
                _maxElement = n;
            }

            //  Destroy every element then deallocate the memory
            void    ft_deallocate(void)
            {
                for (size_type n = 0; n < _nbElement; n++)
                    _allocator.destroy(&_ptr[n]);
                _allocator.deallocate(_ptr, _maxElement);
                _nbElement = 0;
                _maxElement = 0;
                _ptr = NULL;
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
};
