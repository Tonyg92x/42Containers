/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:20:00 by aguay             #+#    #+#             */
/*   Updated: 2022/11/09 11:23:05 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "vector.hpp"
#include <map>
#include <vector>

int	main(void)
{
    int i = 42;

    ft::vector<int> vec(5, static_cast<int &>(i));
    for (ft::iterator<int> ite = vec.begin(); ite != vec.end(); ite++)
        std::cout << *ite << std::endl;
	return (0);
}
