/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:22:00 by aguay             #+#    #+#             */
/*   Updated: 2022/11/23 14:25:42 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <typename It>
    struct iterator_traits
    {
        typedef typename It::iterator_category iterator_category;
        typedef typename It::value_type        value_type;
        typedef typename It::difference_type   difference_type;
        typedef typename It::pointer           pointer;
        typedef typename It::reference         reference;
    };

    template <typename It>
    struct iterator_traits<It*>
    {
        typedef ft::random_access_iterator_tag  iterator_category;
        typedef typename remove_cv<It>::type    value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef It*                             pointer;
        typedef It&                             reference;
    };
};
