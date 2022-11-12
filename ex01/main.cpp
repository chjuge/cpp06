/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:17:47 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 20:25:11 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

uintptr_t	serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main( void )
{
	Data *ptr = new Data;
	Data *new_ptr;
	uintptr_t raw;

	ptr->data = "Fish, meat and kozli na sostavleniyah etogo basika";
	ptr->data_int = 777;
	raw = serialize(ptr);
	new_ptr = deserialize(raw);
	std::cout << "new_ptr->data = " << new_ptr->data << std::endl;
	std::cout << "and more:		" << new_ptr->data_int << std::endl;
	delete ptr;
}