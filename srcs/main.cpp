/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:20:00 by aguay             #+#    #+#             */
/*   Updated: 2022/11/10 14:44:32 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include "include.hpp"

//  Timing
#define MsBetweenTestType 550
#define MsBetweenTest 300

//  Test bool (do it or not)

//  Global test
#define IteratorTests true

//  Unit test
#define IteratorConstructor true
#define IteratorOperatorOverload true
#define IteratorDefenceTest true

int	main(void)
{
    ft::vector<float>   x;
    
    x.push_back(0);
    x.push_back(12.2);
    x.push_back(42.42);
    x.push_back(-123);
    x.push_back(-1000);
    x.push_back(1000);
    x.push_back(4242);
    x.push_back(1);
    x.push_back(-15);
    x.push_back(201);

    // =============== Bidirectional iterator       ===============//
    if (IteratorTests)
    {
        ft::vector<float>::iterator first = x.begin();
        ft::vector<float>::iterator last = --(x.end());

        std::cout << GREEN << UNDERLINE << "\nTest for bidirectional iterator\n" << NORMAL << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

        // ===============  Constructor test's      ===============//
        if (IteratorConstructor)
        {
            std::cout << RED << UNDERLINE << "\nCONSTRUCTOR TEST'S" << NORMAL << std::endl;
    
            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

            //  Copy constructor test
            std::cout << UNDERLINE "\nCopy constructor test\n" << NORMAL << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

            ft::vector<float>::iterator CopyLast(last);
            ft::vector<float>::iterator CopyFirst(first);

            std::cout << "first == " << *first << " == " << *CopyFirst << std::endl;
            std::cout << "last == " << *last << " == " << *CopyLast << std::endl << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            //  Test 0
            if (last == CopyLast)
                std::cout << GREEN << "Copy constructor test 0: SUCCESS!" << NORMAL << std::endl;
            else
                std::cout << RED << "Copy constructor test 0: ERROR" << NORMAL << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            //  Test 1
            if (first == CopyFirst)
                std::cout << GREEN << "Copy constructor test 1: SUCCESS!" << NORMAL << std::endl;
            else
                std::cout << RED << "Copy constructor test 1: ERROR" << NORMAL << std::endl;

            //  Copy assignable test
            std::cout << UNDERLINE << "\nCopy assignable test\n" << NORMAL << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

            ft::vector<float>::iterator assignCopyFirst = ++CopyFirst;
            ft::vector<float>::iterator assignCopyLast = --CopyLast;

            std::cout << "second == " << *(CopyFirst) << " == " << *assignCopyFirst << std::endl;
            std::cout << "before last == " << *(CopyLast) << " == " << *assignCopyLast << std::endl << std::endl;

            //  Test 0
            if (assignCopyFirst == CopyFirst)
                std::cout << GREEN << "Copy assignation test 0: SUCCESS!" << NORMAL << std::endl;
            else
                std::cout << RED << "Copy assignation test 0: ERROR" << NORMAL << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            //  Test 1
            if (assignCopyLast == CopyLast)
                std::cout << GREEN << "Copy assignation test 1: SUCCESS!" << NORMAL << std::endl;
            else
                std::cout << RED << "Copy assignation test 1: ERROR" << NORMAL << std::endl;

            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
        }

        // ===============  Operator Overload tests ===============//
        {
            std::cout << RED << UNDERLINE << "\nOPERATOR OVERLOAD TEST'S" << NORMAL << std::endl;

            //  Equality test
            {
                std::cout << UNDERLINE << "\nOperator overload equality test's\n" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));
        
                //  Test 0
                if (first == last)
                    std::cout << RED << "Equality test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Equality test 0: SUCCESS!" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                ft::vector<float>::iterator fCopy = first;
                if (first == fCopy)
                    std::cout << GREEN << "Equality test 1: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Equality test 1: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                ft::vector<float>::iterator lCopy = last;
                if (last == lCopy)
                    std::cout << GREEN << "Equality test 2: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Equality test 2: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3
                std::string str = "test";
                ft::vector<std::string> strVec(5, str);
                
                ft::vector<std::string>::iterator   it0 = strVec.begin();
                ft::vector<std::string>::iterator   it1 = strVec.begin();
                it1++;

                if (it0 == it1)
                    std::cout << RED << "Equality test 3: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Equality test 3: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
            }
        
            //  Inequality test
            {
                std::cout << UNDERLINE << "\nOperator overload inequality test's\n" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Test 0
                if (first != last)
                    std::cout << GREEN << "Inequality test 0: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Inequality test 0: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                std::string str = "test";
                ft::vector<std::string> strVec(5, str);
                
                ft::vector<std::string>::iterator   it0 = strVec.begin();
                ft::vector<std::string>::iterator   it1 = strVec.begin();

                it1++;
                if (it0 != it1)
                    std::cout << GREEN << "Inequality test 1: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Inequality test 1: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                it0++;
                if (it0 != it1)
                    std::cout << RED << "Inequality test 2: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Inequality test 2: SUCCESS!" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3
                it1--;
                if (it1 != it0)
                    std::cout << GREEN << "Inequality test 3: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Inequality test 3: ERROR" << NORMAL << std::endl;

                //  Test 4
                it0--;
                if (it1 != it0)
                    std::cout << RED << "Inequality test 4: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Inequality test 4: SUCCESS!" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
            }
        
            //  Deference test
             
        }
        
    }
    
	return (0);
}
