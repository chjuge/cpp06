/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:46:26 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 20:05:26 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	Conversion conv = Conversion(argv[1]);
	if (conv.getType() != ERROR)
		conv.printConversionResult();
	return (0);
}