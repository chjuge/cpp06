/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:05:01 by mproveme          #+#    #+#             */
/*   Updated: 2022/10/30 19:24:45 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

string sp_f[] = {"-inff", "+inff", "inff", "nanf"};
string sp_d[] = {"-inf", "+inf", "inf", "nan"};

void	wrong_literal()
{
	cout << "You inputed wrong literal" << endl;
}

void	check_float(string str)
{
	cout << str.back() << endl;
}
void	check_int()
{
	
}

void do_int(int num)
{
	cout << "it's int!\n";
	isprint(num)
	? cout << "char:	" << static_cast<char>(num) << endl
	: cout << "char:	" << "Non displayable" << endl;
	cout << "int:	" << num << endl;
	cout << "float:	" << static_cast<float>(num) << ".0f" << endl;
	cout << "double:	" << static_cast<double>(num) << ".0" << endl;
}

void do_char(char c)
{
	cout << "char:	" << c << endl;
	cout << "int:	" << static_cast<int>(c) << endl;
	cout << "float:	" << static_cast<float>(c) << ".0f" << endl;
	cout << "double:	" << static_cast<double>(c) << ".0" << endl;
}

string	str_tolower(string str)
{
	string	str_new = "";
	for (size_t i = 0; i < str.length(); i++)
		str_new += static_cast<char>(tolower(static_cast<int>(str[i])));
	return (str_new);	
}

void	check_char_literal(string lit)
{
	isprint(lit[0]) 
	? isnumber(lit[0])
	? do_int(std::stoi(lit))
	: do_char(lit[0])
	: wrong_literal();
}

bool	check_permitted(string str)
{
	size_t	flag;
	if ((flag = str.find_first_not_of("0123456789-+ .ainf")) != std::string::npos)
		cout << "Input contains forbidden characters" << endl;
	return flag == std::string::npos;
}

void	detect_the_type(string str)
{
	if (str.length() == 1)
	{
		check_char_literal(str);
		return;
	}
	if (!check_permitted(str))
		return ;
	int dots = 0;
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '.')
			dots++;
	dots == 0
	? check_int()
	: dots == 1
	? check_float(str)
	: wrong_literal();
}


int main(int argc, char ** argv)
{
	if (argc != 2)
	{
		cout << "Wrong number of params" << endl;
		return (1);
	}
	string str = str_tolower(argv[1]);
	detect_the_type(str);
	return (0);
}