/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:20:00 by aguay             #+#    #+#             */
/*   Updated: 2022/11/23 14:46:13 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include "include.hpp"

//  Timing
#define MsBetweenTestType 500
#define MsBetweenTest 200

//  =============== Iterator-traits Test's          =============== //
#define IteratorTraitsTests             true


//  =============== Vector Iterator Test's          =============== //
#define VectorIteratorTests             true


//  ==============  Vector test's                   =============== //
#define VectorTests                     true

//  Capacity test's
#define VectorCapacityTests             true

#define VectorSize                      true
#define VectorMaxSize                   true
#define VectorResize                    true
#define VectorCapacity                  true


//  Modifiers test's
#define VectorModifierTests             true

#define VectorAssign                    true
#define VectorPushBack                  true
#define VectorPopBack                   true
#define VectorInsert                    true
#define VectorErase                     false
#define VectorSwap                      false
#define VectorClear                     false



int	main(void)
{
    //  ===============  Iterator traits test's     =============== //
    if (IteratorTraitsTests)
    {
        std::cout << TEAL << UNDERLINE << "\nTest's for iterator traits\n" << NORMAL << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

        typedef ft::iterator_traits<int*> ft_traits;
        typedef std::iterator_traits<int*> std_traits;

        //  Test 0

        if (typeid(ft_traits::iterator_category)==typeid(ft::random_access_iterator_tag))
            std::cout << GREEN << "Ierator traits test 0: SUCCESS!" << NORMAL << std::endl;
        else
            std::cout << RED << "Ierator traits test 0: ERROR" << NORMAL << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

        //  Test 1
        if (typeid(ft_traits::difference_type)==typeid(std_traits::difference_type))
            std::cout << GREEN << "Ierator traits test 1: SUCCESS!" << NORMAL << std::endl;
        else
            std::cout << RED << "Ierator traits test 1: ERROR" << NORMAL << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

        //  Test 2
        if (typeid(ft_traits::pointer)==typeid(std_traits::pointer))
            std::cout << GREEN << "Ierator traits test 2: SUCCESS!" << NORMAL << std::endl;
        else
            std::cout << RED << "Ierator traits test 2: ERROR" << NORMAL << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

        //  Test 3
        if (typeid(ft_traits::value_type)==typeid(std_traits::value_type))
            std::cout << GREEN << "Ierator traits test 3: SUCCESS!" << NORMAL << std::endl;
        else
            std::cout << RED << "Ierator traits test 3: ERROR" << NORMAL << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

        //  Test 4
        if (typeid(ft_traits::reference)==typeid(std_traits::reference))
            std::cout << GREEN << "Ierator traits test 4: SUCCESS!" << NORMAL << std::endl;
        else
            std::cout << RED << "Ierator traits test 5: ERROR" << NORMAL << std::endl;
    }
	
    //  =============== Vector test's               =============== //
    if (VectorTests)
    {
        std::cout << TEAL << UNDERLINE << "\nTest's for vector container\n" << NORMAL << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

        if (VectorCapacityTests)
        {
            std::cout << RED << UNDERLINE << "\nCAPACITY TEST'S\n" << NORMAL << std::endl;
    
            std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

            //  Vector size test
            if (VectorSize)
            {
                std::cout << UNDERLINE << "\nVector capacity max_size test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's
                std::vector<int>    rV;
                ft::vector<int>     fV;

                rV.push_back(1);
                rV.push_back(2);
                rV.push_back(3);

                fV.push_back(1);
                fV.push_back(2);
                fV.push_back(3);

                //  Test 0
                if (rV.size() != fV.size())
                    std::cout << RED << "Vector size test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                fV.push_back(4);
                rV.push_back(4);
                if (rV.size() != fV.size())
                    std::cout << RED << "Vector size test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                fV.push_back(5);
                fV.push_back(6);
                fV.push_back(7);
                rV.push_back(5);
                rV.push_back(6);
                rV.push_back(7);

                if (rV.size() != fV.size())
                    std::cout << RED << "Vector size test 2: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 2: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3
                fV.push_back(8);
                fV.push_back(9);
                fV.push_back(-10);
                rV.push_back(8);
                rV.push_back(9);
                rV.push_back(-10);

                if (rV.size() != fV.size())
                    std::cout << RED << "Vector size test 3: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 3: SUCCESS!" << NORMAL << std::endl;
            }

            //  Vector max size test
            if (VectorMaxSize)
            {
                std::cout << UNDERLINE << "\nVector capacity max_size test's\n" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup vector for test's
                std::vector<int>            iRV;
                ft::vector<int>             iV;

                std::vector<float>          fRV;
                ft::vector<float>           fV;

                std::vector<double>         dRV;
                ft::vector<double>          dV;

                std::vector<char>           cRV;
                ft::vector<char>            cV;

                std::vector<std::string>    sRV;
                ft::vector<std::string>     sV;

                //  Test 0
                if (iRV.max_size() != iV.max_size())
                    std::cout << RED << "Vector max_size test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector max_size test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
                    
                //  Test 1
                if (fRV.max_size() != fV.max_size())
                    std::cout << RED << "Vector max_size test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector max_size test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                if (dRV.max_size() != dV.max_size())
                    std::cout << RED << "Vector max_size test 2: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector max_size test 2: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3
                if (cRV.max_size() != cV.max_size())
                    std::cout << RED << "Vector max_size test 3: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector max_size test 3: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 4
                if (sRV.max_size() != sV.max_size())
                    std::cout << RED << "Vector max_size test 4: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector max_size test 4: SUCCESS!" << NORMAL << std::endl; 
            }
        
            //  Vector resize test
            if (VectorResize)
            {
                std::cout << UNDERLINE << "\nVector capacity max_size test's\n" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup vector for test's
                int         i = 42;
                double      d = 42;
                float       f = 42;
                std::string s = "42";

                ft::vector<int> iVec(5, i);
                ft::vector<double> dVec(5, d);
                ft::vector<float> fVec(5, f);
                ft::vector<std::string> sVec(5, s);

                //  Test 0
                iVec.resize(9);
                dVec.resize(9);
                fVec.resize(9);
                // sVec.resize(9); Here we cant assign 0 as str value
                
                if (iVec.size() != 9 || dVec.size() != 9 || fVec.size() != 9 || sVec.size() != 9)
                    std::cout << RED << "Vector resize test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector resize test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1    
            }

            //  Vector capacity test
            if (VectorCapacity)
            {   
                std::cout << UNDERLINE << "\nVector capacity capacity test's\n" << NORMAL << std::endl;
                
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                // test 0
                ft::vector<char>    vec;

                if (vec.size() > vec.capacity())
                    std::cout << RED << "Vector capacity test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector capacity test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  test 1
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                
                if (vec.size() > vec.capacity())
                    std::cout << RED << "Vector capacity test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector capacity test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  test 2
                vec.push_back('a');
                vec.push_back('a');
                if (vec.size() > vec.capacity())
                    std::cout << RED << "Vector capacity test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector capacity test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  test 3
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                vec.push_back('a');
                if (vec.size() > vec.capacity())
                    std::cout << RED << "Vector capacity test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector capacity test 0: SUCCESS!" << NORMAL << std::endl;
            }
        }
    
        if (VectorModifierTests)
        {
            //  Vector assign test
            if (VectorAssign)
            {
                std::cout << UNDERLINE << "\nVector Modifier assign test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's
                int i = 42;
                
                ft::vector<int> iVec(6, i);
                
                iVec.assign(50, 42);

                //  Test 0
                bool    engine = true;
                ft::vector<int>::iterator   it = iVec.begin();
                ft::vector<int>::iterator   end = iVec.end();

                while (engine && it != end)
                {
                    if (*it != 42)
                        engine = false;
                    it++;
                }

                if (engine)
                    std::cout << GREEN << "Vector assign test 0: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Vector assign test 0: ERROR" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                ft::vector<std::string> sVec;

                sVec.assign(42, "yo");
                if (sVec.size() == 42)
                    std::cout << GREEN << "Vector assign test 1: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Vector assign test 1: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2

                ft::vector<int> i2Vec;

                i = 69;
                
                iVec.push_back(i);

                i2Vec.assign(iVec.begin(), iVec.end());

                if (i2Vec.size() == iVec.size())
                    std::cout << GREEN << "Vector assign test 2: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Vector assign test 2: ERROR" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3

                engine = true;

                it = i2Vec.begin();
                end = i2Vec.end();

                int w = 0;
                while (engine && it != end)
                {
                    if (iVec[w] != i2Vec[w])
                        engine = false;
                    it++;
                    w++;
                }

                if (engine)
                    std::cout << GREEN << "Vector assign test 3: SUCCESS!" << NORMAL << std::endl;
                else
                    std::cout << RED << "Vector assign test 3: ERROR" << NORMAL << std::endl;

                //  Test 4
            }

            //  Vector push back test
            if (VectorPushBack)
            {
                std::cout << UNDERLINE << "\nVector modifier push back test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's
                ft::vector<int>     ftVec;
                std::vector<int>    stdVec;

                ftVec.push_back(0);
                stdVec.push_back(0);

                ft::vector<int>::iterator   ftIt = ftVec.begin();
                std::vector<int>::iterator  stdIt = stdVec.begin();

                //  Test 0
                if (ftVec.size() != stdVec.size() || *ftIt != *stdIt)
                    std::cout << RED << "Vector push_back test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector push_back test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                ftVec.push_back(-1);
                stdVec.push_back(1);
                ftIt++;
                stdIt++;

                if (ftVec.size() != stdVec.size() || *ftIt == *stdIt)
                    std::cout << RED << "Vector push_back test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector push_back test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                ftVec.push_back(2);
                ftVec.push_back(3);
                ftVec.push_back(4);
                ftVec.push_back(5);
                ftVec.push_back(6);
                ftVec.push_back(7);
                ftVec.push_back(8);

                stdVec.push_back(2);
                stdVec.push_back(3);
                stdVec.push_back(4);
                stdVec.push_back(5);
                stdVec.push_back(6);
                stdVec.push_back(7);
                stdVec.push_back(8);

                if (ftVec.size() != stdVec.size() || ftVec[9] != stdVec[9])
                    std::cout << RED << "Vector push_back test 2: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector push_back test 2: SUCCESS!" << NORMAL << std::endl;
            }

            //  Vector pop back test
            if (VectorPopBack)
            {
                std::cout << UNDERLINE << "\nVector modifier pop back test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));
                
                //  Setup some variable for test's
                float plop = 42;
                
                std::vector<float>  stdVec(12, plop);
                ft::vector<float>   ftVec(12, plop);
                
                //  Test 0
                if (stdVec.size() != ftVec.size())
                    std::cout << RED << "Vector pop_back test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                stdVec.assign(5, -12.534);
                ftVec.assign(5, -12.534);

                stdVec.pop_back();
                ftVec.pop_back();

                if (stdVec.size() != ftVec.size())
                    std::cout << RED << "Vector pop_back test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2

                if (stdVec[4] != ftVec[4])
                    std::cout << RED << "Vector pop_back test 2: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 2: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 3
                stdVec.pop_back();
                stdVec.pop_back();
                stdVec.pop_back();

                ftVec.pop_back();
                ftVec.pop_back();
                ftVec.pop_back();

                if (stdVec.size() != ftVec.size())
                    std::cout << RED << "Vector pop_back test 3: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 3: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 4

                if (stdVec[0] != ftVec[0])
                    std::cout << RED << "Vector pop_back test 4: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 4: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 5

                ftVec.pop_back();
                stdVec.pop_back();

                if (ftVec.size() != stdVec.size())
                    std::cout << RED << "Vector pop_back test 5: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector pop_back test 5: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
            
            }

            //  Vector insert test
            if (VectorInsert)
            {
                std::cout << UNDERLINE << "\nVector modifier insert test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's
                std::vector<int>            stdIVec;
                std::vector<std::string>    stdSVec;

                ft::vector<int>             ftIVec;
                ft::vector<std::string>     ftSVec;

                stdIVec.push_back(1);
                stdIVec.push_back(10);
                stdIVec.push_back(11);
                stdIVec.push_back(12);

                ftIVec.push_back(1);
                ftIVec.push_back(10);
                ftIVec.push_back(11);
                ftIVec.push_back(12);
                
                stdSVec.push_back("1");
                stdSVec.push_back("10");
                stdSVec.push_back("11");
                stdSVec.push_back("12");

                ftSVec.push_back("1");
                ftSVec.push_back("10");
                ftSVec.push_back("11");
                ftSVec.push_back("12");

                std::vector<int>::iterator stdIIt = stdIVec.begin();
                std::vector<std::string>::iterator stdSIt = stdSVec.begin();

                ft::vector<int>::iterator ftIIt = ftIVec.begin();
                ft::vector<std::string>::iterator ftSIt = ftSVec.begin();

                stdIIt++;
                stdSIt++;
                ftIIt++;
                ftSIt++;

                ftIVec.insert(ftIIt, 2);
                stdIVec.insert(stdIIt, 2);
                
                //  Test 0
                if (ftIVec[1] != stdIVec[1])
                    std::cout << RED << "Vector insert test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector insert test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 1
                if (ftIVec[2] != stdIVec[2])
                    std::cout << RED << "Vector insert test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector insert test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

                //  Test 2
                if (ftIVec[3] != stdIVec[3])
                    std::cout << RED << "Vector insert test 1: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector insert test 1: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            }

            //  Vector erase test
            if (VectorErase)
            {
                std::cout << UNDERLINE << "\nVector modifier erase test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's

                //  Test 0
                if (true)
                    std::cout << RED << "Vector size test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            }

            //  Vector swap test
            if (VectorSwap)
            {
                std::cout << UNDERLINE << "\nVector modifier swap test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's

                //  Test 0
                if (true)
                    std::cout << RED << "Vector size test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));

            }

            //  Vector Clear test
            if (VectorClear)
            {
                std::cout << UNDERLINE << "\nVector modifier clear test's\n" << NORMAL << std::endl;
                    
                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTestType));

                //  Setup some variable for test's

                //  Test 0
                if (true)
                    std::cout << RED << "Vector size test 0: ERROR" << NORMAL << std::endl;
                else
                    std::cout << GREEN << "Vector size test 0: SUCCESS!" << NORMAL << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(MsBetweenTest));
                

            }
        }
    }
    return (0);
}
