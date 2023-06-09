/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhendzel <dhendzel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:10:55 by dhendzel          #+#    #+#             */
/*   Updated: 2023/06/24 16:58:54 by dhendzel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	sedding(std::string stringToRep, std::string stringToKeep, std::string *fileContent)
{
	size_t	i = 0;
	size_t	stringLength = stringToKeep.length();
	i = (*fileContent).find(stringToRep, i);
	while((i = (*fileContent).find(stringToRep, i)) != std::string::npos)
	{
		(*fileContent).erase(i, stringToRep.length());
		(*fileContent).insert(i, stringToKeep);
		i += stringLength;
	}
}

void	errorMessage(std::string message)
{
	std::cout << message << std::endl <<"usage ./<programName> <fileName> <stringToRep> <stringToKeep>" << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (errorMessage("wrong number of arguements"), 1);
	std::ifstream	infile(argv[1]);
	std::string		stringToRep = argv[2];
	std::string		stringToKeep = argv[3];
	if (!stringToRep.length() || !stringToKeep.length())
		return (errorMessage("wrong arguements"), 1);
	if (!infile.good())
		return (errorMessage("can't open file"), 1);
	std::ofstream	outfile(std::string(argv[1]) + ".replace");
	std::string		fileContent;
	char			c;
	while(infile.get(c))
		fileContent.push_back(c);
	sedding(stringToRep, stringToKeep, &fileContent);
	outfile << fileContent;
	infile.close();
	outfile.close();
	return (0);
}