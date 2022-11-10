/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:20:00 by aguay             #+#    #+#             */
/*   Updated: 2022/11/10 11:47:29 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "include.hpp"

int	main(void)
{
    std::cout << std::endl << UNDERLINE << GREEN << "My iterator test's :" << NORMAL << std::endl;
    {
        std::cout << YELLOW << "begin and end iterator test's : \n" << NORMAL << std::endl;
        {
            ft::vector<int> vec1;

            vec1.push_back(0);
            vec1.push_back(1);
            vec1.push_back(2);
            for (ft::vector<int>::iterator ite = vec1.begin(); ite != vec1.end(); ite++)
                std::cout << *ite << std::endl;
        }

        std::cout << YELLOW << "\nrbegin and rend iterator test's : \n" << NORMAL << std::endl;
        {
            ft::vector<int> vec;
            
            vec.push_back(0);
            vec.push_back(1);
            vec.push_back(2);

            for (ft::reverse_iterator<int> ite = vec.rbegin(); ite != vec.rend(); ite++)
                std::cout << *ite << std::endl;
        }
        
        std::cout << YELLOW << "\ncbegin and cend iterator test's : \n" << NORMAL << std::endl;
        {
            {
                ft::vector<int> vec;
                
                vec.push_back(0);
                vec.push_back(1);
                vec.push_back(2);

                for (ft::vector<int>::const_iterator ite = vec.cbegin(); ite != vec.cend(); ite++)
                    std::cout << *ite << std::endl;
            }
        }

        std::cout << YELLOW << "\ncrbegin and crend iterator test's : \n" << NORMAL << std::endl;
        {
            {
                ft::vector<int> vec;
                
                vec.push_back(0);
                vec.push_back(1);
                vec.push_back(2);

                for (ft::vector<int>::const_reverse_iterator ite = vec.crbegin(); ite != vec.crend(); ite++)
                    std::cout << *ite << std::endl;
            }
        }
    }
	return (0);
}
