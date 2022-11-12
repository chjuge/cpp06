/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:46:19 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 20:14:52 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion() {
	// std::cout << "Default constructor" << std::endl;
}

Conversion::Conversion(std::string input_str) {
	// std::cout << "Constructor" << std::endl;
	this->input = input_str;
	this->dbl = std::atof(this->input.c_str());
	this->conversion();
}

Conversion::Conversion(const Conversion &src) {
	// std::cout << "Copy constructor" << std::endl;
	*this = src;
}

Conversion &Conversion::operator=(const Conversion &src) {
	// std::cout << "Assignment" << std::endl;

	if (this != &src)
	{
		this->input = src.input;
		this->ch = src.ch;
		this->num = src.num;
		this->fl = src.fl;
		this->dbl = src.dbl;
	}
	return *this;
}

Conversion::~Conversion() {
	// std::cout << "Destructor" << std::endl;
}

int		Conversion::getType() const {
	return this->type;
}

void	Conversion::fromChar() {
	this->ch = static_cast<char>(this->input[0]);
	this->num = static_cast<int>(this->ch);
	this->fl = static_cast<float>(this->ch);
	this->dbl = static_cast<double>(this->ch);
}

void	Conversion::fromInt() {
	this->num = static_cast<int>(this->dbl);
	this->ch = static_cast<unsigned char>(this->num);
	this->fl = static_cast<float>(this->dbl);
}

void	Conversion::fromFloat() {
	this->fl = static_cast<float>(this->dbl);
	this->ch = static_cast<char>(this->fl);
	this->num = static_cast<int>(this->fl);
}

void	Conversion::fromDouble() {
	this->ch = static_cast<char>(this->dbl);
	this->num = static_cast<int>(this->dbl);
	this->fl = static_cast<float>(this->dbl);
}

void	Conversion::conversion() {
	void (Conversion:: * fPntr[])(void) ={	& Conversion::fromChar, 
											& Conversion::fromInt, 
											& Conversion::fromFloat, 
											& Conversion::fromDouble};
	int types[4] = {CHAR, INT, FLOAT, DOUBLE};

	this->type = determineInputType();

	if (this->type == INF_NAN)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->type == types[i]) {
			(this->*fPntr[i])();
			return ;
		}
	}
	std::cout << "Wrong input" << std::endl;
}

int	Conversion::determineInputType() {
	if (this->input == NAN
		|| this->input == NANF
		|| this->input == INF1
		|| this->input == INF2
		|| this->input == INF3
		|| this->input == INFF1
		|| this->input == INFF2
		|| this->input == INFF3) 
		return (INF_NAN); 
	if (this->input.length() == 1 
		&& (this->input[0] == '+' 
		|| this->input[0] == '-' 
		|| this->input[0] == 'f' 
		|| this->input[0] == '.'))
		return (CHAR);
	if (this->input.find_first_of("+-") != this->input.find_last_of("+-")
			 || ((this->input.find_first_of("+-") != std::string::npos)
			 && (this->input.find_first_of("+-") != 0))
			 )
		return (ERROR);
	if (this->input.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	if (this->input.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (this->input.find_first_of(".") != this->input.find_last_of(".")
			|| isdigit(this->input[this->input.find_first_of(".") + 1]) == false 
			|| this->input.find_first_of(".") == 0) 
			return (ERROR);
		else
			return (DOUBLE);
	}
	if (this->input.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->input.find_first_of(".") != this->input.find_last_of(".")
			|| this->input.find_first_of("f") - this->input.find_first_of(".") == 1 
			|| this->input.find_first_of(".") == 0 
			|| this->input[this->input.find_first_of("f") + 1] != '\0'
			)
			return (ERROR);
		else
			return (FLOAT);
	}
	if ((this->input.length() == 1 && std::isprint(this->input[0])) ||
		(this->input.length() == 1 && std::isalpha(this->input[0])))
	{
		return (CHAR);
	}
	else
		return (ERROR);
}

void	Conversion::printChar() const {
	if (this->type != INF_NAN && this->dbl <= UCHAR_MAX && this->dbl >= 0)
	{
		if (isprint(this->ch))
			std::cout << "char: '" << this->ch << "'" << std::endl;
		else
			std::cout << "char: Non printable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void	Conversion::printInt() const {
	if (this->type != INF_NAN 
		&& this->dbl >= std::numeric_limits<int>::min() 
		&& this->dbl <= std::numeric_limits<int>::max()
		)
		std::cout << "int: " << this->num << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void	Conversion::printFloat() const {
	if (this->type != INF_NAN)
	{
		std::cout << "float: " << this->fl;
		if (this->fl - this->num == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else
	{
		if (this->input == NAN || this->input == NANF)
			std::cout << "float: nanf" << std::endl;
		else if (this->input[0] == '+' || this->input[0] == 'i')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
}

void	Conversion::printDouble() const {
	if (this->type != INF_NAN)
	{
		std::cout << "double: " << this->dbl;
		if (this->dbl < std::numeric_limits<int>::min() 
			|| this->dbl > std::numeric_limits<int>::max() 
			|| this->dbl - this->num == 0
			) 
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		if (this->input == NAN || this->input == NANF)
			std::cout << "double: nan" << std::endl;
		else if (this->input[0] == '+' || this->input[0] == 'i')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

void	Conversion::printConversionResult() const{
	this->printChar();
	this->printInt();
	this->printFloat();
	this->printDouble();
}