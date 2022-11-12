/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:27:34 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 20:46:48 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void)
{
	std::srand (std::time (0));
	int random_int = std::rand() % 3;
	if (random_int == 2) 
	{
		std::cout << "Generate A object" << std::endl;
		return (new A());
	} 
	else if (random_int == 1) 
	{
		std::cout << "Generate B object" << std::endl;
		return (new B());
	} 
	else if (random_int == 0) 
	{
		std::cout << "Generate C object" << std::endl;
		return (new C());
	} 
	else
		return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "* Base has A type" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Base has B type" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Base has C type" << std::endl;
	else
		std::cout << "Base has unknown type" << std::endl;
}

//bad_cast is only thrown when casting references
//NULL is returned when casting pointers
void identify(Base &p)
{
	try 
	{
		A & a =  dynamic_cast<A &>(p);
		std::cout << "& Base has A type" << std::endl;
		(void)a;
	} 
	catch (std::bad_cast) 
	{
		// std::cout << "bad_cast of A!" << std::endl;
	}

	try 
	{
		B & b = dynamic_cast<B &>(p);
		std::cout << "& Base has B type" << std::endl;
		(void)b;
	}
	catch (std::bad_cast) 
	{
		// std::cout << "bad_cast of B!" << std::endl;
	}
	try 
	{
		C & c = dynamic_cast<C &>(p);
		std::cout << "& Base has C type" << std::endl;
		(void)c;
	} 
	catch (std::bad_cast) 
	{
		// std::cout << "bad_cast of C!" << std::endl;
	}
	std::cout << "Base has unknown type" << std::endl;
}

int	main(void)
{
	// Base *base = generate();
	// if (base == NULL)
	// 	return (-1);
	// identify(base);
	// identify(*base);
	// delete base;

	Base	*base;

	std::cout << "Identifying with pointers" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl << "Identifying with references" << std::endl
		<< std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;
	return (0);
}
