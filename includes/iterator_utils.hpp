/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguay <aguay@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:16:26 by aguay             #+#    #+#             */
/*   Updated: 2022/11/23 14:19:43 by aguay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <typename T> struct remove_const {typedef T type;};
    template <typename T> struct remove_const<const T> {typedef T type;};
    template <typename T> struct remove_volatile {typedef T type;};
    template <typename T> struct remove_volatile<volatile T> {typedef T type;};
    template <typename T> struct remove_cv {typedef typename remove_volatile<typename remove_const<T>::type>::type type;};
}
