/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mproveme <mproveme@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:46:23 by mproveme          #+#    #+#             */
/*   Updated: 2022/11/06 20:11:38 by mproveme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <climits>

# define CHAR 5
# define INT 6
# define FLOAT 7
# define DOUBLE 8
# define INF_NAN 9
# define ERROR 1

# define NAN "nan"
# define NANF "nanf"
# define INF1 "inf"
# define INF2 "+inf"
# define INF3 "-inf"
# define INFF1 "inff"
# define INFF2 "+inff"
# define INFF3 "-inff"

class Conversion {
private:
	std::string	input;
	int			type;
	char		ch;
	int 		num;
	float		fl;
	double		dbl;

	void		fromChar();
	void		fromInt();
	void		fromFloat();
	void		fromDouble();

	void		printChar() const;
	void		printInt() const;
	void		printFloat() const;
	void		printDouble() const;

	void		conversion();
	int			determineInputType();
	
public:
	Conversion();
	Conversion(std::string input_str);
	Conversion(const Conversion &src);
	Conversion &operator=(const Conversion &src);
	~Conversion();

	int		getType() const;

	void	printConversionResult() const;
};

#endif
